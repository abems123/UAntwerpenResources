//
// Created by Abdellah on 10/27/2025.
//

#ifndef TRANSITION_H
#define TRANSITION_H
#include <string>
#include <vector>

using namespace std;

class Transition
{

public:
    Transition() = default;
    string current_state;
    string current_input;
    string current_stack_top;

    string new_state;
    vector<string> new_stack_top;

};


#endif //TRANSITION_H
