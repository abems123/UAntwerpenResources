//
// Created by Abdellah on 10/20/2025.
//

#include "Utils.h"

#include <algorithm>
#include <set>

string Utils::body_to_string(vector<string> body)
{
    string result = "`";

    for (auto it = body.begin(); it != body.end(); ++it)
    {
        result += *it;
        if (it != body.end() - 1) result += " ";
    }

    result += '`';

    return result;
}

string Utils::vector_to_string(vector<string> v)
{
    string result = "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        result += *it;
        if (it != v.end() - 1)
            result += ", ";
    }
    result += "]";

    return result;
}

string Utils::set_to_string(set<string> v)
{
    string result = "{";
    auto last = --v.end();
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        result += *it;
        if (it != last)
            result += ", ";
    }
    result += "}";

    return result;
}

string Utils::pairs_to_string(vector<pair<string, string>> v)
{
    string result = "{";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        result += "(" + it->first + ", " + it->second + ")";
        if (it != v.end() - 1) result += ", ";
    }
    result += "}";
    return result;
}
