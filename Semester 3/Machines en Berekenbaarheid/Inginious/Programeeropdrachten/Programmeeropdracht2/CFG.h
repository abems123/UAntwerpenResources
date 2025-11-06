//
// Created by Abdellah on 10/3/2025.
//

#ifndef CFG_H
#define CFG_H
#include <string>
#include <vector>


using namespace std;
typedef struct
{
    string head;
    vector<string> body;
} production;

class CFG {
    vector<string> variables;
    vector<string> terminals;
    vector<production> productions;
    char start_variable;

public:
    CFG(const string& json_file);
    CFG();

    void print();
};



#endif //CFG_H
