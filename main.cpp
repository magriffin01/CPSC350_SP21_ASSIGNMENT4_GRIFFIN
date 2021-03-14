#include <iostream>
#include "RPNCalc.h"

using namespace std;

int main(int argc, char **argv)
{
    RPNCalc *calc = new RPNCalc();
    calc->run();
    

    delete calc;
    return 0;
}