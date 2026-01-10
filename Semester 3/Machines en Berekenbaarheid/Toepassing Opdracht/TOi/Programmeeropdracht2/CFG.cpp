//
// Created by Abdellah on 10/3/2025.
//

#include "CFG.h"

#include <iostream>
#include "json.hpp"
#include <fstream>

CFG::CFG(const string& json_file)
{
    ifstream input(json_file);

    nlohmann::json j;
    input >> j;

    variables = j["Variables"].get<vector<string>>();
    std::sort(variables.begin(), variables.end());

    terminals = j["Terminals"].get<vector<string>>();
    std::sort(terminals.begin(), terminals.end());

    for (auto p : j["Productions"])
    {
        production new_production;
        new_production.head = p["head"];
        new_production.body = p["body"].get<vector<string>>();
        productions.push_back(new_production);
    }
    std::sort(productions.begin(), productions.end(), [](const production& a, const production& b) {return a.head < b.head || a.body.empty();});

    start_variable = j["Start"].get<string>().front();
}

CFG::CFG()
{
    variables.emplace_back("BINDIGIT");
    variables.emplace_back("S");

    terminals.emplace_back("0");
    terminals.emplace_back("1");
    terminals.emplace_back("a");
    terminals.emplace_back("b");

    production p1;
    p1.head = "BINDIGIT";
    p1.body = {"0"};

    production p2;
    p2.head = "BINDIGIT";
    p2.body = {"1"};

    production p3;
    p3.head = "S";
    p3.body = {""};

    production p4;
    p4.head = "S";
    p4.body = {"a", "S"" b BINDIGIT"};

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
    for (auto& p : productions)
    {
        auto variable = p.head;
        auto result = p.body;

        cout << "    " << variable << " -> " << '`';

        for (auto r : result)
        {
            cout << r;
            if (r != result.back()) cout << " ";
        }

        cout << '`' << endl;
    }
    cout << "}" << endl;

    cout << "S = " << start_variable << endl;
}
