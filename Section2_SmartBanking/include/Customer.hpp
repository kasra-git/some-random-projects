#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <string>
#include <vector>
#include "../include/Account.hpp"

class Customer {
private:
    int id;
    std::string name;
    std::vector<Account> accounts;

public:
    Customer(int id, const std::string& name);
    void addAccount(const Account& account);
    Account& getAccount(int accountId);
    void printReport() const;
    friend class BankSystem;
};

#endif