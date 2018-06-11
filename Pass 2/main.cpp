#include <iostream>
#include "Pass2Controller.h"
using namespace std;

int main()
{
    Pass2Controller pass2 = Pass2Controller();
    bool errorFound = pass2.generateIntermediateFile("Reader.txt");
    if (!errorFound) {
        pass2.generateObjectCode();
        pass2.generateFinalFile("0000", "PROG");
    }
}
