#include <iostream>

#include "PDA.h"

int main()
{
    PDA pda("../input-pda2cfg1.json");
    pda.toCFG().print();
}
