#ifndef METHODSTOBEPUTINCONTROLLER_H
#define METHODSTOBEPUTINCONTROLLER_H

using namespace std;

class MethodsToBePutInController
{
    public:
///Method 1 --> if symbol type is 'U' undefined yet then evaluate it first use the method in private section as well
void setSymbolType(string, string, int);

///method 2 --> evaluate object code of word/byte directives
///if operation == word/byte then object code is
string getWordObjectCode(string); ///--> same as elly bassant 7at3melo in converting a number to ascii
string getByteObjectCode(string);

///method 3 --> evaluate object code of literals
///if label == * then it is a literal, then get operation which will be name of literal and get its value
string getObjectCode(string);


///method 4 -->
///register to register handling (ahmed/bassam-> add another method in class format)
///In controller call class Register table to get register number

    private:
        LitTable literalTable;
        char evaluateType(string, string,int);

};

#endif // METHODSTOBEPUTINCONTROLLER_H
