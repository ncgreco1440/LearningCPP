#ifndef ACCOUNT_HEADER_
#define ACCOUNT_HEADER_

#include <string>
#include <vector>
#include "transaction.hpp"

/**
 * Generic Bank Account
 */
class Account {
  public:
    /**
     * Create a new blank Account
     */
    Account();
    /**
     * Returns the given balance for this account
     */
    inline int GetBalance() {
      return this->balance;
    }
    inline bool EvenBalance() {
      return true;
    }
    /**
     * Deposits money into the account
     * @param amt - amount to deposit
     */
    bool Deposit(int amt);
    /**
     * Withdraws money from the account
     * @param amt - amount to withdraw
     */
    bool Withdrawl(int amt);
    /**
     * Return a report of the transactions that took place
     * @return std::vector\<std::string>> report
     */
    std::vector<std::string> Report();
  private:
    int balance;
    std::vector<Transaction> log; 
};

#endif