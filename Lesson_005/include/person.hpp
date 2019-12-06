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
    virtual ~Person();
    /**
     * Return the full first and last name of the person
     * note on virtual, in the even a pointer to Person is created that
     * actually points to a derived class any method marked "virtual"
     * will invoke the derived version of the method. This includes the
     * destructor.
     *
     * A good practice is to wait until you must declare at least 1
     * method "virtual", and then immediate declare your base
     * destructor as "virtual" so that the destructor of the
     * derived class is run.
     */
    virtual std::string getName() const {
      return this->firstName + " " + this->lastName;
    }

    virtual int getNumber() const {
      return this->arbitrary;
    }
    /**
     * Private data members are inaccessible even to derived classes
     * making these members "protected" instead of "private" *would*
     * allow a derived class to leverage these data members directly,
     * but a better practice would be to leverage any public methods
     * instead.
     */
    private:
    std::string firstName;
    std::string lastName;
    int arbitrary;
  };

} // namespace LCPP

#endif // PERSON_H_