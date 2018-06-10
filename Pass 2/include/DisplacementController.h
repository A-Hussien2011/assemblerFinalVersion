#ifndef DISPLACEMENTCONTROLLER_H
#define DISPLACEMENTCONTROLLER_H
#include "OperandIdentifiers.h"
#include <algorithm>
#include <bitset>
#include <string>
#include "InstructionLine.h"
#include "OperationTable.h"
#include "RegistersTable.h"
#include "Converters.h"

class DisplacementController
{
    public:
        DisplacementController(OperandIdentifiers);
        bool getPCflag();
        bool getBflag();
        string getDispalcement();
        void setValidBase(bool);
        void setDispalcement(string, string, string, string, int);
    private:
        OperandIdentifiers OperandIdent;
        InstructionLine InstLine;
        OperationTable OpTable;
        RegistersTable registersTable;
        Converters converter;

        void setPCflag(bool);
        void setBflag(bool);
        void setEflag(bool);
        int addBinary(string, string);
        string convertToBin(int);
        string calculateDisp(string, string, string);

        bool PCflag;
        bool Bflag;
        bool Eflag;
        bool validBase;
        string displacement;

        static const int FORMAT_2 = 2;
        static const int FORMAT_3 = 3;
        static const int FORMAT_4 = 4;
        static const int NO_FORMAT = -1;
};

#endif // DISPLACEMENTCONTROLLER_H
