#include "GroceryTracker.h"

#include <iostream>
#include <fstream>

using namespace std;

// Constructor
GroceryTracker::GroceryTracker() {
    LoadData();
    WriteBackupFile();
}

// Reads the grocery file
void GroceryTracker::LoadData() {

    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    string item;

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

// Creates frequency.dat automatically
void GroceryTracker::WriteBackupFile() {

    ofstream outputFile("frequency.dat");

    for (auto pair : itemFrequency) {
        outputFile << pair.first << " "
            << pair.second << endl;
    }

    outputFile.close();
}

// Returns frequency of one item
int GroceryTracker::GetItemFrequency(string item) {

    if (itemFrequency.count(item) > 0) {
        return itemFrequency[item];
    }

    return 0;
}

// Prints every item
void GroceryTracker::PrintAllItems() {

    cout << endl;

    for (auto pair : itemFrequency) {

        cout << pair.first << " "
            << pair.second << endl;
    }

    cout << endl;
}

// Prints histogram
void GroceryTracker::PrintHistogram() {

    cout << endl;

    for (auto pair : itemFrequency) {

        cout << pair.first << " ";

        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }

        cout << endl;



    }

    cout << endl;
}