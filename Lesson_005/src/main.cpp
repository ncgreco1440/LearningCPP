#include <iostream>
#include <vector>

#include "person.hpp"
#include "tweeter.hpp"

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
  for (std::string x: args) {
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
  for (std::string x: args) {
    if (x == "-t") {
      return true;
    }
  }

  return false;
}

/**
 * accept base classes by const& such that virtual functions may be used.
 * accepting by value means that slicing will occur, which results in loss of data.
 */
std::string getName(LCPP::Person const& p) {
  return p.getName();
}

int main(int argc, char const* argv[]) {
#ifdef Windows
  std::cout << "This program is running on windows" << std::endl;
#endif

  /**
   * Use the range initializer,
   * this saves you the time of having to write a for loop
   *
   * Start at argv + 1 because the first c-string in argv will be
   * the full filepath of the program.
   */
  Vector_Str args{argv + 1, argv + argc};

  // if (shouldCreatePerson(args)) {
  //   LCPP::Person p1{args[1], args[2], std::stoi(args[3])};
  //   std::cout << p1.getName() << "\n";
  // }

  // if (shouldCreateTweeter(args)) {
  //   LCPP::Tweeter p1{args[1], args[2], std::stoi(args[3]), args[4]};
  //   std::cout << p1.getName() << "\n";
  // }

  LCPP::Tweeter t2{args[1], args[2], std::stoi(args[3]), args[4]};
  // Calling raw function
  std::cout << getName(t2) << std::endl;

  LCPP::Person* p1 = dynamic_cast<LCPP::Person*>(&t2);

  if (p1) {
    std::cout << "p1\'s declared type Tweeter points to a Person";
  }

  return 0;
}
