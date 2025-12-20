#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP
#include <string>

class Transaction {
    public:
        enum Type { DEPOSIT, WITHDRAWAL, TRANSFER };
    private:
        int id;
        Type type;
        double amount;
        std::string timestamp;
    public:
        Transaction(int id, Type type, double amount);
        bool operator==(const Transaction& other) const;
        Transaction operator+(const Transaction& other) const;
        void print() const;
    private:
        std::string typeToString() const;
        friend class BankSystem;
};
#endif 