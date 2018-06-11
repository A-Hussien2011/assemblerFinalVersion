#include <iostream>
#include "include/IntermediateLine.h"

using namespace std;

int main() {
    IntermediateLine *intermediateLine = new IntermediateLine("2         0000                LDA            ALPHA     ");

    cout << "Address: " << intermediateLine->getAddress() << endl;
    cout << "Label: " << intermediateLine->getLabel() << endl;
    cout << "Operation: " << intermediateLine->getOperation() << endl;
    cout << "Operand: " << intermediateLine->getOperand() << endl;
    cout << "Format: " << intermediateLine->getFormat() << endl;

}
