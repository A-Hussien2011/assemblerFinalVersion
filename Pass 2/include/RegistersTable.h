#ifndef REGISTERSTABLE_H
#define REGISTERSTABLE_H

#include <algorithm>
#include <iostream>
#include <map>
#include "inOutFile.h"

using namespace std;

class RegistersTable
{
    public:
        RegistersTable();
        int getRegisterNumber(string);
    private:
        void initializeTable();
        map<string, int> RegTable;
        map<string, int>::iterator itr;

};

#endif // REGISTERSTABLE_H
