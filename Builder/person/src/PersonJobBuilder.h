#pragma once
#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase {
  typedef PersonJobBuilder Self;

public:
  explicit PersonJobBuilder(Person& person)
    :PersonBuilderBase{person}
  {}
  
  Self& at(std::string company) {
    person.company = company;
    return *this;
  }
  
  Self& is(std::string job) {
    person.job = job;
    return *this;
  }

  Self& earn(int salary) {
    person.salary = salary;
    return *this;
  }

};
