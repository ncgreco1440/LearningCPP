#include "person.hpp"

LCPP::Person::~Person() {
  delete this->pResource;
}

void LCPP::Person::AddResource() {
  this->pResource = new Resource{"Resource for " + this->GetName()};
}

LCPP::Person::Person(LCPP::Person const &p) {
  this->pResource = new Resource(p.pResource->GetName());
}

/**
 * Note no check for self assignment is done here
 */
LCPP::Person &LCPP::Person::operator=(const LCPP::Person &p) {
  delete pResource;
  pResource = new Resource(p.pResource->GetName());
  return *this;
}

void LCPP::SmartPerson::AddResource() {
  this->pResource = std::make_shared<Resource>("Resource for " + this->GetName());
}
