#include <iostream>

#include "DrinkFactory.h"
using namespace std;


int main()
{
  DrinkFactory df;
  DrinkWithVolumeFactory dvf;

  auto drink1 = df.makeDrink("coffee");
  auto drink2 = dvf.makeDrink("tea");

  return 0;
}
