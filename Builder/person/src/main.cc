#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonJobBuilder.h"
#include "PersonLifeBuilder.h"

int main() {
  Person p = Person::create()
    .lives().nameIs("kasakun").ageIs("13").livesAt("231 Bake Rd.")
    .work().is("Gamer").at("Play Company").earn(10e6);

  cout << p << endl;

  getchar();
  return 0;
}
