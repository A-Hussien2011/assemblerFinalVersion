#ifndef LITTABLE_H
#define LITTABLE_H

#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include "Converters.h"

using namespace std;

class LitTable
{

    public:
        void addLiteral(string, int);
        int assignAddress(int);
        int getLength(string);
        string getValue(string);
        bool contain(string);
        void setVectors();
        string getAscii(char);
        int getAddress(string);

        std::vector<std::string> nameV;
        std::vector<std::string> valueV;
        std::vector<int> lengthV;
        std::vector<std::string> addressV;

   private:
       string literalValue;
        int litLength(string);

        struct literal_info {
            char label;
            int address;
            int length;
            string value;
        };
        //map that stores the literals
        map<string, literal_info> literal_table;
        //iterator for map iteration
        map<string, literal_info>::iterator literal_table_iterator;

        string litValue(string, int);
        int getIncrValue (string);
        string convertCharToString(char [], int);
        string convertToHexa(int);
        unordered_map<char ,string> hashtable;
        int convertToBin(int);
        Converters convert;


};

#endif // LITTABLE_H
