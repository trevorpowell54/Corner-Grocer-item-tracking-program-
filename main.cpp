#include <iostream>
#include <limits>

#include "GroceryTracker.h"

using namespace std;

// Displays menu
void DisplayMenu() {

    cout << endl;
    cout << "========= Corner Grocer =========" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. Print frequency list" << endl;
    cout << "3. Print histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "=================================" << endl;
    cout << "Enter choice: ";
}

int main() {

    GroceryTracker tracker;

    int choice = 0;

    while (choice != 4) {

        DisplayMenu();

        cin >> choice;

        // Input validation
        while (cin.fail() || choice < 1 || choice > 4) {

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid selection." << endl;
            cout << "Enter a number between 1 and 4: ";

            cin >> choice;
        }

        if (choice == 1) {

            string item;

            cout << endl;
            cout << "Enter item name: ";
            cin >> item;

            cout << endl;
            cout << item << " was purchased "
                << tracker.GetItemFrequency(item)
                << " time(s)." << endl;
        }

        else if (choice == 2) {

            tracker.PrintAllItems();
        }

        else if (choice == 3) {

            tracker.PrintHistogram();
        }

        else if (choice == 4) {

            cout << endl;
            cout << "Goodbye!" << endl;
        }
    }

    return 0;
}