#include "transaction.hpp"

Transaction::Transaction(int amt, std::string kind)
  :amount(amt), type(kind) {}

Transaction::Transaction():amount(0), type("NIL") {}

std::string Transaction::Report() {
  std::string report{" " + this->type + " " + std::to_string(this->amount)};
  return report;
}