//
// Created by Bassam on 6/9/2018.
//

#ifndef PASS_1_INTERMEDIATELINE_H
#define PASS_1_INTERMEDIATELINE_H

#include <string>

using namespace std;

class IntermediateLine {
public:

    static const int NO_FORMAT = -1;
    static const int FORMAT_TWO = 2;
    static const int FORMAT_THREE = 3;
    static const int FORMAT_FOUR = 4;

    explicit IntermediateLine(string intermediateLine);

    const string &getLabel() const;

    const string &getAddress() const;

    const string &getOperation() const;

    const string &getOperand() const;

    int getFormat() const;

    const string &getIntermediateLine() const;

    void setIntermediateLine(const string &intermediateLine);

private:

    const string REGEX_LINE_NUMBER = "(\\d+){1}";
    const string REGEX_ADDRESS = "([0-9A-Fa-f]{4}){1}";
    const string REGEX_LABEL = "([a-zA-Z][\\w]*){0,1}";
    const string REGEX_OPERATION = "([+]{0,1}[a-zA-Z]{1,5}){1}";
    const string REGEX_OPERAND = "([=@#]{0,1}[\\w,+\\-*/%']*){0,1}";

    const string REGEX_INTERMEDIATE_LINE = "^\\s*" + REGEX_LINE_NUMBER +
                                           "\\s+" + REGEX_ADDRESS +
                                           "\\s+" + REGEX_LABEL +
                                           "\\s+" + REGEX_OPERATION +
                                           "\\s+" + REGEX_OPERAND;

    string label;
    string address;
    string operation;
    string operand;
    int format;
    string intermediateLine;

    void setLabel(const string &label);

    void setAddress(const string &address);

    void setOperation(const string &operation);

    void setOperand(const string &operand);

    void setFormat(int format);

    void parse(string intermediateLine);

    string toUpper(string str);

};


#endif //PASS_1_INTERMEDIATELINE_H
