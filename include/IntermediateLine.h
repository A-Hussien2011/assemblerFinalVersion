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

    const string &getAddress() const;

    const string &getOperation() const;

    const string &getOperand() const;

    const string &getFormat() const;

    const string &getIntermediateLine() const;

private:
    string address;
    string operation;
    string operand;
    string format;
    string intermediateLine;

    void setAddress(const string &address);

    void setOperation(const string &operation);

    void setOperand(const string &operand);

    void setFormat(const string &format);

    void setIntermediateLine(const string &intermediateLine);

    void parse(string intermediateLine);
};


#endif //PASS_1_INTERMEDIATELINE_H
