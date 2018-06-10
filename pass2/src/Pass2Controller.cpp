#include "Pass2Controller.h"
#include <vector>
#include <string.h>
#include "OperandIdentifiers.h"
#include "DisplacementController.h"
#include "Format.h"
#include "Controller.h"
#include "include/IntermediateLine.h"
#include "inOutFile.h"
#include "Converters.h"

Pass2Controller::Pass2Controller()
{
    controller = Controller();
    displacementController = DisplacementController();
    format = Format();
    converter = Converters();
}

void Pass2Controller::generateIntermediateFile(string fileName) {
    controller.start(fileName);
}

void Pass2Controller::generateObjectCode() {
    int fileIterator = 2;
    file = inOutFile();
    std::vector<std::string> input = file.readFile("pass1.txt");
    currentLine = IntermediateLine(input[fileIterator]);
    nextLine = IntermediateLine(input[fileIterator]);
    string start = currentLine.getAddress();
    string base = currentLine.getAddress();
    string progName = currentLine.getLabel();
    operandIdentifiers = OperandIdentifiers(controller.getSymbolTable(), controller.getLiteralTable()):
    while(fileIterator !=  input.size()) {
        if (currentLine.getOperation() == "NOBASE") {
            displacementController.validBase(false);
        } else if (currentLine.getOperation() == "BASE") {
            base = currentLine.getAddress();
        }
        displacementController.setDispalcement(currentLine.getOperation(), currentLine.getOperand()
                                               , nextLine.getAddress(), base, currentLine.getFormat());
        format.setNflag(operandIdentifiers.getNflag());
        format.setIflag(operandIdentifiers.getIflag());
        format.setXflag(operandIdentifiers.getXflag());
        format.setBflag(displacementController.getBflag());
        format.setPflag(displacementController.getPCflag());
        format.setFormatType(currentLine.getFormat());
        format.setDispalcement(displacementController.getDispalcement());
        objectCodeArr.push_back(format.getObjectCode());
        fileIterator++;
        currentLine = nextLine;
        nextLine = IntermediateLine(input[fileIterator]);
    }
}

void Pass2Controller::generateFinalFile(){
    file.writeHeaderFile (objectCodeArr, start, getLength(), progName);
}

string Pass2Controller::getLength()  {
    int counter = 0;
    for (int i = 0; i < objectCodeArr.size(); i++) {
        counter += objectCodeArr[i].length();
    }
    return converter.convertToHexa(counter/2);
}
