#pragma once
#include <memory>
#include <iostream>
using namespace std;

struct HotDrink
{
  virtual  ~HotDrink() = default;

  virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
  void prepare(int volume)
  {
    cout << "Take a tea bag, boil water and pour " << volume << "ml water." << endl;
  }
};

struct Coffee : HotDrink
{
  void prepare(int volume)
  {
    cout << "Take some beans, boil water and pour " << volume << "ml water." << endl;
  }
};

