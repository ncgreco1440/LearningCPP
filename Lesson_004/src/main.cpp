#include <iostream>
#include <string>
#include <vector>

#include "functions.hpp"
#include "accum.hpp"
#include "resource.hpp"
#include "person.hpp"

std::vector<std::string> args;

/**
 * @brief push cli args into a global vector
 * @param argc - the amount of args to insert
 * @param argv - the char** to insert
 */
void pushArgs(int argc, char* argv[]) {
  if (argc > 1) { // start at 1 to skip the name of the binary as an argument
    for (int i = 1; i < argc; i++) {
      args.push_back(argv[i]);
    }
  }
}

int main(int argc, char* argv[]) {
  pushArgs(argc, argv);

  if (args.size()) {
    // Run some logic around Person/Resource
    LCPP::SmartPerson Bobby;

    {
      LCPP::Resource localResource{"local"};

      LCPP::SmartPerson Nico{"Nico", "Greco"};
      Nico.AddResource();
      Bobby = Nico;
    }

    Bobby.AddResource();

    // LCPP::Resource* pResource = new LCPP::Resource{"created with new"};
    // std::string newString = pResource->GetName();

    // // manually delete the resource
    // delete pResource;

    // // Yikes
    // std::string string3 = pResource->GetName();

  } else {
    // Run some logic around templates
    std::string s1{"cat"};
    std::string s2{"dog"};
    std::cout << "max of cat and dog is " << LCPP::max(s1, s2) << std::endl;

    std::cout << "max of 5 and 7 is " << LCPP::max(5, 7) << std::endl;

    std::cout << "max of 5.6 and 7.9 is " << LCPP::max(5.6, 7.9) << std::endl;

    LCPP::Accum<int> accumulator_int{5};
    LCPP::Accum<std::string> accumulator_str{""};
    accumulator_int += 7;
    accumulator_str += "hello, ";
    accumulator_str += "world!";
    accumulator_str += ". More characters here....";
    std::cout << accumulator_int.GetTotal() << std::endl;
    std::cout << accumulator_str.GetTotal() << std::endl;
  }

  return 0;
}
