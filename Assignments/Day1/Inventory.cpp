/*
Assignment-1

Aim:-  Develop a Warehouse Inventory Management System using C++ to simulate how industries manage and track their inventory.
The program should enable users to add new items to the inventory, update stock levels, track inventory movement, and generate reports.
Each item in the inventory should be represented as an object with attributes like a unique item ID, name, category, quantity, and reorder level.
The system should include functionality to alert the user when stock levels fall below the reorder threshold.
A menu-driven interface should allow users to perform operations such as viewing inventory, searching for items by name or category, and exporting inventory data to a file for record-keeping.
This assignment is designed to mirror real-world inventory management systems used in industries like retail, manufacturing, and logistics,
providing hands-on experience with object-oriented design, file handling, and user interaction in C++.


Input:

1.Add item details like item ID, name, category, quantity, and reorder level.
2.Update stock levels for existing items.
3.Search for items by name or category.


Output:
1.Display the current inventory with all item details.
2.Alert the user when an item's stock is below its reorder level.
3.Export inventory data to a file for record-keeping.

*/

// Code:-

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class InventoryItem
{
public:
    int itemID;
    string name;
    string category;
    int quantity;
    int reorderLevel;

    // Constructor
    InventoryItem(int id, string n, string cat, int qty, int reorder)
        : itemID(id), name(n), category(cat), quantity(qty), reorderLevel(reorder) {}

    // Display item details
    void displayItem() const
    {
        cout << setw(10) << itemID << setw(20) << name << setw(20) << category
             << setw(10) << quantity << setw(15) << reorderLevel << endl;
    }
};

class InventorySystem
{
private:
    vector<InventoryItem> inventory;

public:
    // Add a new item
    void addItem()
    {
        int id, qty, reorder;
        string name, category;

        cout << "Enter Item ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Item Name: ";
        getline(cin, name);
        cout << "Enter Category: ";
        getline(cin, category);
        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Reorder Level: ";
        cin >> reorder;

        inventory.push_back(InventoryItem(id, name, category, qty, reorder));
        cout << "Item added successfully.\n";
    }

    // Update stock levels
    void updateStock()
    {
        int id, qty;
        cout << "Enter Item ID to update: ";
        cin >> id;

        for (auto &item : inventory)
        {
            if (item.itemID == id)
            {
                cout << "Enter new quantity: ";
                cin >> qty;
                item.quantity = qty;
                cout << "Stock updated successfully.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Display inventory
    void viewInventory() const
    {
        if (inventory.empty())
        {
            cout << "No items in inventory.\n";
            return;
        }

        cout << setw(10) << "Item ID" << setw(20) << "Name" << setw(20)
             << "Category" << setw(10) << "Quantity" << setw(15) << "Reorder Level" << endl;
        cout << string(75, '-') << endl;

        for (const auto &item : inventory)
        {
            item.displayItem();
        }
    }

    // Search items by name or category
    void searchItem() const
    {
        string keyword;
        cout << "Enter item name or category to search: ";
        cin.ignore();
        getline(cin, keyword);

        bool found = false;
        for (const auto &item : inventory)
        {
            if (item.name.find(keyword) != string::npos ||
                item.category.find(keyword) != string::npos)
            {
                item.displayItem();
                found = true;
            }
        }

        if (!found)
        {
            cout << "No items found.\n";
        }
    }

    // Generate alerts for low stock
    void checkReorderLevel() const
    {
        bool alert = false;
        for (const auto &item : inventory)
        {
            if (item.quantity < item.reorderLevel)
            {
                cout << "Alert: Item \"" << item.name << "\" is below reorder level.\n";
                alert = true;
            }
        }

        if (!alert)
        {
            cout << "All items are above their reorder levels.\n";
        }
    }

    // Export inventory data to a file
    void exportData() const
    {
        ofstream file("InventoryReport.txt");
        if (!file)
        {
            cout << "Error opening file for writing.\n";
            return;
        }

        file << setw(10) << "Item ID" << setw(20) << "Name" << setw(20)
             << "Category" << setw(10) << "Quantity" << setw(15) << "Reorder Level" << endl;
        file << string(75, '-') << endl;

        for (const auto &item : inventory)
        {
            file << setw(10) << item.itemID << setw(20) << item.name
                 << setw(20) << item.category << setw(10) << item.quantity
                 << setw(15) << item.reorderLevel << endl;
        }

        file.close();
        cout << "Inventory data exported successfully to 'InventoryReport.txt'.\n";
    }
};

// Main function
int main()
{
    InventorySystem system;
    int choice;

    do
    {
        cout << "\nWarehouse Inventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Update Stock\n";
        cout << "3. View Inventory\n";
        cout << "4. Search Item\n";
        cout << "5. Check Reorder Levels\n";
        cout << "6. Export Inventory Data\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addItem();
            break;
        case 2:
            system.updateStock();
            break;
        case 3:
            system.viewInventory();
            break;
        case 4:
            system.searchItem();
            break;
        case 5:
            system.checkReorderLevel();
            break;
        case 6:
            system.exportData();
            break;
        case 7:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

/*
OUTPUT:


Warehouse Inventory Management System
1. Add Item
2. Update Stock
3. View Inventory
4. Search Item
5. Check Reorder Levels
6. Export Inventory Data
7. Exit

Enter your choice: 1
Enter Item ID: 101
Enter Item Name: widget
Enter Category: tools
Enter Quantity: 50
Enter Reorder Level: 20
Item added successfully.

*/
