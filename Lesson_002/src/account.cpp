#include "account.hpp"

Account::Account():balance(0) {}

std::vector<std::string> Account::Report() {
  std::vector<std::string> reports;
  reports.push_back("Balance: " + std::to_string(this->balance));
  reports.push_back("Transactions: ");
  for (Transaction t:this->log) {
    reports.push_back(t.Report());
  }
  reports.push_back("------------------");
  return reports;
}

bool Account::Deposit(int amt) {
  if (amt >= 0) {
    this->balance += amt;
    this->log.push_back(Transaction{amt, "Deposit"});
    return true;
  }
  return false;
}

bool Account::Withdrawl(int amt) {
  if (amt >= 0 && this->balance >= amt) {
    this->balance -= amt;
    this->log.push_back(Transaction{amt, "Withdrawl"});
    return true;
  }
  return false;
}