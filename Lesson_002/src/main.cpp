/**
 * Working with classes. The following lesson demos a fictious bank account.
 */

#include <iostream>

#include "account.hpp"
#include "transaction.hpp"

int main(int argc, char const *argv[])
{
  Account a1;
  a1.Deposit(90);
  std::cout << "After depositing $90\n";
  std::cout << "Balance is " << a1.GetBalance() << "\n";
  for (std::string s:a1.Report()) {
    std::cout << s << std::endl;
  }

  a1.Withdrawl(50);
  if (a1.Withdrawl(100)) {
    std::cout << "second withdraw succeeded\n";
  }
  std::cout << "After withdrawing $50 and then attempted $100\n";
  for (std::string s:a1.Report()) {
    std::cout << s << std::endl;
  }

  return 0;
}
