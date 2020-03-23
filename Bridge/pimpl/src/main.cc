#include "Person.h"


int main()
{
    std::string name = "kasakun";
    Person p = Person(name);

    p.greet();

    return 0;
}