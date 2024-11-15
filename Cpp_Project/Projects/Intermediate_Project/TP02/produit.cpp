// produit.cpp
#include "produit.h"
#include <iostream>

using namespace std;

// --- Produit_X Class Methods ---
void Produit_X::get_size() {
    cout << "Enter the number of stores: ";
    cin >> nbm_Store;
    prix.resize(nbm_Store);
}

void Produit_X::input_Valus() {
    cout << "Enter product name: ";
    cin >> name;
    for (int i = 0; i < nbm_Store; ++i) {
        cout << "Price at store " << i + 1 << ": ";
        cin >> prix[i];
    }
}

void Produit_X::output_Valus() const {
    cout << "Product name: " << name << endl;
    for (int i = 0; i < nbm_Store; ++i) {
        cout << "Price at store " << i + 1 << ": " << prix[i] << endl;
    }
}

void Produit_X::Avg_Price() const {
    double total = 0;
    for (int i = 0; i < nbm_Store; ++i) {
        total += prix[i];
    }
    cout << "Average price: " << (nbm_Store ? total / nbm_Store : 0) << endl;
}

void Produit_X::max_Price() const {
    if (prix.empty()) return;
    double max_price = prix[0];
    for (int i = 1; i < nbm_Store; ++i) {
        if (prix[i] > max_price) max_price = prix[i];
    }
    cout << "Maximum price: " << max_price << endl;
}

void Produit_X::min_Price() const {
    if (prix.empty()) return;
    double min_price = prix[0];
    for (int i = 1; i < nbm_Store; ++i) {
        if (prix[i] < min_price) min_price = prix[i];
    }
    cout << "Minimum price: " << min_price << endl;
}

void Produit_X::output_Valus_With_Position(double value) const {
    bool found = false;
    for (int i = 0; i < nbm_Store; ++i) {
        if (prix[i] == value) {
            cout << "Value " << value << " found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Value not found in price list.\n";
    }
}

void Produit_X::add_Price() {
    double new_price;
    cout << "Enter new price to add: ";
    cin >> new_price;
    prix.push_back(new_price);
    nbm_Store++;
}

void Produit_X::delete_Price() {
    double price_to_delete;
    bool found = false;
    cout << "Enter price to delete: ";
    cin >> price_to_delete;

    for (int i = 0; i < nbm_Store; ++i) {
        if (prix[i] == price_to_delete) {
            found = true;
            // Shift elements left to delete the element at index i
            for (int j = i; j < nbm_Store - 1; ++j) {
                prix[j] = prix[j + 1];
            }
            prix.pop_back(); // Remove the last element
            nbm_Store--;
            cout << "Price deleted.\n";
            break;
        }
    }

    if (!found) {
        cout << "Price not found.\n";
    }
}

// --- Stock Structure Methods ---
void Stock::addProduct(const Produit_X& newProduct) {
    products.push_back(newProduct);
    cout << "Product added to stock.\n";
}

void Stock::displayAllProducts() const {
    if (products.empty()) {
        cout << "No products in stock.\n";
        return;
    }
    for (int i = 0; i < products.size(); ++i) {
        products[i].output_Valus();
        cout << "----------------------\n";
    }
}

bool Stock::deleteProductByName(const string& name) {
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].name == name) {
            for (int j = i; j < products.size() - 1; ++j) {
                products[j] = products[j + 1];
            }
            products.pop_back();
            cout << "Product deleted from stock.\n";
            return true;
        }
    }
    cout << "Product not found in stock.\n";
    return false;
}

bool Stock::findProductByName(const string& name) const {
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].name == name) {
            cout << "Product found:\n";
            products[i].output_Valus();
            return true;
        }
    }
    cout << "Product not found in stock.\n";
    return false;
}
