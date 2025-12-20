#include "../include/BankSystem.hpp"
#include <ctime>

std::string currentTimestamp() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buffer);
}

int main() {
    BankSystem bank;

    Customer c1(1, "Kasra");
    bank.addCustomer(c1);

    int acc1 = bank.createAccount(1, "Kasra", Account::SAVINGS, 1000);
    int acc2 = bank.createAccount(1, "Kasra", Account::CHECKING, 500);

    Customer& cust = bank.getCustomer(1);
    cust.getAccount(acc1).deposit(200);
    bank.recordTransaction(Transaction::DEPOSIT, 200);

    cust.getAccount(acc1).transfer(cust.getAccount(acc2), 300);
    bank.recordTransaction(Transaction::TRANSFER, 300);

    cust.printReport();
    bank.printAllTransactions();
    bank.systemReport();

    return 0;
}