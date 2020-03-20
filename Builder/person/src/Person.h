#pragma once
#include<string>
#include <iostream>

class PersonBuilder;

class Person {
  std::string name, age, address;
  std::string job, company;
  int salary = 0;
  
  //
  // Limited to be called by builder only
  Person() {
    std::cout << "Person created" << std::endl;
  }

public:
  Person(Person&& person)
    :name{move(person.name)},
    age{move(person.age)},
    address{move(person.address)},
    job{move(person.job)},
    company{move(person.company)},
    salary{person.salary}
  {  
  }
  
  Person& operator =(Person&& other)
  {
    name = move(other.name);
    age = move(other.age);
    address = move(other.address);
    job = move(other.job);
    company = move(other.company);
    salary = other.salary;

    return *this;
  }

  ~Person() {
    std::cout << "Person destroyed" << std::endl;
  }
  
  static PersonBuilder create();
  
  friend std::ostream& operator<<(std::ostream& os, Person& p) {
    return os
      << "Name is " << p.name << ", "
      << "age is " << p.age << ", "
      << "lives at " << p.address << ", "
      << "works as " << p.job << ", "
      << "at " << p.company << ", "
      << "earning is " << p.salary;
  }

  friend class PersonBuilder;
  friend class PersonJobBuilder;
  friend class PersonLifeBuilder;
};
