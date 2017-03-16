#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include "tuple.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include "functions.h"

using namespace std;

// Linked list class, (Maintains buckets)
class linkedlist {
public:
    //Constructor
    linkedlist();
    // Adds a given item (index) to the linked list
    void add(int i);
    // Used to search for the pattern string in the given linked list, and outputs the index at which pattern matches
    // Also outputs to the file
    // Meant for Q2
    int searchin(string P, string st, int m, ofstream& fout2);
    // Used to search for the pattern string in the given linked list
    // Then calculates the comparisons and false positives in the form of tuple
    tuple* search(string P, string st, int m);
    //Destructor
    virtual ~linkedlist();

protected:
private:
    // Node head that points to the top of the linked list
    node* head;
};

#endif // LINKEDLIST_H
