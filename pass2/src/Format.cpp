#include "Format.h"
#include <sstream>
#include <bitset>
#include <string>

bool n;
bool i;
bool x;
bool b;
bool p;
bool e;
int format;
string opcode;
string displacement;

Format::Format()
{

}

void Format::setNflag(bool value){
    b = value;
}
void Format::setIflag(bool value){
    b = value;
}
void Format::setXflag(bool value){
    b = value;
}
void Format::setBflag(bool value){
    b = value;
}
void Format::setPflag(bool value){
    b = value;
}

void Format::setFormatType(int value){
    format = value;
}
void Format::setDispalcement(string value){
    displacement = value;
}
void Format::setOperationCode(string value){
    opcode = value;
}
string Format::getObjectCode(){
    string code = "";
    if (displacement == "") {
        return code;
    }
    string bincode = "";
    string s = opcode;
    stringstream ss;
    ss << hex << s;
    unsigned n;
    ss >> n;
    bitset<8> opCode(n);
    if(format == FORMAT_2){
        bincode += opCode.to_string();
        bincode += displacement;
    }
    else{
        string str = opCode.to_string();
        bincode = str.substr (0,6);
        if(n == true){
            bincode += "1";
        }else{
            bincode += "0";
        }
        if(i == true){
            bincode += "1";
        }else{
            bincode += "0";
        }
        if(x == true){
            bincode += "1";
        }else{
            bincode += "0";
        }
        if(b == true){
            bincode += "1";
        }else{
            bincode += "0";
        }
        if(p == true){
            bincode += "1";
        }else{
            bincode += "0";
        }
        if(format == FORMAT_4){
            bincode += "1";
        }else{
            bincode += "0";
        }
        bincode += displacement;
    }
    code = bin_to_hex(bincode);
    return code;
}

string Format::bin_to_hex(string val){
    string code = "";
    string tmp = "";
    int count = 0;
    for(int i = val.length() - 1; i >= 0; i--){
        if(tmp.length() == 4){
            if(tmp == "0000") code += "0";
            if(tmp == "0001") code += "1";
            if(tmp == "0010") code += "2";
            if(tmp == "0011") code += "3";
            if(tmp == "0100") code += "4";
            if(tmp == "0101") code += "5";
            if(tmp == "0110") code += "6";
            if(tmp == "0111") code += "7";
            if(tmp == "1000") code += "8";
            if(tmp == "1001") code += "9";
            if(tmp == "1010") code += "A";
            if(tmp == "1011") code += "B";
            if(tmp == "1100") code += "C";
            if(tmp == "1101") code += "D";
            if(tmp == "1110") code += "E";
            if(tmp == "1111") code += "F";
            tmp = "";
        }else{
            tmp += val[i];
        }
    }
    return code;
}

Format::~Format()
{
    //dtor
}
