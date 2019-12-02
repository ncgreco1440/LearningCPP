#include <iostream>
#include <string>

#include "functions.hpp"
#include "accum.hpp"

int main() {
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

  return 0;
}
