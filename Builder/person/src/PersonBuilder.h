#pragma once
#include "Person.h"

class PersonLifeBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
protected:
  Person& person;
  //
  // We only expect its child to call the constructor
  explicit PersonBuilderBase(Person& person)
    :person{person}
  {
  }
public:
  operator Person() const {
    return std::move(person);
  }
  
  PersonLifeBuilder lives() const;
  PersonJobBuilder work() const;

};

class PersonBuilder: public PersonBuilderBase {
  Person p;
public:
  PersonBuilder(): PersonBuilderBase{p}
  {
  }
};
