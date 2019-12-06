#ifndef PERSON_H_
#define PERSON_H_

#include <string>
// For smart pointers
#include <memory>

#include "resource.hpp"

namespace LCPP {

  // Hard implementation of Person with dynamic memory allocation
  class Person {
    public:
    Person(): firstName(""), lastName("") {}
    Person(std::string const first, std::string const last): firstName(first), lastName(last) {}
    // If you write a destructor, you MUST write a copy constructor
    ~Person();
    // Here is a copy constructor
    Person(Person const& p);
    // Copy assignment
    Person& operator=(const Person& p);
    std::string GetName() const {
      return this->firstName + " " + this->lastName;
    }
    void AddResource();

    private:
    std::string firstName;
    std::string lastName;
    Resource* pResource;
  };

  class SmartPerson {
    public:
    SmartPerson(): firstName(""), lastName("") {}
    SmartPerson(std::string const first, std::string const last)
        : firstName(first), lastName(last) {}
    // no destructor necessary
    std::string GetName() const {
      return this->firstName + " " + this->lastName;
    }
    void AddResource();

    private:
    std::string firstName;
    std::string lastName;
    std::shared_ptr<Resource> pResource;
  };

  /**
   * Standard Library Smart Pointers
   *
   * std::unique_ptr
   *  - very low overhead
   *  - noncopyable
   *  - must use std::move()
   * std::shared_ptr
   *  - reference counted
   *    - inc and dec the reference count, when 0 call delete
   * std::weak_ptr
   *  - lets you see under the hood of an std::shared_ptr
   *  - you can see the refence count
   *
   * create these pointers via make_[ptr_type]<T>()
   * make_unique<Resource>();
   * make_shared<Resource>();
   * make_weak<Resource>();
   *
   */

} // namespace LCPP

#endif // PERSON_H_
