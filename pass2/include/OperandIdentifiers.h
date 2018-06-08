#ifndef OPERANDIDENTIFIERS_H
#define OPERANDIDENTIFIERS_H
#include "OperandValidator.h"
#include "SymbolTable.h"
#include "LitTable.h"
#include <string>

using namespace std;

class OperandIdentifiers
{
    public:
        OperandIdentifiers(SymbolTable, LitTable);
        void setOperand(string);
        bool getNflag();
        bool getIflag();
        bool getXflag();
        string getDispalcement();
        bool isValidExpression();
        bool isSymbolFound();

    private:
        OperandValidator opValidator;
        SymbolTable symbolTable;
        LitTable literalTtable;
        Converters convert;
        int type;
        bool validExpression;
        bool symbolFound;
        void setSymbolFound();
        void setValidExpression();
        string getOperand();
        string operand;
        void setOperandType(string);
        string evaluateExpression();

        //these are used in case of expression only
        string symbol1;
        string symbol2;
        int num;
        char signOperation;

        static const int TYPE_IMMEDITAE_WORD = 0;
        static const int TYPE_IMMEDITAE_SYMBOL = 1;
        static const int TYPE_INDIRECT_WORD = 2;
        static const int TYPE_INDIRECT_SYMBOL = 3;
        static const int TYPE_SYMBOL_OPERAND = 4;
        static const int TYPE_HEXA_LITERAL = 5;
        static const int TYPE_WORD_LITERAL = 6;
        static const int TYPE_BYTE_LITERAL = 7;
        static const int TYPE_HEXA_OPERAND = 8;
        static const int TYPE_BYTE_OPERAND = 9;
        static const int TYPE_INDEXED_SYMBOL = 10;
        static const int TYPE_WORD_OPERAND = 11;
        static const int TYPE_REGISTER_TO_REGISTER = 12;
        static const int TYPE_LOCCTR = 13;
        static const int TYPE_SIMPLE_EXPRESSION = 14;
        static const int TYPE_COMPLEX_EXPRESSION = 15;
};

#endif // OPERANDIDENTIFIERS_H
