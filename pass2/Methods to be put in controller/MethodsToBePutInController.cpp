#include "MethodsToBePutInController.h"

using namespace std;

string MethodsToBePutInController::getObjectCode(string literal) {
    return literalTable.getValue(literal);
}
string MethodsToBePutInController::getByteObjectCode(string operand) {
    string code;
     for (int i = 3; i < operand.length() - 1; i++) {
        code.append(literalTable.getAscii(operand.at(i)));
    }
    return code;
}
void MethodsToBePutInController::setSymbolType(string operation, string operand, int type) {
    char type = evaluateType(operation, operand, type);
    ///symboltable.modifySymbol(lable, type); 7nktbha sa7 fel controller

}
char MethodsToBePutInController::evaluateType(string operation, string operand, int type){
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
