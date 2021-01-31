// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "UnsortedList.h"

using namespace std;
void PrintList(ofstream& outFile, UnsortedList& list);

int main()
{

    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command;        // operation to be executed

    int number;
    ItemType item;
    UnsortedList list;
    bool found;
    int numCommands;


    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
    outFile << outputLabel << endl;
    if (!inFile)
    {
        cout << "file not found" << endl;
        exit(2);
    }
    inFile >> command;

    numCommands = 0;
    while (command != "Quit")
    {
        if (command == "PutItem") { //puts item at end of list
            inFile >> number; //takes number from file
            item.Initialize(number); //initalizes the value 
            list.PutItem(item); //puts item in the list
            item.Print(outFile, false); //prints the value to file(false will not print to cmd screen)
            outFile << " was inserted into the file" << endl; //prints sentence adj to number in file
        }

        else if (command == "GetLength") { //gets length of list
            int length = list.GetLength();
            outFile << "Length of the list is " << length << "." << endl;
        }

        else if (command == "IsFull") { //checks if the list is full 
            bool isFull = list.IsFull(); //stores value returned from .IsFull
            if (isFull) {
                outFile << "The list is full." << endl; 
            }
            else {
                outFile << "The list is not full" << endl;
            }
        }

        else if (command == "GetItem") { //checks if item in list
            inFile >> number;
            item.Initialize(number);
            list.GetItem(item, found);
            if (found) {
                outFile << number << " is in the list." << endl;
            }
            else {
                outFile << number << " is not in the list." << endl;
            }
        }

        else if (command == "PrintList") { //prints entire list contents to output
            PrintList(outFile, list);
        }

        else if (command == "DeleteItem") { //deletes item from the list 
            inFile >> number;
            item.Initialize(number);
            list.DeleteItem(item);
            item.Print(outFile, false);
            outFile << " has been deleted from the list." << endl;
        }

        else if (command == "MakeEmpty") { //empties list
            list.MakeEmpty();
            outFile << "List has been emptied" << endl;
        }

        else if (command == "Quit") {
            cout << "End of program" << endl;
        }

        else {
            cout << "Command was not recognized" << endl;
            outFile << command << " was not recognized as an option" << endl;
        }
        numCommands++;
        cout << " Command number " << numCommands << " completed."
            << endl;
        inFile >> command;
    };

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}


void PrintList(ofstream& dataFile, UnsortedList& list)       
{
    int length;
    ItemType item;
    length = list.GetLength();
    list.ResetList();
    if (length == 0) {
        dataFile << "No data is in the list" << endl;
    }
    else {
        for (int i = 1; i <= length; i++) {
            item = list.GetNextItem();
            item.Print(dataFile, false);
        }
    }
    dataFile << endl;
}