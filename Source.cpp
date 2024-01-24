#include <iostream>
#include <vector>

using namespace std;

// Function to add a product to the stock
void addProduct(vector<vector<int>>& stock) {
    int code, quantity;

    cout << "Enter the product code: ";
    cin >> code;

    cout << "Enter the quantity to add: ";
    cin >> quantity;

    // Check if the product already exists in the stock
    for (size_t i = 0; i < stock.size(); i++) {
        if (stock[i][0] == code) {
            // Product exists add the specified quantity
            stock[i][1] += quantity;
            cout << "Quantity has been added to the stock." << endl;
            return;
        }
    }

    // Product doesn't exist, add it to the stock
    stock.push_back({ code, quantity });
    cout << "The product has been added to the stock." << endl;
}

// Function to remove a product from the stock
void removeProduct(vector<vector<int>>& stock) {
    int code, quantity;

    cout << "Enter the product code: ";
    cin >> code;

    cout << "Enter the quantity to remove: ";
    cin >> quantity;

    // Search for the product in the stock
    for (size_t i = 0; i < stock.size(); i++) {
        if (stock[i][0] == code) {
            // Product found
            if (stock[i][1] < quantity) {
                // Quantity to remove is greater than the available stock
                cout << "Error: Quantity to remove is greater than the available stock." << endl;
            }
            else {
                // Remove the specified quantity from the stock
                stock[i][1] -= quantity;
                cout << "Quantity has been removed from the stock." << endl;
            }
            return;
        }
    }

    // Product not found
    cout << "Error: The product does not exist in the stock." << endl;
}

// Function to display the total stock
void displayStock(const vector<vector<int>>& stock) {
    cout << "Total stock:" << endl;

    for (const auto& product : stock) {
        cout << "Product " << product[0] << " - Quantity: " << product[1] << endl;
    }
}

int main() {
    vector<vector<int>> stock; // Stock initialized as a vector of vectors of integers

    int choice;

    do {
        // Menu
        cout << "\n|||||||||||||||||| Menu: ||||||||||||||||||" << endl;
        cout << "===================================\n\a";
        cout << "1. Add a product to the stock      |" << endl;
        cout << "===================================\n\a";
        cout << "2. Remove a product from the stock |" << endl;
        cout << "===================================\n\a";
        cout << "3. Display total stock             |" << endl;
        cout << "===================================\n\a";
        cout << "4. Quit                            |" << endl;
        cout << "===================================\n\a";
        cout << "Enter your \"choice\": ";
        cin >> choice;

        // Execute the action based on the user's choice
        switch (choice) {
        case 1:
            addProduct(stock);
            break;
        case 2:
            removeProduct(stock);
            break;
        case 3:
            displayStock(stock);
            break;
        case 4:
            cout << "Program terminated." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
