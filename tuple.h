#ifndef TUPLE_H
#define TUPLE_H

// Class for tuple, for storing and returning the comparisons and false positive for a particular search
class tuple {
public:
    // Constructor that makes the tuple from given values of comparisons and false positives
    tuple(int c, int f);
    // Function to retrieve comparisons or false positives from the tuple
    int get(int i);
    virtual ~tuple();

protected:
private:
    int comp;
    int falsepos;
};

#endif // TUPLE_H
