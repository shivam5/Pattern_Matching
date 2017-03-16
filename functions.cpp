#include "functions.h"

// To calculate n^i
int pow(int n, int i)
{
    int pro = 1;
    for (; i > 0; i--)
        pro = pro * n;
    return pro;
}

// To calculate the next power of 2 after n
int nexttwo(int n)
{
    int i;
    for (i = 0; n > 0; i++)
        n /= 2;
    return pow(2, i);
}

// To check if a number is prime
bool checkprime(int n)
{
    int x = sqrt(n), i;
    for (i = 2; i <= x; i++) {
        if ((n % i) == 0)
            return false;
    }
    return true;
}

// To calculate the next prime number after a given number
int nextprime(int n)
{
    int i;
    for (i = n; i < (2 * n); i++) {
        if (checkprime(i))
            return i;
    }
}

// To compare to strings of given length
int scomp(string a, string b, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] != b[i])
            return 1;
    }
    return 0;
}