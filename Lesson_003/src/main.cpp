#include <iostream>
#include <vector>

#include "person.hpp"
#include "tweeter.hpp"
#include "status.hpp"

/**
 * Just practicing the use of typedef
 * These are arguably unnecessary in day to day cpp development
 */
typedef std::vector<std::string> Vector_Str;
// typedef std::vector<std::string>* P_Vector_Str;
typedef std::string String;

/**
 * Check the CLI arguments for a '-p' option
 */
bool shouldCreatePerson(std::vector<std::string>& args) {
  for (std::string x:args) {
    if (x == "-p") {
      return true;
    }
  }

  return false;
}

/**
 * Check the CLI arguments for a '-t' option
 */
bool shouldCreateTweeter(std::vector<std::string>& args) {
  for (std::string x:args) {
    if (x == "-t") {
      return true;
    }
  }

  return false;
}

int main(int argc, char const *argv[])
{
  /** 
   * Use the range initializer, 
   * this saves you the time of having to write a for loop
   * 
   * Start at argv + 1 because the first c-string in argv will be 
   * the full filepath of the program.
   */
  Vector_Str args{argv + 1, argv + argc};

  std::cout << "Hello, World!\n";
  std::cout << "To create a person, input -p [options]\n";
  std::cout << "CLI Arguments...\n";
  
  // Try to avoid native for-loops when possible. 
  for (String str:args) {
    std::cout << str << "\n";
  }

  double myDouble = 3.14159;

  /** 
   * Use static_cast and/or dynamic_cast functions to type cast variables.
   * Using these functions help to declare explicitness and suppress 
   * compiler warnings.
   */
  std::cout << std::to_string(static_cast<int>(myDouble)) << "\n";

  if (shouldCreatePerson(args)) {
    LCPP::Person p1{args[1], args[2], std::stoi(args[3])};
    std::cout << "Person: " << p1.getName() << "\n";
  }

  if (shouldCreateTweeter(args)) {
    LCPP::Tweeter p1{args[1], args[2], std::stoi(args[3]), args[4]};
    std::cout << "Person: " << p1.getName() << "\n";
  }

  return 0;
}
