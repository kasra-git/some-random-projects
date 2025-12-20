#include "../include/Transaction.hpp"
#include <stdexcept>
#include <iostream>

Transaction::Transaction(int id, Type type, double amount) : id(id), type(type), amount(amount) {}

bool Transaction::operator==(const Transaction& other) const {
    return type == other.type && amount == other.amount;
}

Transaction Transaction::operator+(const Transaction& other) const {
    if (type != other.type) {
        throw std::logic_error("Cannot combine transactions of different types.");
    }
    return Transaction(-1, type, amount + other.amount);
}

void Transaction::print() const {
    std::cout << "Transaction ID: " << id << " | Type: " << typeToString() << " | Amount: " << amount;
}

std::string Transaction::typeToString() const {
    switch (type) {
        case DEPOSIT: return "Deposit";
        case WITHDRAWAL: return "Withdrawal";
        case TRANSFER: return "Transfer";
    }
    return "Unknown";
}