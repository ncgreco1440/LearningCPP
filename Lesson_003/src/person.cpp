#include "person.hpp"

LCPP::Person::Person(std::string first, std::string last, int arb):
  firstName(first), lastName(last), arbitrary(arb) {
    std::cout << "constructing Person...\n";
  }

LCPP::Person::Person(): firstName(""), lastName(""), arbitrary(0) {}

LCPP::Person::~Person() {
  std::cout << "deconstructing Person " << this->getName() << "...\n";
}