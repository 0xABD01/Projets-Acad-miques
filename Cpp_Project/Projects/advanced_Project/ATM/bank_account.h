#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;
    std::string pinCode;
    std::vector<std::string> transactionHistory;
    int failedAttempts;

public:
    BankAccount(const std::string& number, const std::string& holder, double initialBalance, const std::string& pin);

    bool authenticate(const std::string& pin);
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(BankAccount& recipient, double amount);
    double getBalance() const;
    std::vector<std::string> getTransactionHistory() const;
};

#endif