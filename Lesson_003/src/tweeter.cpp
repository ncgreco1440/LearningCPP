#include "tweeter.hpp"

LCPP::Tweeter::Tweeter(std::string first, std::string last, int arbitrary,
  std::string twitterHandle):
  Person(first, last, arbitrary), twitterHnd(twitterHandle) {
    std::cout << "constructing Tweeter: " << this->getName() << "\n";
  }

LCPP::Tweeter::~Tweeter() {
  std::cout << "deconstructing Tweeter " << this->getName() << ": "
    << this->twitterHnd << "\n";
}