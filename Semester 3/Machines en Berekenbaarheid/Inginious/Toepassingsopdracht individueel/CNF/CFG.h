//
// Created by Abdellah on 10/3/2025.
//

#ifndef CFG_H
#define CFG_H
#include <set>
#include <string>
#include <vector>

#include "Production.h"


using namespace std;


class CFG {
    vector<string> variables;
    vector<string> terminals;
    vector<Production*> productions;
    string start_variable;

public:
    void sortProductions();
    CFG(const string& json_file);
    CFG();

    void print();

    void setNullableVariations(const vector<string>& nullables, const Production* production);
    void eliminateNullables(vector<string>& nullables);
    void eliminateEpProductions();
    bool hasUnitProduction(const string& head, vector<Production*>& productions);
    bool pairExists(const pair<string, string>& it, const vector<pair<string, string>>& pairs);
    bool isUnitProduction(Production* p);
    vector<Production*> getUnitProductions(const string& head);
    void findUnitPairs(vector<pair<string, string>>& pairs);
    bool productionExists(const string& head, const vector<string>& body) const;
    void createProduction(const string& head, const vector<string>& body);
    void replaceUnitProductions(const vector<pair<string, string>>& pairs);
    void removeUnitProductions();
    void eliminateUnitPairs();
    bool allTerminals(const vector<string>& vector);
    void deleteProduction(Production* production);
    void removeSymbols(const vector<string>& non_generating);
    void findGeneratingSymbols(vector<string>& generating_symbols, vector<string>& non_generating_symbols);
    void findReachableSymbols(vector<string>& reachable_symbols, vector<string>& non_reachable_symbols);
    void eliminateUselessSymbols();
    bool isTerminal(const string& basic_string);
    pair<string, bool> hasUniqueProduction(const string& a);
    void switchBodySymbol(Production* production, const string& basic_string, const string& string);
    void sortVariables();
    void replaceTerminals();
    string createTwoProduction(int number, const string& head, const vector<string>& body, vector<string>& new_variables);
    void cascadeProductions(const Production* production, const int number, vector<string>& new_variables);
    void breakBodies();
    void toCNF();

    vector<Production*> getProductions(const string& head) const;

    vector<string> getNullables(vector<string>& nullables) const;
    set<string> pairsWithRecursion(string current_head, set<string>& bodies);

    ~CFG()
    {
        for (const auto p : productions)
            delete p;
    }
};



#endif //CFG_H
