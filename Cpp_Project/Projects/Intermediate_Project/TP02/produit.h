// produit.h
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Produit_X {
public:
    string name;
    vector<double> prix;
    int nbm_Store;

    void get_size();
    void input_Valus();
    void output_Valus() const;
    void Avg_Price() const;
    void max_Price() const;
    void min_Price() const;
    void output_Valus_With_Position(double value) const;
    void add_Price();
    void delete_Price();
};

struct Stock {
    vector<Produit_X> products;

    void addProduct(const Produit_X& newProduct);
    void displayAllProducts() const;
    bool deleteProductByName(const string& name);
    bool findProductByName(const string& name) const;
};
