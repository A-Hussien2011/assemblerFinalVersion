#ifndef PASS2CONTROLLER_H
#define PASS2CONTROLLER_H
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


class Pass2Controller
{
    public:
        Pass2Controller();
        bool generateIntermediateFile(string);
        void generateObjectCode();
        void generateFinalFile(string, string);

    private:
        DisplacementController displacementController;
        Format format;
        Controller controller;
        inOutFile file;
        Converters converter;
        OperandValidator OpValidator;
        vector< string > objectCodeArr;
        string getLength();
        string getLiteralObjectCode(string, LitTable);
        string getWordObjectCode(string);
        string getByteObjectCode(string);
        string endStartingAddress;
        char evaluateType(string, string, int, SymbolTable);
        void setSymbolType(string, string, int, SymbolTable);

        string startingAddress;
        string endingAddress;

        static const int TYPE_IMMEDITAE_WORD = 0; //A
        static const int TYPE_IMMEDITAE_SYMBOL = 1; //R
        static const int TYPE_INDIRECT_WORD = 2;   //A
        static const int TYPE_INDIRECT_SYMBOL = 3; //R
        static const int TYPE_SYMBOL_OPERAND = 4;  //R for all except equ
        static const int TYPE_HEXA_LITERAL = 5;  //u
        static const int TYPE_WORD_LITERAL = 6;  //u
        static const int TYPE_BYTE_LITERAL = 7;  //u
        static const int TYPE_HEXA_OPERAND = 8;  //R
        static const int TYPE_BYTE_OPERAND = 9; //R
        static const int TYPE_INDEXED_SYMBOL = 10; //R
        static const int TYPE_WORD_OPERAND = 11; //A for all except word itself
        static const int TYPE_REGISTER_TO_REGISTER = 12; //u
        static const int TYPE_LOCCTR = 13;//R idk el sra7a
        static const int TYPE_SIMPLE_EXPRESSION = 14;//depending
        static const int TYPE_COMPLEX_EXPRESSION = 15;
};

#endif // PASS2CONTROLLER_H
