#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "Person.h"

struct ChatRoom {
    vector<Person*> people;

    void broadcast(const string& origin, const string& message);

    void join(Person* p);

    void message(const string& origin, const string& who, const string& message)
    {
        auto target = std::find_if(begin(people), end(people),
            [&](const Person* p) { return p->name == who; });
        if (target != end(people)) {
            (*target)->receive(origin, message);
        }
    }
};
