#include <iostream>
#include <fstream>
#include <iomanip>

#include "CFG.h"
#include "json.hpp"
using namespace std;

using json = nlohmann::json;

int main(){
    CFG cfg("../input-cnf1.json");
    cfg.toCNF();


    return 0;
}