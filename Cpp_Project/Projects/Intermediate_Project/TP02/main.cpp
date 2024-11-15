// main.cpp
#include "produit.h"
#include <iostream>

using namespace std;

int main() {

    system("cls");
    Stock stock;
    Produit_X product;
    char choice;

    do {

        system("cls");


        cout << "\nChoose an option:\n";
        cout << "1. Add product to stock\n";
        cout << "2. Display all products in stock\n";
        cout << "3. Find product by name\n";
        cout << "4. Delete product by name\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
        case '1':
            product.get_size();
            product.input_Valus();
            stock.addProduct(product);
            break;
        case '2':
            stock.displayAllProducts();
            break;
        case '3': {
            string searchName;
            cout << "Enter the product name to search: ";
            cin >> searchName;
            stock.findProductByName(searchName);
            break;
        }
        case '4': {
            string deleteName;
            cout << "Enter the product name to delete: ";
            cin >> deleteName;
            stock.deleteProductByName(deleteName);
            break;
        }
        case '5':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

        if (choice != '5') {
            cout << "Press Enter to continue...";
            cin.ignore(); // Clear the newline character from the input buffer
            cin.get();    // Wait for the user to press Enter
        }
        
    } while (choice != '5');

    return 0;
}
