#include "Pass2Controller.h"
#include <vector>
#include <string.h>
#include "OperandIdentifiers.h"
#include "DisplacementController.h"
#include "Format.h"
#include "Controller.h"
#include "IntermediateLine.h"
#include "inOutFile.h"
#include "Converters.h"
#include <OperandValidator.h>


Pass2Controller::Pass2Controller() {
    controller = Controller();
    format = Format();
    converter = Converters();
}

void Pass2Controller::generateIntermediateFile(string fileName) {
    controller.start(fileName);
}

void Pass2Controller::generateObjectCode() {
    int fileIterator = 2;
    file = inOutFile();
    string address;
    std::vector<std::string> input = file.readFile("pass1.txt");
    currentLine(input[fileIterator]);
    nextLine(input[fileIterator]);
    string start = currentLine.getAddress();
    string base = currentLine.getAddress();
    string progName = currentLine.getLabel();
    operandIdentifiers = OperandIdentifiers(controller.getSymbolTable(), controller.getLiteralTable());
    displacementController = DisplacementController(operandIdentifiers);
    int opType = OpValidator.getOperandType(currentLine.getOperand());
    operandIdentifiers.setOperand(currentLine.getOperand());
    while(fileIterator !=  input.size()) {
        string operand = currentLine.getOperand();
        if (currentLine.getOperation() == "BYTE") {
            objectCodeArr.push_back(getByteObjectCode(operand));
        } else if (currentLine.getOperation() == "WORD") {
            objectCodeArr.push_back(getWordObjectCode(operand));
        } else if (currentLine.getLabel() == "*") {
            objectCodeArr.push_back(getLiteralObjectCode(operand));
        }
        else if ((opType == TYPE_IMMEDITAE_SYMBOL || opType == TYPE_INDIRECT_SYMBOL ||
                 opType == TYPE_INDEXED_SYMBOL || opType == TYPE_SIMPLE_EXPRESSION ||
                 opType == TYPE_COMPLEX_EXPRESSION) && controller.getSymbolTable().getSymbolType(operand) == 'U') {
                      	setSymbolType(operand);
                if (controller.getSymbolTable().getSymbolType(operand) == 'U') {
                        //error in line msh 3arfa hyt3ml ezay hna
                }
        } else {
            if (currentLine.getOperation() == "NOBASE") {
                displacementController.validBase(false);
            } else if (currentLine.getOperation() == "BASE") {
                base = currentLine.getAddress();
            }
            address = operandIdentifiers.getAddress();
            if (address == "") {
                if (!operandIdentifiers.isValidExpression()) {
                //then write error msg the expression is invalid
                } else {
                    //then symbol is not found in table error msg
                }
            } else {

            displacementController.setDispalcement(address, currentLine.getOperation(), currentLine.getOperand()
                                               , nextLine.getAddress(), base, currentLine.getFormat());
            format.setNflag(operandIdentifiers.getNflag());
            format.setIflag(operandIdentifiers.getIflag());
            format.setXflag(operandIdentifiers.getXflag());
            format.setBflag(displacementController.getBflag());
            format.setPflag(displacementController.getPCflag());
            format.setFormatType(currentLine.getFormat());
            format.setDispalcement(displacementController.getDispalcement());
            objectCodeArr.push_back(format.getObjectCode());
            }
        }
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

string Pass2Controller::getByteObjectCode(string operand) {
    string code;
     for (int i = 3; i < operand.length() - 1; i++) {
        code.append(controller.getLiteralTable().getAscii(operand.at(i)));
    }
    return code;
}

string Pass2Controller::getWordObjectCode(string operand) {
    string code;
    if (operand.at(0) == '-') {
        int word = strtol(operand.c_str(), NULL, 16);
        word *= -1;
        code = converter.convertToHexa(displacementController.addBinary(displacementController.convertToBin(word), "1"));
    } else {
        code = converter.convertToHexa(strtol(operand.c_str(), NULL, 16));
    }
    return code;
}

string Pass2Controller::getLiteralObjectCode(string literal) {
    return literalTable.getValue(literal);
}
