#include "RegistersTable.h"

using namespace std;

RegistersTable::RegistersTable()
{
    initializeTable();
}

int RegistersTable::getRegisterNumber(string registerSymbol){
    itr = RegTable.find(registerSymbol);
    if (itr != RegTable.end()) {
        return itr-> second;
    }
    return -1;
}
void RegistersTable::initializeTable(){
    RegTable["A"] = 0;
    RegTable["X"] = 1;
    RegTable["L"] = 2;
    RegTable["B"] = 3;
    RegTable["S"] = 4;
    RegTable["T"] = 5;
    RegTable["F"] = 6;
    RegTable["SW"] = 8;
    RegTable["PC"] = 9;
}
