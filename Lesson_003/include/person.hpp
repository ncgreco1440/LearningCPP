#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

/**
 * Use a custom namespace to prevent name collisions
 */
namespace LCPP {

  /**
   * A person with a first and last name.
   */
  class Person {
    public:
      Person(std::string first, std::string last, int arb);
      Person();
      ~Person();
      /**
       * Return the full first and last name of the person
       */
      std::string getName() const {
        return this->firstName + " " + this->lastName; 
      }
    private:
      std::string firstName;
      std::string lastName;
      int arbitrary;
  };

}

#endif // PERSON_H_