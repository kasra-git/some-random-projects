#include "../include/Customer.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

Customer::Customer(int id, const std::string& name) : id(id), name(name) {}

void Customer::addAccount(const Account& account) {
    accounts.push_back(account);
}

Account& Customer::getAccount(int accountId) {
    for (auto& acc : accounts) {
        if (acc.getId() == accountId)
            return acc;
    }
    throw std::logic_error("Account not found.");
}

void Customer::printReport() const {
    std::cout << "\nCustomer ID: " << id << " | Name: " << name << std::endl;
    for (const auto& acc : accounts) {
        acc.printBalance();
    }
}
