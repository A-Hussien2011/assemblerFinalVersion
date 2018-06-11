// Created by Carnival Stores on 4/27/2018.
//

#include "inOutFile.h"
#include <iostream>
#include "fstream"
#include <vector>
#include "Converters.h"
#include <iomanip>
#include<LitTable.h>

using namespace std;

vector<string> inOutFile::readFile(string fileName) {
    string line;
    ifstream file(fileName);
    std::vector<std::string> fileContent;

    while( std::getline( file, line ) ) {
        fileContent.push_back( line );
    }
    return fileContent;
}

void inOutFile::writeFile(vector<string> label,vector<string> operation, vector<string> operand,
                          vector<string> comment,vector<string> errorMessageArr,
                          vector<int> locctrArr, string fileName, LitTable literalTable) {
    int line;
    std::size_t line_count = operation.size();
    std::ofstream out(fileName);
    Converters convert;
    out << setw(10) << left << "                          PASS 1 " << setw(10) << left << endl;
     out << setw(10) << left << "Line" << setw(10) << left << "Address"<< setw(10) << left <<"Label";
      out << setw(15) << left << "Operation" << setw(10) << left << "Operand";
       out << setw(10) << left << "Comment" << setw(10) << left << endl;
    for( std::size_t i = 0; i < line_count; ++i ) {
        string locctr = convert.convertToHexa(locctrArr[i]);
        line = i+1;
        if (label[i] == "" && operation[i]== "" && operand[i] == "" && comment[i] != "") {
           out << setw(10) << left << line << setw(10) << left << locctr << setw(10) << left << comment[i]<<endl;
           continue;
        }
        out << setw(10) << left << line << setw(10) << left << locctr << setw(10) << left << label[i];
      out << setw(15) << left << operation[i] << setw(10) << left << operand[i];
       out << setw(10) << left << comment[i] << setw(10) << left << endl;
        if (errorMessageArr[i].length() > 2) {
        out << setw(10) << left << " ***** Error:" << errorMessageArr[i] << setw(10) << left <<endl;
        }
    }


     std::vector<std::string> nameV = literalTable.nameV;
     std::vector<std::string> valueV = literalTable.valueV;
     std::vector<std::string> addressV = literalTable.addressV;

     line_count = nameV.size();

     for( std::size_t i = 0; i < line_count; ++i ) {
        line++;
        out << setw(10) << left << line << setw(10) << left << addressV[i] << setw(10) << left << "*";
        out << setw(15) << left << nameV[i] << setw(10) << left << valueV[i] << endl;
    }
    out.close();
}
void inOutFile::writeSymbolFile(vector<string> name, vector<string> address, string fileName) {
    std::size_t line_count = name.size();
    std::ofstream out(fileName);
    out << setw(10) << left << " SYMBOL TABLE" << setw(10) << left << endl;
     out << setw(10) << left << "Name" << setw(10) << left << "Address"<<endl;
    for( std::size_t i = 0; i < line_count; ++i ) {
        out << setw(10) << left << name[i] << setw(10) << left << address[i]<<endl;
    }
    out.close();
}
void inOutFile::writeLitralFile(vector<string> name, vector<string> value,
                                vector<int> length, vector<string> address, string fileName) {
    std::size_t line_count = name.size();
    std::ofstream out(fileName);
    out << setw(10) << left << "            LITERAL TABLE" << setw(10) << left << endl;
     out << setw(10) << left << "Name" << setw(10) << left << "Value";
    out << setw(10) << left << "Length" << setw(10) << left << "Address"<<endl;
    for( std::size_t i = 0; i < line_count; ++i ) {
        out << setw(10) << left << name[i] << setw(10) << left << value[i];
        out << setw(10) << left << length[i] << setw(10) << left << address[i]<<endl;
    }
    out.close();
}

void inOutFile::writeHeaderFile(vector<string> objectCode, string startAddress, string length, string name){
    int size_line = 0;
    ofstream file;
    converter = Converters();
    file.open ("objectCode.txt");
    std::size_t counter = objectCode.size();
    string textStartAddress = startAddress;
    file << "H^" + name + "^" +startAddress + "^" + length + "\n";
    string temp = "";
    for (int i = 0; i < counter; i++) {
        if(temp.length() + objectCode[i].length() <= 60){
            temp += objectCode[i];
        }
        else {
            textStartAddress = converter.convertToHexa((temp.length()/2) + strtol(textStartAddress.c_str(), NULL, 2));
            file << "T^";
            file << converter.convertToHexa(atoi(startAddress.c_str()) + size_line) << "^";
            size_line += temp.length()/2;
            file << converter.convertToHexa(temp.length()/2) + "^";
            file << temp + "^" + "\n";
            temp = "";
        }
    }
    if (temp != "") {
        textStartAddress = converter.convertToHexa((temp.length()/2) + strtol(textStartAddress.c_str(), NULL, 2));
            file << "T^";
            file << converter.convertToHexa(atoi(startAddress.c_str()) + size_line) << "^";
            size_line += temp.length()/2;
            file << converter.convertToHexa(temp.length()/2) + "^";
            file << temp + "\n";
            temp = "";
    }
    file << "E^";
    file << startAddress;
    file.close();
}
