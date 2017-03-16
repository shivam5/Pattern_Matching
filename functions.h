#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <math.h>
#include <string>

using namespace std;

// General functions used throughout the assignment

// To calculate n^i
int pow(int n, int i);
// To calculate the next power of 2 after n
int nexttwo(int n);
// To check if a number is prime
bool checkprime(int n);
// To calculate the next prime number after a given number
int nextprime(int n);
// To compare to strings of given length
int scomp(string a, string b, int size);

#endif // FUNCTIONS_H
