#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

class GroceryTracker {
private:
    // Stores each item and the number of times it appears
    map<string, int> itemFrequency;

    // Reads the input file
    void LoadData();

    // Creates the backup file
    void WriteBackupFile();

public:
    GroceryTracker();

    // Returns frequency of one item
    int GetItemFrequency(string item);

    // Prints every item and frequency
    void PrintAllItems();

    // Prints histogram
    void PrintHistogram();
};

#endif
