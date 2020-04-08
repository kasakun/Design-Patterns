#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Rats attack like swarm, therefore the attack of a rat equals the attack of
 * the total rats.
 *
 * When a rat create, game will iterate other rats and let attack += 1
 * Each rat will notify the sender(new rat) to add 1 to its attack
 */

struct IRat {
    virtual void rat_enters(IRat* sender) = 0;
    virtual void rat_dies(IRat* sender) = 0;
    virtual void notify(IRat* target) = 0;
};

struct Game {
    vector<IRat*> rats;
    virtual void fire_rat_enters(IRat* sender)
    {
        for (auto rat : rats)
            rat->rat_enters(sender);
    }
    virtual void fire_rat_dies(IRat* sender)
    {
        for (auto rat : rats)
            rat->rat_dies(sender);
    }
    virtual void fire_notify(IRat* target)
    {
        for (auto rat : rats)
            rat->notify(target);
    }
};

struct Rat : IRat {
    Game& game;
    int attack { 1 };

    Rat(Game& game)
        : game(game)
    {
        game.rats.push_back(this);
        game.fire_rat_enters(this);
    }

    ~Rat()
    {
        game.fire_rat_dies(this);
        game.rats.erase(std::remove(game.rats.begin(), game.rats.end(), this));
    }

    virtual void rat_enters(IRat* sender) override
    {
        if (sender != this) {
            ++attack;
            game.fire_notify(sender);
        }
    }

    virtual void rat_dies(IRat* sender) override { --attack; }

    virtual void notify(IRat* target) override
    {
        if (target == this)
            ++attack;
    }
};

int main()
{
    Game game;
    Rat rat1(game);
    Rat rat2(game);
    Rat rat3(game);

    {
        // rat4 dies when come out the scope
        Rat rat4(game);
        cout << rat1.attack << endl;

    }
    cout << rat1.attack << endl;

    return 0;
}
