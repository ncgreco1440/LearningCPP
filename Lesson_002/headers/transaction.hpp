#ifndef TRANSACTION_HEADER_
#define TRANSACTION_HEADER_

#include <string>

/**
 * Transactions that are involved during the lifetime of a Bank Account
 */
class Transaction {
  public:
    /**
     * Creates a new Transaction
     * @param amt - amount of money involved in the transaction
     * @param kind - the type of transaction this is
     */
    Transaction(int amt, std::string kind);
    std::string Report();
  private:
    /**
     * Privatize the default constructor to prevent usage.
     */
    Transaction();
    int amount;
    std::string type;
};

#endif