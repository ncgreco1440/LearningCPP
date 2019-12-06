#include "tweeter.hpp"

LCPP::Tweeter::Tweeter(std::string first, std::string last, int arbitrary,
                       std::string twitterHandle)
    : Person(first, last, arbitrary), twitterHnd(twitterHandle) {
  std::cout << "constructing Tweeter: " << this->getName() << "\n";
}

LCPP::Tweeter::~Tweeter() {
  std::cout << "deconstructing " << this->getName() << "\n";
}

/**
 * To call base methods use the scope resolution operator ::
 */
std::string LCPP::Tweeter::getName() const {
  return this->twitterHnd + ": " + LCPP::Person::getName();
}