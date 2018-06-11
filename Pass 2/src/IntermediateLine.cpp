//
// Created by Bassam on 6/9/2018.
//

#include <regex>
#include <iostream>
#include "../include/IntermediateLine.h"
#include "../include/DirectiveTable.h"
#include "../include/OperationTable.h"


IntermediateLine::IntermediateLine(string intermediateLine) {

    setIntermediateLine(intermediateLine);

}

void IntermediateLine::parse(string intermediateLine) {

    cmatch matcher;
    regex intermediateLineRegex(REGEX_INTERMEDIATE_LINE);
    regex_search(intermediateLine.c_str(), matcher, intermediateLineRegex);

    DirectiveTable *directiveTable = DirectiveTable::getInstance();

    //Checks if contains a directive only
    if (directiveTable->contains(matcher.str(4))) {
        setFormat(NO_FORMAT);
        IntermediateLine::operation = matcher.str(4);
    } else {
        setOperation(matcher.str(4));
    }

    setAddress(matcher.str(2));
    setLabel(matcher.str(3));
    setOperand(matcher.str(5));

}

const string &IntermediateLine::getAddress() const {
    return address;
}

void IntermediateLine::setAddress(const string &address) {
    IntermediateLine::address = address;
}

const string &IntermediateLine::getOperation() const {
    return operation;
}

void IntermediateLine::setOperation(const string &operation) {
    string operationReduced;
    OperationTable *operationTable = OperationTable::getInstance();

    int plusSignPosition = operation.find('+');
    if (plusSignPosition < 0) {
        if (operationTable->getFormat(toUpper(operation)) == 3) {
            setFormat(FORMAT_THREE);
        } else {
            setFormat(FORMAT_TWO);
        }
        operationReduced = operation;
    } else {
        setFormat(FORMAT_FOUR);
        operationReduced = operation.substr(1, operation.length());
    }

    IntermediateLine::operation = operationReduced;
}

const string &IntermediateLine::getOperand() const {
    return operand;
}

void IntermediateLine::setOperand(const string &operand) {
    IntermediateLine::operand = operand;
}

int IntermediateLine::getFormat() const {
    return format;
}

void IntermediateLine::setFormat(int format) {
    IntermediateLine::format = format;
}

const string &IntermediateLine::getIntermediateLine() const {
    return intermediateLine;
}

void IntermediateLine::setIntermediateLine(const string &intermediateLine) {
    IntermediateLine::intermediateLine = intermediateLine;
    parse(intermediateLine);
}

const string &IntermediateLine::getLabel() const {
    return label;
}

void IntermediateLine::setLabel(const string &label) {
    IntermediateLine::label = label;
}

string IntermediateLine::toUpper(string str) {
    for (auto &c: str) c = static_cast<char>(toupper(c));
    return str;
}

