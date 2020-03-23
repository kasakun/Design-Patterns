#include "Person.h"
#include <iostream>

struct Person::PersonImpl
{
  void greet(Person* p);
};

void Person::PersonImpl::greet(Person* p)
{
  std::cout << "hello " << p->name << std::endl;
}

Person::Person(std::string& name)
  : name(name), impl(new PersonImpl)
{
}

Person::~Person()
{
  delete impl;
}

void Person::greet()
{
  impl->greet(this);
}