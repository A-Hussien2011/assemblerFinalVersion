#include <iostream>
#include <include/InstructionLine.h>
#include <include/OperationTable.h>
#include <include/Controller.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <include/OperandValidator.h>

#include <include/OpValidator.h>

using namespace std;

void toUpper(string *symbolName) {
    transform(symbolName->begin(), symbolName->end(), symbolName->begin(), ::toupper);
}

int main() {

    InstructionLine instructionLine = InstructionLine(
            "  DONE END  ");
    //InstructionLine instructionLine = InstructionLine("           LABEL      LDA       X   ,X             .sadsa             ");
    //InstructionLine instructionLine = InstructionLine("                 LDA       X,X             .sadsa             ");
    //InstructionLine instructionLine = InstructionLine("           LABEL      LDA                               ");
    //InstructionLine instructionLine = InstructionLine("                 LDA                    .sadsa             ");

    cout << "Line: " << instructionLine.getLine() << endl;
    cout << "Type: " << instructionLine.getType() << endl;
    cout << "Error: " << instructionLine.getError() << endl;
    cout << "Label: " << instructionLine.getLabel() << endl;
    cout << "Operation: " << instructionLine.getOperation() << endl;
    cout << "Operand: " << instructionLine.getOperand() << endl;
    cout << "Comment: " << instructionLine.getComment() << endl;


    Controller controller;
    controller.start();


    return 0;
}

