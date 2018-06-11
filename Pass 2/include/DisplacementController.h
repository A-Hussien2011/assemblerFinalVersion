#ifndef DISPLACEMENTCONTROLLER_H
#define DISPLACEMENTCONTROLLER_H
#include "OperandIdentifiers.h"
#include <algorithm>
#include <bitset>
#include <string>
#include "RegistersTable.h"
#include "Converters.h"

class DisplacementController
{
    public:
        DisplacementController();
        bool getPCflag();
        bool getBflag();
        string getDispalcement();
        void setValidBase(bool);
        void setDispalcement(string, string, string, string, string, int);
        bool validBase;
        string convertToBin(int, int);
        int addBinary(string, string);
        void setDirectDisplacement(string);
    private:
        RegistersTable registersTable;
        Converters converter;

        void setPCflag(bool);
        void setBflag(bool);
        void setEflag(bool);
        void calculateDisp(string, string, string);

        bool PCflag;
        bool Bflag;
        bool Eflag;
        string displacement;

        static const int FORMAT_2 = 2;
        static const int FORMAT_3 = 3;
        static const int FORMAT_4 = 4;
        static const int NO_FORMAT = -1;
};

#endif // DISPLACEMENTCONTROLLER_H
