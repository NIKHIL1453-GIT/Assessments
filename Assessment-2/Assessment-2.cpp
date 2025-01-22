/*Create a Project to demonstrate Simple Food Ordering Project which will help to order 
foods . The Project should contain all the necessary  requirements i.e  need to use 
conditional Statements, Loops, Function, SwitchCase  and also A Program should use  
the concept of OOP.*/


#include <iostream>
#include <string>

using namespace std;

// Class representing a food item
class FoodItem {
public:
    string name;
    double price;

    FoodItem(string n = "", double p = 0.0) : name(n), price(p) {}

    // Display food item details
    void display() {
        cout << name << " - " << price << endl;
    }
};

// Class representing an order
class Order {
private:
    FoodItem cart[100];  // Fixed-size array to store food items
    int itemCount;
    double total;

public:
    Order() : itemCount(0), total(0) {}

    // Add an item to the order
    void addItem(FoodItem item) {
        if (itemCount < 100) {
            cart[itemCount++] = item;
            total += item.price;
        } else {
            cout << "Order is full. Cannot add more items.\n";
        }
    }

    // Display the complete order
    void displayOrder() {
        cout << "\nYour Order Summary:\n";
        for (int i = 0; i < itemCount; i++) {
            cart[i].display();
        }
        cout << "Total Amount: " << total << "\n";
    }
};

// Function to display the food menu
void displayMenu() {
    cout << "\nWelcome to the Food Ordering System\n";
    cout << "Please choose from the menu below:\n";
    cout << "1. Pizza - 10.00\n";
    cout << "2. Burger - 5.00\n";
    cout << "3. Pasta - 7.00\n";
    cout << "4. Exit\n";
}

int main() {
    Order order;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Process user choice using switch-case
        switch (choice) {
            case 1:
                order.addItem(FoodItem("Pizza", 10.00));
                cout << "Pizza added to your order.\n";
                break;
            case 2:
                order.addItem(FoodItem("Burger", 5.00));
                cout << "Burger added to your order.\n";
                break;
            case 3:
                order.addItem(FoodItem("Pasta", 7.00));
                cout << "Pasta added to your order.\n";
                break;
            case 4:
                cout << "Thank you for using the Food Ordering System!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    // Display the final order summary
    order.displayOrder();

    cout << "\nHave a great day!\n";
    return 0;
}

