//
// Created by Carnival Stores on 4/27/2018.
//

#ifndef PASS1_INOUTFILE_H
#define PASS1_INOUTFILE_H
#include "Converters.h"
#include <vector>
#include <iostream>
#include<LitTable.h>

using namespace std;


class inOutFile {
public:
    static vector<string> readFile(string);
    void static writeFile(vector<string>,vector<string>,vector<string>,vector<string>,
                          vector<string>,vector<int>, string, LitTable);
    void static writeSymbolFile(vector<string>, vector<string>,string);
    void static writeLitralFile(vector<string>, vector<string>,
                                vector<int>, vector<string>,string);
    void writeHeaderFile(vector<string>, string, string, string);

    private:
    Converters converter;
};


#endif //PASS1_INOUTFILE_H
