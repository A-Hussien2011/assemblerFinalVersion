#include <iostream>
#include <InstructionLine.h>
#include <OperationTable.h>
#include <Controller.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <OperandValidator.h>
using namespace std;



int main() {

    InstructionLine instructionLine = InstructionLine(
            "                 lda   3  ");
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
   //controller.start();
   //OperandValidator op = OperandValidator();
   OperationTable x;
   x.getInstance();
   cout << x.getFormat("+LDA");




    return 0;
}
