#include <iostream>

#include "resource.hpp"

LCPP::Resource::Resource(std::string n) : name(n) {
  std::cout << "constructing " << name << std::endl;
}

LCPP::Resource::~Resource(void) {
  std::cout << "destructing " << name << std::endl;
}
