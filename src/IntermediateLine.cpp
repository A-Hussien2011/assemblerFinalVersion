//
// Created by Bassam on 6/9/2018.
//

#include "include/IntermediateLine.h"


IntermediateLine::IntermediateLine(string intermediateLine) {

    setIntermediateLine(intermediateLine);

    parse(intermediateLine);
}

void IntermediateLine::parse(string intermediateLine) {

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
    IntermediateLine::operation = operation;
}

const string &IntermediateLine::getOperand() const {
    return operand;
}

void IntermediateLine::setOperand(const string &operand) {
    IntermediateLine::operand = operand;
}

const string &IntermediateLine::getFormat() const {
    return format;
}

void IntermediateLine::setFormat(const string &format) {
    IntermediateLine::format = format;
}

const string &IntermediateLine::getIntermediateLine() const {
    return intermediateLine;
}

void IntermediateLine::setIntermediateLine(const string &intermediateLine) {
    IntermediateLine::intermediateLine = intermediateLine;
}

