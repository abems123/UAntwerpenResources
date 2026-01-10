//
// Created by Abdellah on 10/27/2025.
//

#ifndef PDA_H
#define PDA_H
#include <string>
#include <vector>

#include "CFG.h"
#include "Transition.h"

using namespace std;

class PDA
{
    vector<string> states;
    vector<string> input_alphabet;
    vector<string> stack_alphabet;
    string start_state;
    string start_stack_symbol;
    vector<string> accepting_states;
    vector<Transition> transitions;

public:
    PDA(const string& json_file);
    void print();

    vector<string> generateVariables();
    void generateInitialProductions(vector<Production*>& productions);
    static string composeVariable(const string& from, const std::string& symbol, const std::string& to);
    void createProduction(const string& head, const string& body, vector<Production*>& productions);
    void generateLongProductions(vector<Production*>& productions);
    vector<Production*> generateProductions();
    CFG toCFG();
};


#endif //PDA_H
