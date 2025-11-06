//
// Created by Abdellah on 10/20/2025.
//

#ifndef UTILS_H
#define UTILS_H
#include <set>
#include <string>
#include <vector>

using namespace std;

class Utils {

public:
    static string body_to_string(vector<string> body);
    static string vector_to_string(vector<string> v);
    static string set_to_string(set<string> v);
    static string pairs_to_string(vector<pair<string,string>> v);
};



#endif //UTILS_H
