#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "hash.h" 

using namespace std;

int main (int argc , char *argv[])
{
    // The below code checks if the correct number of arguments is provided
    if (argc != 1)
    {
        cout << "Usage: " << argv[0] << " < input_file" << endl;
        // The below code return an error code indicating improper usage
        return 1; 
    }

    //The below code is the number of slots in the hash table
    int k = 0; 
    //Below is the index n
    int n = 0; 
    //The below code is the array to store input tokens
    string texts[500]; 

    //The below code reads the number of hash table slots from standard input
    cin >> k;
    string line;
    //Below code takes out a newline character
    getline(cin, line); 

    //The below code reads tokens from a standard input which will be given as a file while running
    while (getline(cin, line))
    {
        texts[n] = line;
        n++;
    }
    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    //The below code creates a hash table
    HashTable hashTable(k);

    //The below code inserts tokens into the hash table
    for (int i = 0; i < n; ++i)
    {
        hashTable.insert(texts[i]);
    }

    //The below code print the contents of the first 5 slots
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5; ++i)
    {
        // Printing the slot index
        cout << "Slot " << i << ": ";
        
        // Getting the first node in the slot
        Node *current = hashTable.getSlot(i);
        while (current != NULL)
        {
            // Printing the key stored in the current node
            cout << current->key << " ";

            // Moving to the next node in the slot
            current = current->next;
        }
        // Moving to the next line after printing all keys in the slot
        cout << endl;
    }

    //The below code prints the lengths of every slot
    cout << "==== Printing the slot lengths ====" << endl;
    hashTable.printSlotLengths();

    //The below code prints the standard deviation
    cout << "==== Printing the standard deviation ====" << endl;
    cout << fixed << setprecision(4) << hashTable.calculateStandardDeviation() << endl;

    return 0;
}

