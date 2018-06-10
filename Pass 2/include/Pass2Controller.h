#ifndef PASS2CONTROLLER_H
#define PASS2CONTROLLER_H
#include <vector>
#include <string.h>
#include "OperandIdentifiers.h"
#include "DisplacementController.h"
#include "Format.h"
#include "Controller.h"
#include "include/IntermediateLine.h"
#include "inOutFile.h"
#include "Converters.h"

class Pass2Controller
{
    public:
        Pass2Controller();
        void generateIntermediateFile(string);
        void generateObjectCode();

    private:
        OperandIdentifiers operandIdentifiers;
        DisplacementController displacementController;
        Format format;
        Controller controller;
        IntermediateLine currentLine;
        IntermediateLine nextLine;
        inOutFile file;
        Converters converter;
        vector< string > objectCodeArr;
        string getLength();
        string getLiteralObjectCode(string);
        string getWordObjectCode(string);
        string getByteObjectCode(string);

        static const int TYPE_IMMEDITAE_SYMBOL = 1; //R
        static const int TYPE_INDIRECT_SYMBOL = 3;
        static const int TYPE_INDEXED_SYMBOL = 10; //R
        static const int TYPE_SIMPLE_EXPRESSION = 14;//depending
        static const int TYPE_COMPLEX_EXPRESSION = 15;
};

#endif // PASS2CONTROLLER_H
