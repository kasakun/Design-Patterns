#include <iostream>
#include <vector>

using namespace std;

struct Creature
{
    int health, attack;

    Creature(int health, int attack)
        : health(health),attack(attack)
    {}
};

struct CardGame
{
    vector<Creature> creatures;

    CardGame(const vector<Creature>& creatures)
        : creatures(creatures)
    {}

    int combat(int index1, int index2)
    {
        Creature& c1 = creatures[index1];
        Creature& c2 = creatures[index2];
        hit(c1, c2);
        hit(c2, c1);

        if ((c1.health > 0 && c2.health > 0) ||
            (c1.health <= 0 && c2.health <= 0))
            return -1;
        else
            return c1.health > 0 ? index1:index2;
    }

    virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame: CardGame
{
    TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}
    virtual void hit(Creature& attacker, Creature& other) override
    {
        auto oldHealth = other.health;
        other.health -= attacker.attack;
        if (other.health > 0) other.health = oldHealth;
    }
};

struct PermanentCardDamageGame: CardGame
{
    PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    virtual void hit(Creature& attacker, Creature& other) override
    {
        other.health -= attacker.attack;
    }
};

int main()
{
    Creature c1{2,2};
    Creature c2{2,2};
    Creature c3{3,1};
    Creature c4{2,1};

    PermanentCardDamageGame game1({c3, c4});
    TemporaryCardDamageGame game2({c1, c2});

    cout << game2.combat(0, 1) << "| Expected: Both dies." << endl;
    cout << game1.combat(0, 1) << "| Expected: Both alive" << endl;
    cout << game1.combat(0, 1) << "| 0 is alive, 1 dies" << endl;
    return 0;
}
