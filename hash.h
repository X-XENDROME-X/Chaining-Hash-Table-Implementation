#ifndef HASH_H
#define HASH_H

#include <string>
using namespace std;

//The below code is the node structure for the linked list implementation in each slot of the hash table
struct Node
{
    //The below code is the Key stored in the node
    string key;
    //The below code is the pointer to the next node in the linked list
    Node *next; 
};

//The below code is the HashTable class definition
class HashTable
{
private:
    //The below code is the size of the hash table
    int size;    
    //The below code is the array of pointers to Node, representing the hash table
    Node **table; 

public:
    //The below code is the constructor to initialize the hash table with a given size
    HashTable(int slotSize);

    //The below code is the destructor to deallocate memory used by the hash table
    ~HashTable();

    //The below code is the Hash function to map keys to slot indices
    int hashFunction(string key);

    //The below code is the method to insert a key into the hash table
    void insert(string key);

    //The below code is the method to get the first node in a slot given its index
    Node *getSlot(int index);

    //The below code is the method to print the lengths of each slot in the hash table
    void printSlotLengths();

    //The below code is the method to calculate the standard deviation of slot lengths
    double calculateStandardDeviation();
};

#endif

