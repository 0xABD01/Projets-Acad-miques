#include "bank_account.h"
#include <iostream>
#include <iomanip>

BankAccount::BankAccount(const std::string& number, const std::string& holder, double initialBalance, const std::string& pin)
    : accountNumber(number), accountHolder(holder), balance(initialBalance), pinCode(pin), failedAttempts(0) {}

bool BankAccount::authenticate(const std::string& pin) {
    if (pin == pinCode) {
        failedAttempts = 0;
        return true;
    } else {
        failedAttempts++;
        return false;
    }
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactionHistory.push_back("Deposit: " + std::to_string(amount));
    } else {
        std::cout << "Invalid deposit amount." << std::endl;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        transactionHistory.push_back("Withdraw: " + std::to_string(amount));
        return true;
    } else {
        std::cout << "Insufficient balance or invalid amount." << std::endl;
        return false;
    }
}

bool BankAccount::transfer(BankAccount& recipient, double amount) {
    if (withdraw(amount)) {
        recipient.deposit(amount);
        transactionHistory.push_back("Transfer to " + recipient.accountNumber + ": " + std::to_string(amount));
        return true;
    }
    return false;
}

double BankAccount::getBalance() const {
    return balance;
}

std::vector<std::string> BankAccount::getTransactionHistory() const {
    return transactionHistory;
}