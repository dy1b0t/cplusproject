#include "ItemFrequency.h"
#include <iostream>
#include <fstream>

using namespace std;

// Adds or updates the frequency of an item
void ItemFrequency::addItemFrequency(const string& item, int count) {
    // If the item already exists, update its count
    if (itemFrequency.find(item) != itemFrequency.end()) {
        itemFrequency[item] += count;
    }
    else {
        // Otherwise, add the item with the given count
        itemFrequency[item] = count;
    }
}

// Returns the frequency of the specified item
int ItemFrequency::getItemFrequency(const string& item) const {
    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        return it->second;
    }
    return 0; // Return 0 if the item is not found
}

// Prints the frequency of all items
void ItemFrequency::printAllFrequencies() const {
    cout << "Item Frequencies:" << endl;
    for (const auto& pair : itemFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Prints a histogram of the item frequencies
void ItemFrequency::printHistogram() const {
    cout << "Item Histogram:" << endl;
    for (const auto& pair : itemFrequency) {
        cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            cout << '*';
        }
        cout << endl;
    }
}

// Saves the frequencies to a file
void ItemFrequency::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}
