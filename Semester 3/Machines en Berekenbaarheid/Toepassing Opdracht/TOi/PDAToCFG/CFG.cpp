//
// Created by Abdellah on 10/3/2025.
//

#include "CFG.h"

#include <iostream>
#include "json.hpp"
#include <fstream>
#include <set>

#include "PDA.h"
#include "Utils.h"


void CFG::sortProductions()
{
    sort(productions.begin(), productions.end(), [](const Production* a, const Production* b)
    {
        if (a->getHead() != b->getHead())
        {
            return a->getHead() + " -> " + Utils::body_to_string(a->getBody()) < b->getHead() + " -> " +
                Utils::body_to_string(b->getBody());
        }
        return a->getBody() < b->getBody();
    });
}

vector<string> CFG::getVariables() const
{
    return variables;
}

void CFG::setVariables(const vector<string>& variables)
{
    this->variables = variables;
}

vector<string> CFG::getTerminals() const
{
    return terminals;
}

void CFG::setTerminals(const vector<string>& terminals)
{
    this->terminals = terminals;
}

vector<Production*> CFG::getProductions1() const
{
    return productions;
}

void CFG::setProductions(const vector<Production*>& productions)
{
    this->productions = productions;
}

string CFG::getStartVariable() const
{
    return start_variable;
}

void CFG::setStartVariable(const string& start_variable)
{
    this->start_variable = start_variable;
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
        auto variable = p->getHead();
        auto result = p->getBody();

        cout << "  " << variable << " -> " << Utils::body_to_string(result) << endl;
    }
    cout << "}" << endl;

    cout << "S = " << start_variable << endl;
}

void CFG::setNullableVariations(const vector<string>& nullables, const Production* production)
{
    // The indexes of the nullables in production
    vector<int> indexes;
    for (int i = 0, n = production->getBody().size(); i < n; i++)
    {
        if (find(nullables.begin(), nullables.end(), production->getBody()[i]) != nullables.end())
            indexes.push_back(i);
    }

    if (indexes.size() <= 0 || production->getBody().size() <= 1)
        return;

    const int n = indexes.size();

    // Use the binary form to loop through all possible combinations of variables
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        vector<string> body(production->getBody());
        for (int bit = 0; bit < n; ++bit)
        {
            if (mask & (1 << bit))
            {
                // if bit 'bit' is set
                body[indexes[bit]] = "";
            }
        }

        // Remove the empty symbols in body and the new productions with the new variations
        body.erase(remove(body.begin(), body.end(), ""), body.end());
        auto p = new Production();
        p->setHead(production->getHead());
        p->setBody(body);
        this->productions.push_back(p);
    }
}


void CFG::eliminateNullables(vector<string>& nullables)
{
    for (auto& v : variables)
    {
        for (const auto p : getProductions(v))
        {
            if (p->getBody().size() == 0)
            {
                deleteProduction(p);
                continue;
            }

            setNullableVariations(nullables, p);
        }
    }

    sortProductions();
}

void CFG::eliminateEpProductions()
{
    const int original = productions.size();

    vector<string> nullables;
    getNullables(nullables);

    sort(nullables.begin(), nullables.end());

    cout << "  Nullables are " << Utils::vector_to_string(nullables) << endl;

    eliminateNullables(nullables);

    const int created = productions.size();
    cout << "  Created " << created << " productions, original had " << original << endl << endl;

    print();
}

bool CFG::hasUnitProduction(const string& head, vector<Production*>& productions)
{
    bool hasUnitProduction = false;

    for (auto p : getProductions(head))
    {
        if (p->getBody().size() == 1 && find(variables.begin(), variables.end(), p->getBody().front()) != variables.
            end())
        {
            productions.push_back(p);
            hasUnitProduction = true;
        }
    }
    return hasUnitProduction;
}


bool CFG::pairExists(const pair<string, string>& it, const vector<pair<string, string>>& pairs)
{
    for (auto p : pairs)
    {
        if (p.first == it.first && p.second == it.second)
            return true;
    }
    return false;
}

bool CFG::isUnitProduction(Production* p)
{
    return p->getBody().size() == 1 && find(variables.begin(), variables.end(), p->getBody().front()) != variables.
        end();
}

vector<Production*> CFG::getUnitProductions(const string& head)
{
    vector<Production*> result;
    for (auto p : getProductions(head))
    {
        if (isUnitProduction(p))
        {
            result.push_back(p);
        }
    }
    return result;
}

void CFG::findUnitPairs(vector<pair<string, string>>& pairs)
{
    int unit_productions = 0;

    // Basis
    vector<pair<string, string>> basis_pairs;
    for (const auto v : variables)
    {
        unit_productions += getUnitProductions(v).size();
        pair<string, string> p;
        p.first = v;
        p.second = v;
        basis_pairs.push_back(p);
    }
    pairs.insert(pairs.end(), basis_pairs.begin(), basis_pairs.end());

    for (const auto basis_pair : basis_pairs)
    {
        set<string> bodies;
        pairsWithRecursion(basis_pair.second, bodies);
        for (const auto b : bodies)
        {
            pair<string, string> p;
            p.first = basis_pair.first;
            p.second = b;
            pairs.push_back(p);
        }
    }
}

bool CFG::productionExists(const string& head, const vector<string>& body) const
{
    for (auto p : productions)
    {
        if (p->getHead() == head && p->getBody() == body)
        {
            return true;
        }
    }
    return false;
}

void CFG::createProduction(const string& head, const vector<string>& body)
{
    if (!productionExists(head, body))
    {
        const auto p = new Production();
        p->setHead(head);
        p->setBody(body);
        this->productions.push_back(p);
    }
}

void CFG::replaceUnitProductions(const vector<pair<string, string>>& pairs)
{
    for (auto pair_0 : pairs)
    {
        if (pair_0.first == pair_0.second)
            continue;

        for (const auto production : getProductions(pair_0.second))
        {
            if (!isUnitProduction(production))
                createProduction(pair_0.first, production->getBody());
        }
    }
}

void CFG::removeUnitProductions()
{
    for (auto v : variables)
        for (auto p : getProductions(v))
            if (isUnitProduction(p))
            {
                deleteProduction(p);
            }
}


void CFG::eliminateUnitPairs()
{
    vector<Production*> unit_productions;
    vector<pair<string, string>> unit_pairs;
    findUnitPairs(unit_pairs);

    // Getting unit productions
    for (auto v : variables)
    {
        auto up = getUnitProductions(v);
        unit_productions.insert(unit_productions.end(), up.begin(), up.end());
    }

    sort(unit_pairs.begin(), unit_pairs.end(), [&](const pair<string, string>& p1, const pair<string, string>& p2)
    {
        return "(" + p1.first + ", " + p1.second + ")" < "(" + p2.first + ", " + p2.second + ")";
    });
    cout << "  Found " << unit_productions.size() << " unit productions" << endl;
    cout << "  Unit pairs: " << Utils::pairs_to_string(unit_pairs) << endl;

    int productions_before = productions.size();
    replaceUnitProductions(unit_pairs);
    removeUnitProductions();
    int productions_after = productions.size();

    cout << "  Created " << productions_after << " new productions, original had " << productions_before << endl <<
        endl;

    sortProductions();
    print();
}

bool CFG::allTerminals(const vector<string>& vector)
{
    for (auto s : vector)
        if (find(variables.begin(), variables.end(), s) != variables.end())
            return false;

    return true;
}

void CFG::deleteProduction(Production* production)
{
    delete production;
    productions.erase(remove(productions.begin(), productions.end(), production));
}

void CFG::removeSymbols(const vector<string>& symbols)
{
    // Removing all productions with non-generating variables in head or body
    for (auto it = productions.begin(); it != productions.end(); ++it)
    {
        if (find(symbols.begin(), symbols.end(), (*it)->getHead()) != symbols.end())
        {
            deleteProduction(*it);
            --it;
            continue;
        }
        for (auto s : (*it)->getBody())
        {
            if (find(symbols.begin(), symbols.end(), s) != symbols.end())
            {
                deleteProduction(*it);
                --it;
                break;
            }
        }
    }

    // Removing non-generating variables from the vector of variables
    for (auto v : symbols)
        variables.erase(remove(variables.begin(), variables.end(), v), variables.end());
}

void CFG::findGeneratingSymbols(vector<string>& generating_symbols, vector<string>& non_generating_symbols)
{
    // Getting all generating symbols which have a production with a body consisting only from terminals
    for (const auto production : productions)
    {
        if (allTerminals(production->getBody()) && find(generating_symbols.begin(), generating_symbols.end(),
                                                        production->getHead()) == generating_symbols.end())
            generating_symbols.push_back(production->getHead());
    }

    // Getting the generating symbols that can generate a string consisting of only terminals in more than one step
    for (const auto production : productions)
    {
        bool all_generating = true;
        for (auto b : production->getBody())
        {
            if (find(generating_symbols.begin(), generating_symbols.end(), b) == generating_symbols.end())
            {
                all_generating = false;
                break;
            }
        }
        if (all_generating && find(generating_symbols.begin(), generating_symbols.end(),
                                   production->getHead()) == generating_symbols.end())
        {
            generating_symbols.push_back(production->getHead());
        }
    }
    // Getting all non-generating symbols
    for (auto v : variables)
        if (find(generating_symbols.begin(), generating_symbols.end(), v) == generating_symbols.end())
            non_generating_symbols.push_back(v);

    sort(generating_symbols.begin(), generating_symbols.end());
}

void CFG::findReachableSymbols(vector<string>& reachable_symbols, vector<string>& non_reachable_symbols)
{
    // Start variable is always reachable
    // Each symbol in alpha for all (S -> alpha) is reachable
    // For each reachable variable A, for all productions (A -> alpha), all elements of alpha are reachable
    for (const auto p : getProductions(start_variable))
        for (auto s : p->getBody())
            if (find(reachable_symbols.begin(), reachable_symbols.end(), s) == reachable_symbols.end())
                reachable_symbols.push_back(s);

    for (auto it = reachable_symbols.begin(); it != reachable_symbols.end(); ++it)
    {
        for (const auto production : getProductions(*it))
        {
            for (auto s : production->getBody())
            {
                if (find(reachable_symbols.begin(), reachable_symbols.end(), s) == reachable_symbols.end())
                {
                    reachable_symbols.push_back(s);
                    it = reachable_symbols.begin() - 1;
                }
            }
        }
    }

    // Getting all non-generating symbols
    for (auto v : variables)
        if (find(reachable_symbols.begin(), reachable_symbols.end(), v) == reachable_symbols.end())
            non_reachable_symbols.push_back(v);


    sort(reachable_symbols.begin(), reachable_symbols.end());
}


void CFG::eliminateUselessSymbols()
{
    int productions_before = productions.size();
    int variables_before = variables.size();
    int terminals_before = terminals.size();

    vector<string> generating_symbols(terminals);
    vector<string> non_generating_symbols;

    findGeneratingSymbols(generating_symbols, non_generating_symbols);
    removeSymbols(non_generating_symbols);
    cout << "  Generating symbols: " << Utils::vector_to_string(generating_symbols) << endl;

    // cout << "  Non-Generating symbols: " << Utils::vector_to_string(non_generating_symbols) << endl;

    vector<string> reachable_symbols = {start_variable};
    vector<string> non_reachable_symbols;

    findReachableSymbols(reachable_symbols, non_reachable_symbols);
    removeSymbols(non_reachable_symbols);
    cout << "  Reachable symbols: " << Utils::vector_to_string(reachable_symbols) << endl;

    vector<string> useful_symbols;
    std::set_intersection(generating_symbols.begin(), generating_symbols.end(),
                          reachable_symbols.begin(), reachable_symbols.end(),
                          std::back_inserter(useful_symbols));

    cout << "  Useful symbols: " << Utils::vector_to_string(useful_symbols) << endl;

    int productions_after = productions.size();
    int variables_after = variables.size();
    int terminals_after = terminals.size();

    cout << "  Removed " << variables_before - variables_after << " variables, " << terminals_before - terminals_after
        << " terminals and " << productions_before - productions_after << " productions" << endl << endl;

    print();
}

bool CFG::isTerminal(const string& basic_string)
{
    return find(terminals.begin(), terminals.end(), basic_string) != terminals.end();
}

pair<string, bool> CFG::hasUniqueProduction(const string& a) const
{
    // By unique production here I mean this kind of productions (A -> a) where 'A' is a variable and 'a' is a terminal
    for (auto production : productions)
    {
        if (production->getBody().size() == 1 && production->getBody().front() == a)
            return {production->getHead(), true};
    }
    return {"", false};
}

void CFG::switchBodySymbol(Production* production, const string& old_symbol, const string& new_symbol)
{
    auto old_body = production->getBody();
    vector<string> new_body(old_body);

    for (int i = 0, n = old_body.size(); i < n; i++)
    {
        if (old_body[i] == old_symbol)
            new_body[i] = new_symbol;
    }
    production->setBody(new_body);
}

void CFG::sortVariables()
{
    sort(variables.begin(), variables.end());
}

void CFG::replaceTerminals()
{
    const int original_productions = productions.size();

    vector<string> new_variables;
    for (const auto& production : productions)
    {
        for (auto& s : production->getBody())
        {
            if (isTerminal(s))
            {
                if (!hasUniqueProduction(s).second)
                {
                    string new_variable = "_" + s;
                    createProduction(new_variable, {s});
                    switchBodySymbol(production, s, new_variable);
                    new_variables.push_back(new_variable);
                }
                else if (production->getBody().size() > 1)
                {
                    switchBodySymbol(production, s, hasUniqueProduction(s).first);
                }
            }
        }
    }
    const int new_productions = productions.size();

    variables.insert(variables.end(), new_variables.begin(), new_variables.end());
    cout << "  Added " << new_variables.size() << " new variables: " << Utils::vector_to_string(new_variables) << endl;
    cout << "  Created " << new_productions << " new productions, original had " << original_productions << endl <<
        endl;


    sortVariables();
    sortProductions();
    print();
}

void CFG::cascadeProductions(const Production* production, const int number, vector<string>& new_variables)
{
    // Make a new production with a new variable and with all symbols except the first one as body
    // Do the same to that production if its length >= 3
    createTwoProduction(number, production->getHead(), production->getBody(), new_variables);
}

string CFG::createTwoProduction(const int number, const string& head, const vector<string>& body,
                                vector<string>& new_variables)
{
    const auto new_production = new Production();
    string new_name = head + "_" + to_string(number);


    if (body.size() <= 2)
    {
        new_production->setHead(new_name);
        new_production->setBody(body);
        productions.push_back(new_production);
        new_variables.push_back(new_name);
        return new_name;
    }

    new_production->setHead(head);

    vector<string> new_body;
    const vector<string> rest_body(body.begin() + 1, body.end());
    new_body.push_back(body.front());
    new_body.push_back(createTwoProduction(number + 1, head, rest_body, new_variables));
    new_production->setBody(new_body);
    productions.push_back(new_production);

    return new_name;
}

void CFG::breakBodies()
{
    vector<string> new_variables;
    int broken_bodies = 0;

    for (auto v : variables)
    {
        int number = 1;
        for (const auto production : getProductions(v))
        {
            if (production->getBody().size() >= 3)
            {
                cascadeProductions(production, number, new_variables);
                deleteProduction(production);
                number++;
                broken_bodies++;
            }
        }
    }
    variables.insert(variables.end(), new_variables.begin(), new_variables.end());
    cout << endl << " >> Broke " << broken_bodies << " bodies, added " << new_variables.size() << " new variables" <<
        endl;
    cout << ">>> Result CFG:" << endl << endl;
    sortProductions();
    sortVariables();
    print();
}

void CFG::toCNF()
{
    cout << "Original CFG:" << endl << endl;
    print();
    cout << endl << "-------------------------------------" << endl << endl;

    // 1. Eliminate epsilon productions
    cout << " >> Eliminating epsilon productions" << endl;
    eliminateEpProductions();

    // 2. Eliminate unit pairs
    cout << endl << " >> Eliminating unit pairs" << endl;
    eliminateUnitPairs();

    // 3. Eliminate useless symbols
    cout << endl << " >> Eliminating useless symbols" << endl;
    eliminateUselessSymbols();

    // 4. Replace terminals in bad bodies
    cout << endl << " >> Replacing terminals in bad bodies" << endl;
    replaceTerminals();

    // 5. Break bodies of length 3 or more
    breakBodies();
}

vector<Production*> CFG::getProductions(const string& head) const
{
    vector<Production*> result;

    for (auto p : productions)
    {
        if (p->getHead() == head)
            result.push_back(p);
    }

    return result;
}

vector<string> CFG::getNullables(vector<string>& nullables) const
{
    // base case
    for (auto& v : variables)
    {
        for (const auto& p : getProductions(v))
        {
            if (p->isNullable())
            {
                nullables.push_back(p->getHead());
                break;
            }
        }
    }

    // induction
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (auto& v : variables)
        {
            if (find(nullables.begin(), nullables.end(), v) != nullables.end())
                continue;

            for (const auto& p : getProductions(v))
            {
                const auto body = p->getBody();
                if (std::all_of(body.begin(), body.end(), [&](const std::string& s)
                {
                    return std::find(nullables.begin(), nullables.end(), s) != nullables.end();
                }))
                {
                    nullables.push_back(v);
                    changed = true;
                    break;
                }
            }
        }
    }
    return nullables;
}

set<string> CFG::pairsWithRecursion(string current_head, set<string>& bodies)
{
    vector<Production*> unit_productions;

    if (hasUnitProduction(current_head, unit_productions))
    {
        for (auto p : unit_productions)
        {
            bodies.insert(p->getBody().front());
            auto recursive_bodies = pairsWithRecursion(p->getBody().front(), bodies);
            bodies.insert(recursive_bodies.begin(), recursive_bodies.end());
        }
    }
    return bodies;
}
