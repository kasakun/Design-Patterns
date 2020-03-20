#pragma once
#include "PersonBuilder.h"

class PersonLifeBuilder: public PersonBuilderBase {
  typedef PersonLifeBuilder Self;
public:
  explicit PersonLifeBuilder(Person& person)
    :PersonBuilderBase{person}
  {
  }

  Self& nameIs(std::string name) {
    person.name = name; 
    return *this;
  }

  Self& ageIs(std::string age) {
    person.age = age; 
    return *this;
  }

  Self& livesAt(std::string address) {
    person.address = address; 
    return *this;
  }
};

