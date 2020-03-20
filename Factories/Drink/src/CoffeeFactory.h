#pragma once
#include "HotDrinkFactory.h"

struct CoffeeFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() const override
  {
    return make_unique<Coffee>();
  }
};

