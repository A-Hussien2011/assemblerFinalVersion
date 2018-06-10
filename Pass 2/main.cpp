#include <iostream>
#include "Pass2Controller.h"
using namespace std;

int main()
{
    Pass2Controller pass2 = Pass2Controller();
    pass2.generateIntermediateFile("Reader.txt");
    pass2.generateObjectCode();
}
