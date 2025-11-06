//
// Created by Abdellah on 10/20/2025.
//

#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <string>
#include <vector>

using namespace std;

class Production
{
    string head;
    vector<string> body;

public:
    [[nodiscard]] string getHead() const;
    [[nodiscard]] vector<string> getBody() const;

    void setHead(const string& head);
    void setBody(const vector<string>& body);

    bool isNullable() const;


};

#endif //PRODUCTION_H
