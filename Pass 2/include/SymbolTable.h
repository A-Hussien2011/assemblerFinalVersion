#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <algorithm>
#include <iostream>
#include <map>
#include "inOutFile.h"

using namespace std;

class SymbolTable
{
    public:
        SymbolTable();
        /*add symbol [name, address, type]
        return error if exists
        */
        void addSymbol(string*, int, char);
        //edit symbol address, type
        void modifySymbol(string*, int, char);
        //check if symbol exists
        bool containSymbol(string*);

        int getSymbolAddress(string*);
        char getSymbolType(string*);
        int getSymbolLength(string*);
        void printSymbolTable();

    private:
        inOutFile file;
        int symbolLength(string);
        void toUpper(string*);
        //info about the symbol
        struct symbol_info {
            int address;
            char type;
            int length;
        };
        //map that stores the symbols
        map<string, symbol_info> symbol_table;
        //iterator for map iteration
        map<string, symbol_info>::iterator symbol_table_iterator;
};

#endif // SYMBOLTABLE_H
