//
// Created by Abdellah on 10/20/2025.
//
#include "Production.h"

string Production::getHead() const
{
    return head;
}

vector<string> Production::getBody() const
{
    return body;
}

void Production::setHead(const string& head)
{
    this->head = head;
}

void Production::setBody(const vector<string>& body)
{
    this->body = body;
}

bool Production::isNullable() const
{
    return body.empty();
}
