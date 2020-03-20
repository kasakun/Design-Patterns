#include "PersonBuilder.h"
#include "PersonLifeBuilder.h"
#include "PersonJobBuilder.h"

PersonLifeBuilder PersonBuilderBase::lives() const {
  return PersonLifeBuilder{person};
}

PersonJobBuilder PersonBuilderBase::work() const {
  return PersonJobBuilder{person};
}

