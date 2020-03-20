#pragma once
#include <string>
#include <memory>
#include <map>
#include <functional>

#include "HotDrink.h"
#include "TeaFactory.h"
#include "CoffeeFactory.h"
using namespace std;

/*!
 * A factory stors 2 hot drink factories.
 *
 * 2 hot drink factories has their own make()
 * to create their own product.
 */
class DrinkFactory {
  map<string, unique_ptr<HotDrinkFactory>> hotFactories;
public:
  DrinkFactory()
  {
    hotFactories["coffee"] = make_unique<CoffeeFactory>();
    hotFactories["tea"] = make_unique<TeaFactory>();
  }

  unique_ptr<HotDrink> makeDrink(const string& name)
  {
    auto drink = hotFactories[name]->make();
    drink->prepare(200);
    return drink;
  }
};

/*!
 * Functional factory
 */
class DrinkWithVolumeFactory
{
  map<string, function<unique_ptr<HotDrink>()>> factories;
public:
  DrinkWithVolumeFactory()
  {
    factories["tea"] = [] {
      auto tea = make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };

    factories["coffee"] = [] {
      auto coffee = make_unique<Coffee>();
      coffee->prepare(200);
      return coffee;
    };
  }

  unique_ptr<HotDrink> makeDrink(const string& name)
  {
    return factories[name]();
  }
};

