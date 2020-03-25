
#include <iostream>
#include <string>

struct Coffee {
    virtual double getCost() = 0;
    virtual std::string getIngredients() = 0;

    friend std::ostream& operator<<(std::ostream& os, Coffee& coffee)
    {
        return os << "Cost: " << coffee.getCost() << "; Ingredients: "
            << coffee.getIngredients() << std::endl;
    }
};

struct SimpleCoffee : public Coffee
{
    virtual double getCost() { return 1.0; }

    virtual std::string getIngredients() { return "Coffee"; }
};

struct MilkDecorator : Coffee
{
    MilkDecorator (Coffee *basicCoffee)
        : basicCoffee(basicCoffee)
    {
    }

    virtual double getCost()
    {
        return basicCoffee->getCost() + 0.5;
    }

    virtual std::string getIngredients() {
        return basicCoffee->getIngredients() + ", " + "Milk";
    }
private:
    Coffee *basicCoffee;
};

struct WhipDecorator : Coffee
{
    WhipDecorator (Coffee *basicCoffee)
        : basicCoffee(basicCoffee)
    {
    }

    virtual double getCost()
    {
        return basicCoffee->getCost() + 0.7;
    }

    virtual std::string getIngredients()
    {
        return basicCoffee->getIngredients() + ", " + "Whip";
    }
private:
    Coffee *basicCoffee;
};

int main()
{
    SimpleCoffee s;
    std::cout << s;

    MilkDecorator m(&s);
    std::cout << m;

    WhipDecorator w(&s);
    std::cout << w;

    MilkDecorator m2(&w);
    std::cout << m2;
}