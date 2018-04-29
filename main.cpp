#include <iostream>
#include <InstructionLine.h>
#include <OperationTable.h>
#include <Controller.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <OperandValidator.h>

#include <OpValidator.h>
using namespace std;

void toUpper(string* symbolName) {
        transform(symbolName->begin(), symbolName->end(), symbolName->begin(), ::toupper);
}

int main() {

    InstructionLine instructionLine = InstructionLine(
            "  loop      +sta   3  ");
    //InstructionLine instructionLine = InstructionLine("           LABEL      LDA       X   ,X             .sadsa             ");
    //InstructionLine instructionLine = InstructionLine("                 LDA       X,X             .sadsa             ");
    //InstructionLine instructionLine = InstructionLine("           LABEL      LDA                               ");
    //InstructionLine instructionLine = InstructionLine("                 LDA                    .sadsa             ");

    /*cout << instructionLine.getLine() << endl;
    cout << instructionLine.getType() << endl;
    cout << instructionLine.getError() << endl;
    cout << instructionLine.getLabel() << endl;
    cout << instructionLine.getOperation() << endl;
    cout << instructionLine.getOperand() << endl;
    cout << instructionLine.getComment() << endl;*/


    Controller controller;
    controller.start();




    return 0;
}

