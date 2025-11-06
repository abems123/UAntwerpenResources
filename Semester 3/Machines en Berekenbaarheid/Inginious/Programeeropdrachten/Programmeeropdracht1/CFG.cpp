//
// Created by Abdellah on 10/3/2025.
//

#include "CFG.h"

#include <iostream>

CFG::CFG()
{
    variables.emplace_back("BINDIGIT");
    variables.emplace_back("S");

    terminals.emplace_back("0");
    terminals.emplace_back("1");
    terminals.emplace_back("a");
    terminals.emplace_back("b");

    production p1;
    p1.variable = "BINDIGIT";
    p1.result = "0";

    production p2;
    p2.variable = "BINDIGIT";
    p2.result = "1";

    production p3;
    p3.variable = "S";
    p3.result = "";

    production p4;
    p4.variable = "S";
    p4.result = "a S b BINDIGIT";

    productions = {p1, p2, p3, p4};


    start_variable = 'S';
}

void CFG::print()
{
    cout << "V = {";
    for (int i = 0; i < variables.size(); i++)
    {
        cout << variables[i];
        if (i != variables.size() - 1)
            cout << ", ";
    }
    cout << "}" << endl;

    cout << "T = {";
    for (int i = 0; i < terminals.size(); i++)
    {
        cout << terminals[i];
        if (i != terminals.size() - 1)
            cout << ", ";
    }
    cout << "}" << endl;

    cout << "P = {" << endl;
    for (auto & [variable, result] : productions)
    {
        cout << "    " << variable << " -> " << '`' << result << '`' << endl;
    }
    cout << "}" << endl;

    cout << "S = " << start_variable << endl;
}
