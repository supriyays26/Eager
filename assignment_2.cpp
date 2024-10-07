// Assignment 2

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class InventoryItem {
public:

    int productId;
    string productName;
    string productCategory;
    int stockQuantity;

    InventoryItem() : productId(0), productName(""), productCategory(""), stockQuantity(0) {}
    InventoryItem(int id, const std::string& name, const std::string& category, int quantity)
        : productId(id), productName(name), productCategory(category), stockQuantity(quantity) {}
 
    void display() const {

        std::cout << "Product(ID: " << productId 
<< ", Name: " << productName 
<< ", Category: " << productCategory 
<< ", Quantity: " << stockQuantity << ")\n";

    }

};
 
class InventoryManager {
    private:

    std::unordered_map<int, InventoryItem> inventory;
 
public:

    void addProduct(int id, const std::string& name, const std::string& category, int quantity) {
            if (inventory.find(id) != inventory.end()) {
            std::cout << "Product with ID " << id << " already exists.\n";
        } else {
            inventory[id] = InventoryItem(id, name, category, quantity);
            std::cout << "Product '" << name << "' added successfully.\n";
        }

    }
 
    void updateStockQuantity(int id, int newQuantity) {
        if (inventory.find(id) != inventory.end()) {
            inventory[id].stockQuantity = newQuantity;
            std::cout << "Stock quantity for product ID " << id << " updated to " << newQuantity << ".\n";
        } else {
            std::cout << "Product with ID " << id << " not found.\n";

        }

    }
 
    std::vector<InventoryItem> searchProductByCategory(const std::string& category) {
        std::vector<InventoryItem> matchingProducts;
        for (const auto& entry : inventory) {
            if (entry.second.productCategory == category) {
                matchingProducts.push_back(entry.second);

            }

        }
        return matchingProducts;

    }
 
    void displayAllProducts() const {
        for (const auto& entry : inventory) {
            entry.second.display();

        }

    }

};
 
int main() {
    InventoryManager myInventory;
 
    // Adding new products
    myInventory.addProduct(101, "headset", "Electronics", 50);
    myInventory.addProduct(102, "iphone", "Electronics", 125);
    myInventory.addProduct(201, "Watch", "Fashion", 20);
 
    // Updating stock quantity
    myInventory.updateStockQuantity(101, 45);
    myInventory.updateStockQuantity(404, 30);  // Product not found
 
    // Searching for products by category
    std::vector<InventoryItem> electronics = myInventory.searchProductByCategory("Electronics");
    std::cout << "Electronics products:\n";
    for (const auto& product : electronics) {
        product.display();

    }
 
    std::vector<InventoryItem> fashion = myInventory.searchProductByCategory("Fashion");
    std::cout << "Fashion products:\n";
    for (const auto& product : fashion) {
        product.display();
    }
 
    std::vector<InventoryItem> toys = myInventory.searchProductByCategory("Toys");  // No products found
    std::cout << "Toys products:\n";
    for (const auto& product : toys) {
        product.display();
    }
 
    // Display all products
    std::cout << "All products in inventory:\n";
    myInventory.displayAllProducts();
    return 0;

}

 