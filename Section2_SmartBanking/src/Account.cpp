#include "../include/Account.hpp"
#include <stdexcept>
#include <iostream>

Account::Account(int id, const std::string& owner, Account::Type type, double initialBalance) : id(id), ownerName(owner), balance(initialBalance), type(type) {}

void Account::deposit(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Deposit amount must be positive.");
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Withdrawal amount must be positive.");
    if (balance < amount)
        throw std::logic_error("Insufficient balance.");
    balance -= amount;
}

void Account::transfer(Account& to, double amount) {
    withdraw(amount);
    to.deposit(amount);
}

void Account::printBalance() const {
    std::cout << "Account ID: " << id << " | Owner: " << ownerName<< " | Balance: " << balance << std::endl;
}

int Account::getId() const { return id; }
double Account::getBalance() const { return balance; }