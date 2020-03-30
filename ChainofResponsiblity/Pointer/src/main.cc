#include <iostream>
#include <string>

using namespace std;

struct Creature
{
    string name;
    int attack, defense;

    Creature(const string& name, const int attack, const int defense)
        :name(name), attack(attack), defense(defense)
    {}

    friend ostream& operator<<(ostream& os, const Creature& obj)
    {
        return os << "name:" << obj.name
            << " attack: " << obj.attack
            << " defense: " << obj.defense;
    }

};

class CreatureModifier
{
    CreatureModifier* next{nullptr};
protected:
    Creature& creature;
public:
    explicit CreatureModifier(Creature& creature)
        : creature(creature)
    {}
    virtual ~CreatureModifier() = default;

    void add(CreatureModifier* cm)
    {
        if (next)
            next->add(cm);
        else
            next = cm;
    }

    virtual void handle()
    {
        if (next)
            next->handle();
    }

};

class NoBonusesModifier : public CreatureModifier
{
public:
    explicit NoBonusesModifier(Creature& creature)
        : CreatureModifier(creature)
    {}

    void handle() override
    {
        // nothing
    }
};

class DoubleAttackModifier : public CreatureModifier
{
public:
    explicit DoubleAttackModifier(Creature& creature)
        : CreatureModifier(creature)
    {}

    void handle() override
    {
        creature.attack *= 2;
        CreatureModifier::handle();
    }
};

class IncreaseDefenseModifier : public CreatureModifier
{
public:
    explicit IncreaseDefenseModifier(Creature& creature)
        : CreatureModifier(creature)
    {}

    void handle() override
    {
        if (creature.attack <= 2)
            creature.defense += 1;
        CreatureModifier::handle();
    }
};

/*!
 * The chain is like:
 * xxxModifier::handle() -> baseModifier::handle() -> if(next) next->handle
 *
 * This is kind of old style of COR
 */
int main()
{
    Creature goblin{"Goblin", 1, 1};
    CreatureModifier root{goblin};
    DoubleAttackModifier r1{goblin};
    DoubleAttackModifier r1_2{goblin};
    IncreaseDefenseModifier r2{goblin};

    root.add(&r1);
    root.add(&r1_2);
    root.add(&r2);


    root.handle();

    cout << goblin << endl;

    getchar();

    return 0;
}
