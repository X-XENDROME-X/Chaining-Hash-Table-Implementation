#include "hash.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

// The below code is the constructor which Initializes the hash table with the specified size
HashTable::HashTable(int slotSize)
{
    size = slotSize;
    // The below code allocates memory for an array of  pointers to Node object
    table = new Node *[size]();
}

// The below code is the destructor which deallocates memory used by the hash table
// used for memory efficiency
HashTable::~HashTable()
{
    // The below code iterates through each slot in the hash table
    for (int i = 0; i < size; ++i)
    {
        Node *current = table[i];
        // The below code traverses the linked list in each slot and deallocate memory for each node
        while (current != NULL)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
    // The below code deallocates memory for the array of Node pointers
    delete[] table;
}

// The below code is the code for hash function
int HashTable::hashFunction(string key)
{
    int hash = 0;   // hash variable initialized to 0
    int prime = 31; // A prime numer is taken

    for (int i = 0; i < (int)key.size(); ++i)
    {
        hash = hash + prime * key[i]; // Prime number is multiplied with individual tokens and then added to hash
    }
    // The below code returns the hash value modulo the size of the hash table to get the slot index
    return hash % size;
}

// The below code inserts a key into the hash table
void HashTable::insert(string key)
{
    // The below code gets the slot index for the key
    int index = hashFunction(key);
    // The below code creates a new node
    Node *newNode = new Node;
    // The below code assigns the key to the new node
    newNode->key = key;
    // The below code points the new node to the current head of the linked list in the slot
    newNode->next = table[index];
    // The below code updates the head of the linked list in the slot to the new node
    table[index] = newNode;
}

// The below code gets the first node in a slot given its index
Node *HashTable::getSlot(int index)
{
    // The below code checks if the index is out of bounds
    if (index < 0 || index >= size)
    {
        return NULL;
    }
    // The below code returns the head of the linked list in the specified slot
    return table[index];
}

// The below code calculates the length of each slot and print it
void HashTable::printSlotLengths()
{
    for (int i = 0; i < size; ++i)
    {
        // The below code initializes length counter for the current slot
        int length = 0;
        // The below code gets the head of the linked list in the slot
        Node *current = table[i];
        while (current != NULL)
        {
            // The below code increments length for each node in the linked list
            ++length;
            // The below code moves to the next node
            current = current->next;
        }
        // The below code prints the slot index and its corresponding length
        cout << "Slot " << i << ": " << length << endl;
    }
}

// The below code calculates the standard deviation of slot lengths in the hash table
double HashTable::calculateStandardDeviation()
{
    // The below code calculates the mean slot length
    double mean = 0;
    // The below code counters for non-empty slots
    int nonEmptySlots = 0;
    for (int i = 0; i < size; ++i)
    {
        // The below code gets the head of the linked list in the slot
        Node *current = table[i];
        // The below code initializes slot length counter
        int slotLength = 0;
        while (current != NULL)
        {
            // The below code increments slot length for each node in the linked list
            ++slotLength;
            // The below code moves to the next node
            current = current->next;
        }
        if (slotLength > 0)
        {
            // The below code adds the slot length to the mean
            mean += slotLength;
            // The below code increments the counter for non-empty slots
            ++nonEmptySlots;
        }
    }
    // The below code calculates the mean by dividing the sum of slot lengths by the number of non-empty slots
    mean = mean / nonEmptySlots;

    // The below code calculates the sum of squared differences from the mean
    double sumSquaredDifferences = 0;
    for (int i = 0; i < size; ++i)
    {
        // The below code gets the head of the linked list in the slot
        Node *current = table[i];
        // The below code initializes slot length counter
        int slotLength = 0;
        while (current != NULL)
        {
            // The below code increments slot length for each node in the linked list
            ++slotLength;
            // The below code moves to the next node
            current = current->next;
        }
        if (slotLength > 0)
        {
            // The below code adds squared difference from the mean to the sum
            sumSquaredDifferences += pow(slotLength - mean, 2);
        }
    }

    // The below code calculates the variance
    double variance = sumSquaredDifferences / nonEmptySlots;

    // The below code calculates the standard deviation by taking the square root of the variance
    double standardDeviation = sqrt(variance);

    // The below code returns the calculated standard deviation
    return standardDeviation;
}
