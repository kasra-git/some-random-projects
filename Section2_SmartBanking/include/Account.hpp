#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>

class Account {
public:
    enum Type { SAVINGS, CHECKING, CREDIT };

private:
    int id;
    std::string ownerName;
    double balance;
    Type type;

public:
    Account(int id, const std::string& owner, Type type, double initialBalance);

    void deposit(double amount);
    void withdraw(double amount);

    void transfer(Account& to, double amount);
    void printBalance() const;
    int getId() const;
    double getBalance() const;

    friend class Customer;
};

#endif