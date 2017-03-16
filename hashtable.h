#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "linkedlist.h"

using namespace std;

// Hashtable class, implemented using separate chaining (Linked List method)
class hashtable {
public:
    // Parameterized constructor initializing the table and taking size as a parameter
    hashtable(int size);
    // Destructor
    virtual ~hashtable();
    // Hash function
    void hash(string st, int size, int select1, int select2, int m, int n);
    // Hashcode function, unsigned taken for component sum function to reduce overflows
    unsigned int hashcode(string word, int select1, int m);
    // Compression function
    int compression(unsigned int hashcode, int select2, int size);
    // Finds a substring and returns the false positive and comparisons value (for Q1)
    tuple* find(string P, string st, int size, int select1, int select2, int m);
    // Finds a subtring and outputs the pattern matches (for Q2)
    int findin(string P, string st, int size, int select1, int select2, int m, ofstream& fout2);

protected:
private:
    // Data member - basically the hash table
    linkedlist* table;
};

#endif // HASHTABLE_H
