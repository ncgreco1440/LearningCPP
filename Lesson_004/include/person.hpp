#ifndef PERSON_H_
#define PERSON_H_

#include <string>

namespace LCPP {

  class Person {
    public:
      Person(): firstName(""), lastName("") {}
      Person(std::string const first, std::string const last):
        firstName(first), lastName(last) {}
      std::string Name() const {
        return this->firstName + " " + this->lastName;
      }
    private:
      std::string firstName;
      std::string lastName;
  };

}

#endif // PERSON_H_
