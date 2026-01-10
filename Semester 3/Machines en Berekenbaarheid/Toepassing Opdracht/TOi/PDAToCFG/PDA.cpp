//
// Created by Abdellah on 10/27/2025.
//

#include "PDA.h"

#include <bitset>

#include "json.hpp"
#include <fstream>
#include <iostream>
#include <utility>

#include "Utils.h"


PDA::PDA(const string& json_file)
{
    ifstream input(json_file);

    nlohmann::json j;
    input >> j;

    states = j["States"].get<vector<string>>();
    input_alphabet = j["Alphabet"].get<vector<string>>();
    stack_alphabet = j["StackAlphabet"].get<vector<string>>();
    start_state = j["StartState"].get<string>();
    start_stack_symbol = j["StartStack"].get<string>();

    for (const auto& t : j["Transitions"].items())
    {
        Transition transition;
        transition.current_state = t.value()["from"].get<string>();
        transition.current_input = t.value()["input"].get<string>();
        transition.current_stack_top = t.value()["stacktop"].get<string>();
        transition.new_state = t.value()["to"].get<string>();
        transition.new_stack_top = t.value()["replacement"].get<vector<string>>();
        transitions.push_back(transition);
    }
}

void PDA::print()
{
    cout << "States: " << Utils::vector_to_string(states) << endl;
    cout << "Alphabet: " << Utils::vector_to_string(input_alphabet) << endl;
    cout << "StackAlphabet: " << Utils::vector_to_string(stack_alphabet) << endl;
}

vector<string> PDA::generateVariables()
{
    vector<string> vars = {"S"};

    for (const auto& state_0 : states)
    {
        for (const auto& stack_0 : stack_alphabet)
        {
            for (const auto& state_1 : states)
            {
                vars.push_back("[" + state_0 + "," + stack_0 + "," + state_1 + "]");
            }
        }
    }
    return vars;
}

void PDA::generateInitialProductions(vector<Production*>& productions)
{
    for (const auto& state : states)
    {
        auto* production = new Production();
        production->setHead("S");
        production->setBody({composeVariable(start_state, start_stack_symbol, state)});
        productions.push_back(production);
    }
}

string PDA::composeVariable(const string& from, const std::string& symbol, const std::string& to)
{
    return "[" + from + "," + symbol + "," + to + "]";
}


void PDA::createProduction(const string& head, const string& body, vector<Production*>& productions)
{
    const auto p = new Production();
    p->setHead(head);
    p->setBody({body});
    productions.push_back(p);
}


void PDA::generateLongProductions(vector<Production*>& productions)
{
    // δ(q, a , X) = (r, Y1Y2...Yk)

    for (const auto& [q, a, X, r, Y] : transitions)
    {
        if (Y.empty())
        {
            auto production = new Production();
            production->setHead(composeVariable(q, X, r));
            production->setBody({a});
            productions.push_back(production);
        }
        else if (Y.size() == 1)
        {
            for (auto state : states)
            {
                string body = a + " " + composeVariable(r, Y.front(), state);
                createProduction(composeVariable(q, X, state), body, productions);
            }
        }
        else
        {
            for (const auto& state : states)
            {
                const int n = Y.size() - 1; // number of digits
                const int m = states.size(); // base

                for (int i = 0; i < pow(m, n); ++i)
                {
                    int x = i;
                    vector<int> digits(n);
                    for (int j = n - 1; j >= 0; --j)
                    {
                        digits[j] = x % m;
                        x /= m;
                    }

                    // for (const int d : digits)
                    //     cout << d;
                    // cout << '\n';

                    string body = a;
                    string first_state = r;
                    string last_state = states.front();
                    int j = 0;

                    for (const int& digit : digits)
                    {
                        last_state = states[digit];
                        body += " " + composeVariable(first_state, Y[j], last_state);
                        first_state = last_state;
                        j++;
                    }
                    body += " " + composeVariable(last_state, Y[j], state);
                    createProduction(composeVariable(q, X, state), body, productions);
                }
            }


            // What are the variables here?
            // By variables, I mean the things that change with each transition
            // So here we have three for loops, the first one is for the head.
            // The other two ones are for the body, since there are two places
            // where we must have all states
        }
    }
}

vector<Production*> PDA::generateProductions()
{
    vector<Production*> productions;

    generateInitialProductions(productions);

    generateLongProductions(productions);

    return productions;
}

CFG PDA::toCFG()
{
    CFG cfg;
    cfg.setVariables(generateVariables());
    cfg.setTerminals(input_alphabet);
    cfg.setProductions(generateProductions());
    cfg.setStartVariable("S");
    cfg.sortVariables();
    cfg.sortProductions();

    return cfg;
}
