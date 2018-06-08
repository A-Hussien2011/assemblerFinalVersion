#include "OperandIdentifiers.h"
#include <string>
#include "OperandValidator.h"
#include "SymbolTable.h"
#include "LitTable.h"

using namespace std;
///notes for using this class: first instantiate and the constructor have both the literal and symbol tables
///then set operand where the operand type(based on operand validator class) is also set then get flags and displacement
///and must check if string returned is an empty string then the operand is not valid and u must check why

OperandIdentifiers::OperandIdentifiers(SymbolTable symTable, LitTable litTable){
    symbolTable = symTable;
    literalTtable = litTable;
}
void OperandIdentifiers::setOperand(string opernd){
    operand =  opernd;
    setOperandType(operand);

}
void OperandIdentifiers::setOperandType(string operand){
    type = opValidator.getOperandType(operand);
}
bool OperandIdentifiers::getNflag(){
    return (type == TYPE_INDIRECT_WORD || type == TYPE_INDIRECT_SYMBOL);
}
bool OperandIdentifiers::getIflag(){
    return (type == TYPE_IMMEDITAE_WORD || type == TYPE_IMMEDITAE_SYMBOL);
}
bool OperandIdentifiers::getXflag(){
    return type == TYPE_INDEXED_SYMBOL;
}
string OperandIdentifiers::getOperand(){
    return operand;
}
bool OperandIdentifiers::isValidExpression(){
    return validExpression;
}
bool OperandIdentifiers::isSymbolFound(){
    return symbolFound;
}

void OperandIdentifiers::setValidExpression(){
    if(type == TYPE_SIMPLE_EXPRESSION){
        signOperation = '+';
        std::size_t pos = operand.find('+');
        if (pos > operand.length()) {
            signOperation = '-';
            pos = operand.find('-');
        }
        if (!isdigit(operand.at(0))) {
            symbol1 = operand.substr(0, pos);
            string temp = operand.substr(pos+1, operand.length() - pos - 1);
            symbol2 = "";
            num = atoi(temp.c_str());
            validExpression = true;
            return;
        }
        symbol2 = operand.substr(pos + 1, operand.length() - pos - 1);
        if (signOperation =='+' || (signOperation == '-' && symbolTable.getSymbolType(&symbol2)!= 'R')) {
            validExpression = true;
            symbol1 = "";
            string temp = operand.substr(0, pos);
            num = atoi(temp.c_str());
            return;
        }
    } else if (type == TYPE_COMPLEX_EXPRESSION) {
        if ((symbolTable.getSymbolType(&symbol1) != 'R' && symbolTable.getSymbolType(&symbol2) != 'R')
            || (symbolTable.getSymbolType(&symbol1) == 'R' && symbolTable.getSymbolType(&symbol2) != 'R')
            || (symbolTable.getSymbolType(&symbol1) != 'R' && symbolTable.getSymbolType(&symbol2) == 'R' && signOperation =='+')
            || (symbolTable.getSymbolType(&symbol1) == 'R' && symbolTable.getSymbolType(&symbol2) == 'R' && signOperation =='-')) {

            validExpression = true;
            return;
        }
    }
    validExpression = false;
}

void OperandIdentifiers::setSymbolFound() {
    if (type == TYPE_SYMBOL_OPERAND && symbolTable.containSymbol(&operand)) {
        symbolFound = true;
        return;
    } else if (type == TYPE_IMMEDITAE_SYMBOL || type == TYPE_INDIRECT_SYMBOL){
        operand = operand.substr(1, operand.length() - 1);
        if (symbolTable.containSymbol(&operand)) {
            symbolFound = true;
            return;
        }
    } else if (type == TYPE_INDEXED_SYMBOL) {
        operand = operand.substr(0, operand.length() - 2);
        if (symbolTable.containSymbol(&operand)) {
            symbolFound = true;
            return;
        }
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
        if (symbolTable.containSymbol(&operand1)) {
            symbolFound = true;
            return;
        }
    } else if (type == TYPE_COMPLEX_EXPRESSION) {
        std::size_t sign = operand.find('+');
        signOperation = '+';
        if (sign > operand.length()) {
            sign = operand.find('-');
            signOperation = '-';
        }
        symbol2 = operand.substr(sign + 1, operand.length() - sign - 1);
        symbol1 = operand.substr(0, sign);
        if (symbolTable.containSymbol(&symbol1) && symbolTable.containSymbol(&symbol2)) {
            symbolFound = true;
            return;
        }
    }
    symbolFound = false;
}

string OperandIdentifiers::getDispalcement(){

    if (type == TYPE_SYMBOL_OPERAND || type == TYPE_IMMEDITAE_SYMBOL
        || type == TYPE_INDIRECT_SYMBOL || type == TYPE_INDEXED_SYMBOL
        || type == TYPE_SIMPLE_EXPRESSION || type == TYPE_COMPLEX_EXPRESSION) {
          setSymbolFound();
    } else {
          symbolFound = true;
    }

    if (!symbolFound) {
        return "";
    }

    if (type == TYPE_SIMPLE_EXPRESSION || type == TYPE_COMPLEX_EXPRESSION) {
        setValidExpression();
    } else {
        validExpression = true;
    }
    if (!validExpression) {
        return "";
    }

    if (type == TYPE_IMMEDITAE_SYMBOL || type == TYPE_INDIRECT_SYMBOL
        || type == TYPE_SYMBOL_OPERAND) {
            int address = symbolTable.getSymbolAddress(&operand);
        return convert.convertToHexa(address);
    } else if (type == TYPE_INDEXED_SYMBOL) {
        int address = symbolTable.getSymbolAddress(&operand);
        return convert.convertToHexa(address);
    } else if (type == TYPE_IMMEDITAE_WORD || type == TYPE_INDIRECT_WORD) {///must check if negative first
        return operand.substr(1, operand.length() - 1);
    } else if (type == TYPE_HEXA_LITERAL || type == TYPE_WORD_LITERAL || type == TYPE_BYTE_LITERAL) {
        ///el literal byd5oly keda =C'FOE'
        int address = literalTtable.getAddress(operand);
        return convert.convertToHexa(address);
    } else if (type == TYPE_SIMPLE_EXPRESSION || type == TYPE_COMPLEX_EXPRESSION) {
        return evaluateExpression();
    }
    return "";
}

string OperandIdentifiers::evaluateExpression() {
    if (type == TYPE_SIMPLE_EXPRESSION) {
        if (symbol1 == "") {
            if (signOperation == '+') {
                num = num + symbolTable.getSymbolAddress(&symbol2);
            } else {
                num = num - symbolTable.getSymbolAddress(&symbol2);
            }
        } else {
            if (signOperation == '+') {
                num = symbolTable.getSymbolAddress(&symbol1) + num;
            } else {
                num = symbolTable.getSymbolAddress(&symbol1) - num;
            }
        }
        return convert.convertToHexa(num);
    } else if (type == TYPE_COMPLEX_EXPRESSION) {
        int result;
        if (signOperation == '+') {
            result = symbolTable.getSymbolAddress(&symbol1) + symbolTable.getSymbolAddress(&symbol2);
        } else {
            result = symbolTable.getSymbolAddress(&symbol1) - symbolTable.getSymbolAddress(&symbol2);
        }
        return convert.convertToHexa(result);
    }
    return "";
}

