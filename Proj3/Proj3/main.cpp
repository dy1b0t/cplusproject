#include <iostream>
#include <fstream>
#include <string>
#include "ItemFrequency.h"

using namespace std;

void displayMenu();
void processUserChoice(ItemFrequency& itemFreq, bool& isRunning);

int main() {
    ItemFrequency itemFreq;
    bool isRunning = true;

    // Load data from the input file
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string item;
    int count;
    while (inputFile >> item >> count) {
        itemFreq.addItemFrequency(item, count);
    }
    inputFile.close();

    // Save initial data to frequency.dat
    itemFreq.saveToFile("frequency.dat");

    while (isRunning) {
        displayMenu();
        processUserChoice(itemFreq, isRunning);
    }

    return 0;
}

void displayMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Search Item Frequency" << endl;
    cout << "2. Display Item Frequencies" << endl;
    cout << "3. Display Histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void processUserChoice(ItemFrequency& itemFreq, bool& isRunning) {
    int choice;
    cin >> choice;
    string item;

    switch (choice) {
    case 1:
        cout << "Enter the item to search: ";
        cin >> item;
        cout << "Frequency of " << item << ": " << itemFreq.getItemFrequency(item) << endl;
        break;
    case 2:
        itemFreq.printAllFrequencies();
        break;
    case 3:
        itemFreq.printHistogram();
        break;
    case 4:
        isRunning = false;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}
