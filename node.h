#ifndef NODE_H
#define NODE_H

// Class for node (Used in making a linked list)
class node {
public:
    // Members set as private so that they are used easily by the linked list.
    // There is no information leak as we are not returning any node to any file except linkedlist
    // Pointer to point to the next used
    node* next;
    // Used to store the index
    int index;
    node();
    virtual ~node();

protected:
private:
};

#endif // NODE_H
