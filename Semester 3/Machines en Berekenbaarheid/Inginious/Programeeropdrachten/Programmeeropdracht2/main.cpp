#include <iostream>
#include <fstream>
#include <iomanip>

#include "CFG.h"
#include "json.hpp"
using namespace std;

using json = nlohmann::json;

int main(){
    CFG cfg("../CFG.json");
    cfg.print();
    return 0;


    // inlezen uit file
    ifstream input("../input.json");

    json j;
    input >> j;
    // tonen op het scherm
    // cout << setw(4) << j << endl;

    // manueel aanmaken
    json j2;
    // j2["Variables"] = ["A","B"];
    cout << setw(4) << j["Variables"][0] << endl;
    return 0;
}