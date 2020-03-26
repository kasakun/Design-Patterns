#include <iostream>
using namespace std;

template <typename T> struct Property
{
    T value;
    Property(T value)
    {
        this->value = value;
    }

    operator T()
    {
        return value;
    }

    T operator=(T new_value)
    {
        cout << "Assignment!\n";
        return value = new_value;
    }
};

struct Creature
{
    Property<int> strength{10};
    Property<int> agility{10};
};

int main()
{
    Creature c;
    c.agility = 5;
}
