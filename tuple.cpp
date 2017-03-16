#include "tuple.h"

// Constructor that makes the tuple from given values of comparisons and false positives
tuple::tuple(int c, int f)
{
    comp = c;
    falsepos = f;
}

// Function to retrieve comparisons or false positives from the tuple
// If i=0, return the comparisons else returns the false positives
int tuple::get(int i)
{
    if (i == 0)
        return comp;
    return falsepos;
}

tuple::~tuple()
{
    //dtor
}
