#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP
#include "../include/Customer.hpp"
#include "../include/Transaction.hpp"
#include <vector>


class BankSystem {
private:
    std::vector<Customer> customers;
    std::vector<Transaction> transactions;
    static int totalAccounts;
    int nextTransactionId = 1;

public:
    void addCustomer(const Customer& customer);
    Customer& getCustomer(int customerId);
    int createAccount(int customerId, const std::string& owner, Account::Type type, double initialBalance);
    void recordTransaction(Transaction::Type type, double amount);
    void printAllTransactions() const;
    void systemReport() const;
};

#endif