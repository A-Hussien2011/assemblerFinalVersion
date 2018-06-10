#include <Controller.h>
#include <iostream>
#include <inOutFile.h>
#include <InstructionLine.h>
#include <OperationTable.h>
#include <OperationTable.h>
#include <DirectiveTable.h>
#include <vector>
#include <OperandValidator.h>
#include <SymbolTable.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

#include "fstream"
using namespace std;

void Controller :: start(string fileName)
{

        litTab = LitTable();
        std::vector<std::string> errorMessageArr;
        std::vector<int> locctrArr;
        std::vector<std::string> operandVec;
        std::vector<std::string> operationVec;
        std::vector<std::string> labelVec;
        std::vector<std::string> commentVec;

        inOutFile file = inOutFile();
        std::vector<std::string> input = file.readFile(fileName);
        std::vector<std::string> intermediateFile;
        OperandValidator opValid = OperandValidator();
        DirectiveTable dirs;
        dirs.getInstance();
        OperationTable opTable;
        opTable.getInstance();
        int locctr = 0;


    /**/
    int startingAdrr = 0;
    string errorMessage;
    int fileIterator = 0;
    InstructionLine instruction = InstructionLine(input[fileIterator]);
    string label = instruction.getLabel();
    string operand = instruction.getOperand();
    string operation = instruction.getOperation();
    string line = instruction.getLine();
    string error = instruction.getError();
    string comment = instruction.getComment();
    int type = instruction.getType();
    int format = instruction.getInstructionFormatType();
    bool startFlag = false;
    toUpper(&operation);

    if (error == "") {
        errorMessage="";
    } else {
        errorFound = true;
        errorMessage=error;
    }
    ///add while comment
    while(type == TYPE_COMMENT_ONLY){
        operandVec.push_back(operand);
        operationVec.push_back(operation);
        labelVec.push_back(label);
        commentVec.push_back(comment);

        intermediateFile.push_back(line);
        errorMessageArr.push_back(errorMessage);
        locctrArr.push_back(locctr);
        fileIterator++;
        InstructionLine instructionComment = InstructionLine(input[fileIterator]);
        label = instructionComment.getLabel();
        operand = instructionComment.getOperand();
        operation = instructionComment.getOperation();
        line = instructionComment.getLine();
        error = instructionComment.getError();
        type = instructionComment.getType();
        comment = instructionComment.getComment();
        format = instructionComment.getInstructionFormatType();
        toUpper(&operation);

    }
    if(operation == "START"){
        locctr = atoi(operand.c_str());
        startingAdrr = locctr;
        startFlag = true;
        if (type == TYPE_WITH_LABEL) {
            symTab.addSymbol(&label, locctr, false);
        }
    }
    if(!startFlag){
        locctr = 0;
        startingAdrr = 0;
    }
    operandVec.push_back(operand);
    operationVec.push_back(operation);
    labelVec.push_back(label);
    commentVec.push_back(comment);
    intermediateFile.push_back(line);
    errorMessageArr.push_back(errorMessage);
    locctrArr.push_back(locctr);
    locctrArr.push_back(locctr);
    fileIterator++;


    while(operation != "END" && fileIterator !=  input.size()){
        InstructionLine instruct = InstructionLine(input[fileIterator]);
        errorMessage="";
        label = instruct.getLabel();
        operand = instruct.getOperand();
        operation = instruct.getOperation();
        line = instruct.getLine();
        type = instruct.getType();
        toUpper(&operation);
        format = instruct.getInstructionFormatType();
        error = instruct.getError();
        comment = instruct.getComment();

        if(type != TYPE_COMMENT_ONLY){

            if (error != "") {
                errorFound = true;
                errorMessage = instruct.getError();
                operandVec.push_back(operand);
                operationVec.push_back(operation);
                labelVec.push_back(label);
                commentVec.push_back(comment);
                intermediateFile.push_back(line);
                errorMessageArr.push_back(errorMessage);
                locctrArr.push_back(locctr);
                fileIterator ++;
                continue;
            }
            if(operation == "END") {
                endFound = true;
                errorMessage = "";
                operandVec.push_back(operand);
                operationVec.push_back(operation);
                labelVec.push_back(label);
                commentVec.push_back(comment);
                intermediateFile.push_back(line);
                locctrArr.push_back(locctr);
                break;
            }
            if(opTable.contains(operation)){
                    if(operation == "LDB" && baseFound){
                        endBaseFound = true;
                    }
            } else if (!dirs.contains(operation)) {
                errorMessage = "Opcode doesn't exist";
                errorFound = true;
                operandVec.push_back(operand);
                operationVec.push_back(operation);
                labelVec.push_back(label);
                commentVec.push_back(comment);
                intermediateFile.push_back(line);
                errorMessageArr.push_back(errorMessage);
                locctrArr.push_back(locctr);
                fileIterator ++;
                continue;
            }
            if((operation == "NOBASE" || operation == "LTORG")
                && type != TYPE_WITHOUT_LABEL_AND_OPERAND && type != TYPE_WITH_LABEL_WITHOUT_OPERAND){
                errorMessage = operation + " found with label or operand";
                errorFound = true;
                operandVec.push_back(operand);
                operationVec.push_back(operation);
                labelVec.push_back(label);
                commentVec.push_back(comment);
                intermediateFile.push_back(line);
                errorMessageArr.push_back(errorMessage);
                locctrArr.push_back(locctr);
                fileIterator ++;
                continue;
            }
            int operandType;
            if (type == TYPE_WITH_LABEL || type == TYPE_WITHOUT_LABEL) {
                operandType = opValid.getOperandType(operand);
                if (operandType == -1 || !opValid.isCompatible(operandType, operation, operand)) {
                    errorMessage = "operand is not valid";
                    errorFound = true;
                    operandVec.push_back(operand);
                    operationVec.push_back(operation);
                    labelVec.push_back(label);
                    commentVec.push_back(comment);
                    intermediateFile.push_back(line);
                    errorMessageArr.push_back(errorMessage);
                    locctrArr.push_back(locctr);
                    fileIterator ++;

                    continue;
                }
                if (operandType == TYPE_HEXA_LITERAL ||
                    operandType == TYPE_BYTE_LITERAL ||
                    operandType == TYPE_WORD_LITERAL) {
                    if(!litTab.contain(operand)){
                        litTab.addLiteral(operand, operandType);
                    }
                }
            }
            if(type == TYPE_WITH_LABEL || type == TYPE_WITH_LABEL_WITHOUT_OPERAND){

                if(symTab.containSymbol(&label)){
                    errorMessage = "duplicated label in symbol table";
                    errorFound = true;
                } else{
                    if(opTable.contains(label) || dirs.contains(label)) {
                        errorMessage = "Label cannot be Mnemonic";
                        errorFound = true;
                    } else {
                        char opType = evaluateType(operation, operand, operandType);
                        symTab.addSymbol(&label, locctr, opType);
                    }
                }
            }

            if(operation == "WORD"){
                locctr += 3;
            } else if(operation == "RESW"){
                locctr += 3 * atoi(operand.c_str());
            } else if(operation == "RESB"){
                locctr += atoi(operand.c_str());
            } else if(operation == "BYTE"){
                if (operandType == TYPE_HEXA_OPERAND) {
                    locctr += (operand.length() - 3)/2;
                } else if (operandType == TYPE_BYTE_OPERAND) {
                    locctr += (operand.length() - 3);
                }
            } else if (operation == "ORG") {
                if (operandType == TYPE_SYMBOL_OPERAND
                    && !symTab.containSymbol(&operand)) {
                        errorMessage = "error in operand";
                        errorFound = true;
                } else if (operandType == TYPE_SYMBOL_OPERAND
                    && symTab.containSymbol(&operand)){
                    locctr = symTab.getSymbolAddress(&operand);
                } else if (operandType == TYPE_WORD_OPERAND) {
                    locctr = atoi(operand.c_str());
                }
            } else if (operation == "EQU") {
                if ((operandType == TYPE_IMMEDITAE_SYMBOL
                    || operandType == TYPE_INDIRECT_SYMBOL
                    || operandType == TYPE_SYMBOL_OPERAND)
                    && !symTab.containSymbol(&operand)) {
                        errorMessage = "label is not defined before EQU";
                        errorFound = true;
                } else if (operandType == TYPE_SIMPLE_EXPRESSION){
                    string symbolFromExp = getSymbol(operand);
                    if (!symTab.containSymbol(&symbolFromExp)) {
                        errorMessage = "label is not defined before EQU";
                        errorFound = true;
                    }
                }
            } else if (operation == "LTORG") {
                locctr = litTab.assignAddress(locctr);
                ltorgFound = true;
            } else if (operation == "BASE") {
                baseFound = true;
            }
            if(format == 4){
                locctr += 4;
                operationVec.push_back("+" +operation);

            } else{
                format = opTable.getFormat(operation);
                locctr += format;
               operationVec.push_back(operation);

            }

            operandVec.push_back(operand);
            labelVec.push_back(label);
            commentVec.push_back(comment);
            intermediateFile.push_back(line);
            errorMessageArr.push_back(errorMessage);
            locctrArr.push_back(locctr);

            fileIterator ++;
            if(fileIterator == input.size()) {
               break;
            }
        } else {
            operationVec.push_back("");
            operandVec.push_back("");
            labelVec.push_back("");
            commentVec.push_back(comment);
            intermediateFile.push_back("");
            errorMessageArr.push_back("");
            locctrArr.push_back(locctr);

            fileIterator ++;
            if(fileIterator == input.size()) {
               break;
            }
        }

        //handle if endBase = false; then error in line of base or load base
    }

    if(baseFound && !endBaseFound){
        errorMessage = "base not closed";
        errorFound = true;
        errorMessageArr.push_back(errorMessage);
    }
    if (operation == "END") {
        if (baseFound && !baseFound) {
            errorMessage = "Base register is not identified";
            errorFound = true;
            errorMessageArr.push_back(errorMessage);
        }
        if (type == TYPE_WITH_LABEL || type == TYPE_WITH_LABEL_WITHOUT_OPERAND) {
            if (!symTab.containSymbol(&label)) {
                symTab.addSymbol(&label, locctr, false);
            } else {
                errorMessage = "duplicate symbol";
                errorFound = true;
                errorMessageArr.push_back(errorMessage);
            }
        }
        if (type == TYPE_WITH_LABEL || type == TYPE_WITHOUT_LABEL) {
            int operandType = opValid.getOperandType(operand);
            if(operandType == -1 || !opValid.isCompatible(operandType, operation, operand)) {
              errorMessage = "operand is not valid";
              errorFound = true;
              errorMessageArr.push_back(errorMessage);
            }
        }
    }
    errorMessageArr.push_back(errorMessage);

    if(!ltorgFound){
        litTab.assignAddress(locctr);
    }
    if(!endFound){
        errorMessage = "End statement not found";
        errorFound = true;
        operandVec.push_back(operand);
        operationVec.push_back(operation);
        labelVec.push_back(label);
        commentVec.push_back(comment);
        intermediateFile.push_back(line);
        errorMessageArr.push_back(errorMessage);
        locctrArr.push_back(locctr);
    }

    litTab.setVectors();
    file.writeFile(labelVec, operationVec, operandVec, commentVec, errorMessageArr, locctrArr, "pass1.txt", litTab);
    symTab.printSymbolTable();
    file.writeLitralFile(litTab.nameV, litTab.valueV, litTab.lengthV, litTab.addressV, "Literal Table.txt");


}

string Controller::getSymbol(string expression) {
    std::size_t pos = expression.find("+");
    std::string symbolInExpression = expression.substr(0,pos);

    if (expression == symbolInExpression) {
        pos = expression.find("-");
        symbolInExpression = expression.substr(0,pos);
    }
    return symbolInExpression;
}
void Controller::toUpper(string* symbolName) {
        transform(symbolName->begin(), symbolName->end(), symbolName->begin(), ::toupper);
}

char Controller::evaluateType(string operation, string operand, int type){
    if (operation == "WORD" || operation == "BYTE"
        || operation == "RESW" || operation == "RESB") {
        return 'R';
    } else if (type == TYPE_IMMEDITAE_WORD || type == TYPE_INDIRECT_WORD
               || type == TYPE_HEXA_LITERAL || type == TYPE_WORD_LITERAL
               || type == TYPE_BYTE_LITERAL) {

                return 'R';
    } else if (type == TYPE_IMMEDITAE_SYMBOL || type == TYPE_INDIRECT_SYMBOL) {
        string symbolName = operand.substr(1, operand.length() - 1);
         if (symTab.containSymbol(&symbolName)) {
            return symTab.getSymbolType(&symbolName);
        }
        return 'U';
    } else if (type == TYPE_SYMBOL_OPERAND) {
         if (symTab.containSymbol(&operand)) {
            return symTab.getSymbolType(&operand);
        }
        return 'U';
    } else if (type == TYPE_INDEXED_SYMBOL) {
        string symbolName = operand.substr(0, operand.length() - 2);
        if (symTab.containSymbol(&symbolName)) {
            return symTab.getSymbolType(&symbolName);
        }
        return 'U';
    } else if (type == TYPE_SIMPLE_EXPRESSION) {
        std::size_t sign = operand.find('+');
        if (sign > operand.length()) {
            sign = operand.find('-');
        }
        string operand1;
        if (isdigit(operand.at(0))) {
            operand1 = operand.substr(sign + 1, operand.length() - sign - 1);
        } else {
             operand1 = operand.substr(0, sign);
        }
        if (symTab.containSymbol(&operand1)) {
            return symTab.getSymbolType(&operand1);
        }
        return 'U';
    } else if (type == TYPE_COMPLEX_EXPRESSION) {
        std::size_t sign = operand.find('+');
        if (sign > operand.length()) {
            sign = operand.find('-');
        }
        string operand1 = operand.substr(sign + 1, operand.length() - sign - 1);
        string operand2 = operand.substr(0, sign);
        if ((symTab.getSymbolType(&operand1)=='A' && symTab.getSymbolType(&operand2) == 'A')
            || (symTab.getSymbolType(&operand1) == 'R' && symTab.getSymbolType(&operand2) == 'R' && sign == '-')) {
            return 'A';
        } else if ((symTab.getSymbolType(&operand1) == 'A' && symTab.getSymbolType(&operand2) == 'R' && sign == '+')
                   || (symTab.getSymbolType(&operand1) =='R' && symTab.getSymbolType(&operand2) == 'A')) {
            return 'R';
        }
        return 'U';
    }

}

SymbolTable Controller::getSymbolTable(){
    return symTab;
}

LitTable Controller::getLitTable () {
    return litTab;
}

bool Controller::error(){
    return errorFound;
}
