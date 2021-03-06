#include "DisplacementController.h"
#include "OperandIdentifiers.h"
#include <algorithm>
#include <bitset>
#include <string>
#include "RegistersTable.h"
#include "Converters.h"

DisplacementController::DisplacementController() {
    converter = Converters();
    validBase = true;
}

void DisplacementController::setDispalcement(string address, string operation, string operand, string pc, string base, int type) {
    if (type == FORMAT_4) {
        setEflag(true);
        setBflag(false);
        setPCflag(false);
        displacement = bitset<20>(strtol(address.c_str(), NULL, 16)).to_string();
    } else if (type != NO_FORMAT){
        setEflag(false);
        if (type == FORMAT_3) {
            calculateDisp(address, pc, base);
            displacement = bitset<12>(strtol(displacement.c_str(), NULL, 16)).to_string();
        } else if (type == FORMAT_2) {
            string reg1 = "";
            reg1 += operand.at(0);
            string reg2 = "";
            reg2 += operand.at(2);

            string r1 = bitset<4>(registersTable.getRegisterNumber(reg1)).to_string();
            string r2 = bitset<4>(registersTable.getRegisterNumber(reg2)).to_string();
            displacement = r1+r2;
        }
    } else {
        displacement = "";
            setPCflag(false);
            setBflag(false);
            setEflag(false);
    }

}

void DisplacementController::calculateDisp(string address, string pc, string base) {
    int intAddress = converter.convertToDecimal(address);
    int intPc = converter.convertToDecimal(pc);
    int result = intAddress - intPc;
    if (result < 0) {
        result = result * -1;
        result = addBinary(convertToBin(result,12), "1");
    }
    if (result >= -2048 && result <= 2047) {
        setPCflag(true);
        setBflag(false);
        displacement = converter.convertToHexa(result);
    } else if (validBase) {
        int intBase = converter.convertToDecimal(base);
        result = intAddress - intBase;
        if (result < 0) {
        result = result * -1;
        result = addBinary(convertToBin(result,12), "1");
    }
        if (result >= 0 && result <= 4095){
            setPCflag(false);
            setBflag(true);
            displacement = converter.convertToHexa(result);
        }
        else {
            displacement = "";
            setPCflag(false);
            setBflag(false);
            setEflag(false);
        }
    }
}

int DisplacementController::addBinary(string a, string b)
{
    string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum

    // Travers both strings starting from last
    // characters
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;

        // Compute carry
        s /= 2;

        // Move to next digits
        i--; j--;
    }
    int value = strtol(result.c_str(), NULL, 2);
    return value;
}

string DisplacementController::convertToBin(int value, int bitsNumber) {
        string str;
        if (bitsNumber == 20) {
            str = bitset<20>(value).to_string();
        } else {
            str = bitset<12>(value).to_string();
        }

        int i;
        char s[bitsNumber + 1];
        for (i = 0; i < str.length(); i++) {
            if(str.at(i) == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
         s[i] = '\0';
        char* temp = &(s[0]);
        string s1 = string(temp);
        return s1;
    }

void DisplacementController::setValidBase(bool valid) {
    validBase = valid;
}

string DisplacementController::getDispalcement(){
    return displacement;
}

void DisplacementController::setPCflag(bool used){
    PCflag = used;
}

void DisplacementController::setBflag(bool used){
    Bflag = used;
}

void DisplacementController::setEflag(bool used){
    Eflag = used;
}

bool DisplacementController::getPCflag(){
    return PCflag;
}

bool DisplacementController::getBflag(){
    return Bflag;
}

void DisplacementController::setDirectDisplacement(string disp) {
    displacement = disp;
}
