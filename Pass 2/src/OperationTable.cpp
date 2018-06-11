#include <iostream>
#include "../include/OperationTable.h"

#define THREE 3
#define ONE 1
#define TWO 2
#define FOUR 4
#define OPTIONAL 0
#define MUST_EXIST 1
#define NOT_EXIST -1
#include <iostream>
#include <string>
using namespace std;

OperationTable *OperationTable::instance = 0;
OperationTable *OperationTable::getInstance() {
    if (instance == 0)
        instance = new OperationTable;
    return instance;
}
OperationTable::OperationTable() {
    initOpTable();
}

void OperationTable::initOpTable() {
    std::string opName;
    OperationInformation info;

    opName = "ADD";
    info = OperationInformation();
    info.opCode = "18";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "ADDF";
    info = OperationInformation();
    info.opCode = "58";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "ADDR";
    info = OperationInformation();
    info.opCode = "90";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "SUB";
    info = OperationInformation();
    info.opCode = "1C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

     opName = "SUBF";
    info = OperationInformation();
    info.opCode = "5C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

     opName = "SUBR";
    info = OperationInformation();
    info.opCode = "94";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "MUL";
    info = OperationInformation();
    info.opCode = "20";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "MULF";
    info = OperationInformation();
    info.opCode = "60";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "MULR";
    info = OperationInformation();
    info.opCode = "98";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "DIV";
    info = OperationInformation();
    info.opCode = "24";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "DIVF";
    info = OperationInformation();
    info.opCode = "64";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "DIVR";
    info = OperationInformation();
    info.opCode = "9C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "AND";
    info = OperationInformation();
    info.opCode = "40";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "OR";
    info = OperationInformation();
    info.opCode = "44";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "COMP";
    info = OperationInformation();
    info.opCode = "28";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "COMPF";
    info = OperationInformation();
    info.opCode = "88";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "COMPR";
    info = OperationInformation();
    info.opCode = "A0";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "LDA";
    info = OperationInformation();
    info.opCode = "00";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "LDCH";
    info = OperationInformation();
    info.opCode = "50";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "LDB";
    info = OperationInformation();
    info.opCode = "68";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "LDF";
    info = OperationInformation();
    info.opCode = "70";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "LDS";
    info = OperationInformation();
    info.opCode = "6C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "LDT";
    info = OperationInformation();
    info.opCode = "74";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "LDL";
    info = OperationInformation();
    info.opCode = "08";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "LDX";
    info = OperationInformation();
    info.opCode = "04";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "TD";
    info = OperationInformation();
    info.opCode = "E0";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "RD";
    info = OperationInformation();
    info.opCode = "D8";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "WD";
    info = OperationInformation();
    info.opCode = "DC";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "TIX";
    info = OperationInformation();
    info.opCode = "2C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STA";
    info = OperationInformation();
    info.opCode = "0C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STCH";
    info = OperationInformation();
    info.opCode = "54";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STL";
    info = OperationInformation();
    info.opCode = "14";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STX";
    info = OperationInformation();
    info.opCode = "10";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "J";
    info = OperationInformation();
    info.opCode = "3C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "JEQ";
    info = OperationInformation();
    info.opCode = "30";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "JGT";
    info = OperationInformation();
    info.opCode = "34";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "JLT";
    info = OperationInformation();
    info.opCode = "38";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "JSUB";
    info = OperationInformation();
    info.opCode = "48";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "RSUB";
    info = OperationInformation();
    info.opCode = "4C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    info.tybe = ONE;
    opTable[opName] = info;

    opName = "TIXR";
    info = OperationInformation();
    info.opCode = "B8";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "TIO";
    info = OperationInformation();
    info.opCode = "F8";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "CLEAR";
    info = OperationInformation();
    info.opCode = "B4";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "SVC";
    info = OperationInformation();
    info.opCode = "B0";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "FIX";
    info = OperationInformation();
    info.opCode = "C4";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    info.tybe = ONE;
    opTable[opName] = info;

    opName = "FLOAT";
    info = OperationInformation();
    info.opCode = "C0";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    info.tybe = ONE;
    opTable[opName] = info;

    opName = "HIO";
    info = OperationInformation();
    info.opCode = "F4";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    info.tybe = ONE;
    opTable[opName] = info;

    opName = "LPS";
    info = OperationInformation();
    info.opCode = "D0";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "NRMO";
    info = OperationInformation();
    info.opCode = "C8";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    info.tybe = ONE;
    opTable[opName] = info;

    opName = "RMO";
    info = OperationInformation();
    info.opCode = "AC";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "SHIFTL";
    info = OperationInformation();
    info.opCode = "A4";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "SHIFTR";
    info = OperationInformation();
    info.opCode = "A8";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    info.tybe = TWO;
    opTable[opName] = info;

    opName = "SIO";
    info = OperationInformation();
    info.opCode = "F0";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    info.tybe = ONE;
    opTable[opName] = info;

    opName = "SSK";
    info = OperationInformation();
    info.opCode = "EC";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STB";
    info = OperationInformation();
    info.opCode = "78";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STCH";
    info = OperationInformation();
    info.opCode = "54";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STF";
    info = OperationInformation();
    info.opCode = "80";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STI";
    info = OperationInformation();
    info.opCode = "D4";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STL";
    info = OperationInformation();
    info.opCode = "14";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STS";
    info = OperationInformation();
    info.opCode = "7C";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STSW";
    info = OperationInformation();
    info.opCode = "E8";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STT";
    info = OperationInformation();
    info.opCode = "84";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "STX";
    info = OperationInformation();
    info.opCode = "10";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

    opName = "ORG";
    info = OperationInformation();
    info.opCode = "18";
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    info.tybe = THREE;
    opTable[opName] = info;

}

bool OperationTable::contains(std::string operation) {
    return OperationTable::opTable.find(operation) != OperationTable::opTable.end();
}

OperationInformation OperationTable::getInfo(std::string operation) {
return OperationTable::opTable[operation];
}
void OperationTable::test()
{
   std::cout << "test success!" << std::endl;
}
int OperationTable::getFormat(std::string operation) {
    return OperationTable::getInstance()->getInfo(operation).tybe;
}
