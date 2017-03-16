#include "hashtable.h"

// Parameterized constructor initializing the table and taking size as a parameter
hashtable::hashtable(int size)
{
    // Making hash table of the size mentioned, basically size number of linked lists
    table = new linkedlist[size];
}

// Hashcode function (Converting the string to an integer value)
unsigned int hashtable::hashcode(string word, int select1, int m)
{
    //select1 = 0 : Integer casting
    //select1 = 1 : Component sum
    //select1 = 2 : Polynomial sum
    //select1 = 3 : Cyclic sum

    // Variable to calculate the hashcode (Kept unsigned to prevent overflows in component sum method)
    unsigned int hashcode = 0;
    // x is the variable used in the polynomial hashcode calculation
    int a, b, i, x = 33;

    // Select the hashcode function  according to the select1 value
    switch (select1) {

    // Integer casting
    case 0:
        // We have to take 4 bits at a time, so there will be m/4 iterations
        for (i = 0; i <= (m / 4); i++) {
            a = 0, b = 4;
            // If it is the last iteration
            if (i == (m / 4))
                // Take m%4 bits, which may not necesarrily be 3 always
                b = (m % 4);
            for (int j = 0; j < b; j++)
                a = (a * 256) + word[i * 4 + j];
            hashcode += a;
        }
        return hashcode;
        break;

    //Component Sum
    case 1:
        // Hashcode is just the ASCII values added
        for (i = 0; i < m; i++)
            hashcode += word[i];
        return hashcode;
        break;

    // Polynomial Sum
    case 2:
        // Calculating the polynomial value taking x as defined above
        for (i = 0; i < m; i++)
            hashcode = (hashcode * x) + word[i];
        return hashcode;
        break;

    // Cyclic Sum
    case 3:
        // Same as integer casting with difference in cycling
        for (i = 0; i <= (m / 4); i++) {
            a = 0, b = 4;
            if (i == (m / 4))
                b = (m % 4);
            for (int j = 0; j < b; j++)
                a = (a * 256) + word[i * 4 + j];
            // Make a cyclic shift of 5 bits
            hashcode = (hashcode << 5) | (hashcode >> 27);
            hashcode += a;
        }
        return hashcode;
        break;

    default:
        return 0;
        break;

    } //switch
} //hashcode function

// Compression function, converting the hashcode value to an index
int hashtable::compression(unsigned int hashcode, int select2, int size)
{
    //select2 = 0 : Division
    //select2 = 1 : MAD
    //select2 = 2 : Multiplication
    int a, b;
    // Taking a and b for MAD
    a = (size - 1);
    b = (size - 2);
    // Calculating A for multiplication function
    double A = (sqrt(5) - 1) / 2, B;

    // Selecting the compression function based on select2 value
    switch (select2) {

    // Division method
    case 0:
        return hashcode % size;
        break;

    // MAD (Multiplication addition Division) method
    case 1:
        return ((a * hashcode) + b) % size;
        break;

    // Multiplication method
    case 2:
        return floor(size * (modf((hashcode * A), &B)));
        break;

    default:
        return 0;
        break;
    }
}

// Hash function
// Calculates the hash values of a substring and then adds to the hash table
void hashtable::hash(string st, int size, int select1, int select2, int m, int n)
{
    int hashf;
    // The individual m letter word that needs to be hashed
    string word;

    for (int i = 0; i < (n - m + 1); i++) {
        // The individual word is a m lettered substring starting from position i of the string st
        word = st.substr(i, m);
        // Calculate the hash value of word
        hashf = compression(hashcode(word, select1, m), select2, size);
        // Add the word in bucket indexed the hash value
        table[hashf].add(i);
    }
}

// Finds a substring in the hash table and returns the false positive and comparisons value (for Q1)
tuple* hashtable::find(string P, string st, int size, int select1, int select2, int m)
{
    int val;
    // Find the hash value for pattern string P, first calculate hashcode, then hash value
    val = compression(hashcode(P, select1, m), select2, size);
    // Use the linked list search and return the tuple containing the no of comparisons and false positive
    return table[val].search(P, st, m);
}

// Finds a subtring in the hash table and outputs the pattern matches (for Q2)
int hashtable::findin(string P, string st, int size, int select1, int select2, int m, ofstream& fout2)
{
    int val;
    // Find the hash value for pattern string P, first calculate hashcode, then hash value
    val = compression(hashcode(P, select1, m), select2, size);
    // Use the linked list search, that display pattern found at each index and
    // and returns the no of matches (although not being used)
    // Passing the file pointer as argument to write the result
    return table[val].searchin(P, st, m, fout2);
}

// Destructor, deletes table when object goes out of scope
hashtable::~hashtable()
{
    delete table;
}
