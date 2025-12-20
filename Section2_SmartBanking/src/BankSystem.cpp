#include "../include/BankSystem.hpp"
#include "../include/Customer.hpp"
#include "../include/Transaction.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

void BankSystem::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

Customer& BankSystem::getCustomer(int customerId) {
    for (auto& cust : customers) {
        if (cust.id == customerId)
            return cust;
    }
    throw std::logic_error("Customer not found.");
}

int BankSystem::createAccount(int customerId, const std::string& owner, Account::Type type, double initialBalance) {
    totalAccounts++;
    Account acc(totalAccounts, owner, type, initialBalance);
    getCustomer(customerId).addAccount(acc);
    return totalAccounts;
}

void BankSystem::recordTransaction(Transaction::Type type, double amount) {
    transactions.emplace_back(nextTransactionId++, type, amount);
}

void BankSystem::printAllTransactions() const {
    std::cout << "\n=== Transaction Report ===" << std::endl;
    for (const auto& t : transactions) {
        t.print();
    }
}

void BankSystem::systemReport() const {
    std::cout << "\n=== Bank System Report ===" << std::endl;
    std::cout << "Total Customers: " << customers.size() << std::endl;
    std::cout << "Total Accounts: " << totalAccounts << std::endl;
    std::cout << "Total Transactions: " << transactions.size() << std::endl;
}

int BankSystem::totalAccounts = 0;