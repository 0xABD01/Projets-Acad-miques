#include <iostream>
#include <unordered_map>
#include "bank_account.h"

void showMenu();

int main() {
    std::unordered_map<std::string, BankAccount> accounts;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string number, holder, pin;
            double initialBalance;
            std::cout << "Enter account number: ";
            std::cin >> number;
            std::cout << "Enter account holder name: ";
            std::cin.ignore();
            std::getline(std::cin, holder);
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;
            std::cout << "Set a 4-digit PIN: ";
            std::cin >> pin;

            accounts[number] = BankAccount(number, holder, initialBalance, pin);
            std::cout << "Account created successfully!\n";
            break;
        }
        case 2: {
            std::string number, pin;
            std::cout << "Enter account number: ";
            std::cin >> number;

            if (accounts.find(number) != accounts.end()) {
                BankAccount& account = accounts[number];
                std::cout << "Enter PIN: ";
                std::cin >> pin;

                if (account.authenticate(pin)) {
                    std::cout << "Login successful!\n";
                    // Ajouter les actions après connexion ici
                } else {
                    std::cout << "Invalid PIN!\n";
                }
            } else {
                std::cout << "Account not found!\n";
            }
            break;
        }
        case 3:
            std::cout << "Exiting application...\n";
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void showMenu() {
    std::cout << "\n===== Bank Account Management =====\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Access Account\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}