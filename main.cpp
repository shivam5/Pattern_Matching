// ASSIGNMENT 3
// PATTERN MATCHING USING ROBIN KARP ALGORITHM
// SEPARATE CHAINING METHOD USED
// MADE BY SHIVAM MITTAL (2015CSB1032)
// Note : The code may seem large, it actually isn't, it may be due to excessive documentation for better understanding

#include <fstream>
#include <cstring>
#include "hashtable.h"

using namespace std;

int main()
{

    // Ifstream objects for opening files
    ifstream fin1, fin2, fin3;
    // Ofstream object for writing the result
    ofstream fout1, fout2;

    // STRING DEFINITIONS
    // String st to store the long testing string
    // st1 is the intermediate string used in getting st
    // P is the string which stores the pattern being compared
    // tes is the name of the text file which contains the text string
    // pat is the name of the text file which contains the patterns
    string st = "", st1, P, tes, pat;

    // INTEGER DEFINITIONS
    // n stores the length of the test string (st)
    // m stores the length of the pattern string (P)
    // sizeprime is the size of the hash table used for division and MAD compression function (smallest prime number > n)
    // sizetwo is the size of the hash table used for Multiplication compression function (next power of two > n)
    // select1 is used to select the hashcode function
    // select2 is used to select the compression function
    // i is used as iterator at places
    int n, m = 6, sizeprime, sizetwo, select1, select2, i, answer;

    // Standard input output
    cout << "Enter the question number (1/2)\n";
    cin >> answer;
    cout << "Enter the file names of Testing string and Pattern String\n";
    cin >> tes >> pat;
    cout << "Enter the length of the pattern string (m)\n";
    cin >> m;

    // Opening the text file for reading the test string
    fin1.open(tes.c_str());
    //While we do need reach the end of file, getline in st1 and concencatenate it with the st
    while (!fin1.eof()) {
        getline(fin1, st1);
        st = st + st1;
    }
    //Close the text file
    fin1.close();

    //Calculating the length of the test string
    n = st.length();

    // Calculating nextprime and nexttwo for the hash table size,
    // nexttwo is used for multiplication, prime for MAD and division
    sizetwo = nexttwo(n);
    sizeprime = nextprime(n);

    //If the question to be evaluated is the first
    if (answer == 1) {

        // Constructing 8 hash tables of sizeprime (4 for MAD compression, 4 for division compression)
        hashtable* primetable[8];
        for (i = 0; i < 8; i++)
            primetable[i] = new hashtable(sizeprime);

        // Constructing 4 hash tables of sizetwo for multiplication compression
        hashtable* twotable[4];
        for (i = 0; i < 4; i++)
            twotable[i] = new hashtable(sizetwo);

        // Hashing the string(substrings of size m) into the hash table of sizeprime
        // select1 and select2 are passed as arguments to choose the hash code and compression method
        for (select2 = 0; select2 < 2; select2++) {
            for (select1 = 0; select1 < 4; select1++)
                primetable[select2 * 4 + select1]->hash(st, sizeprime, select1, select2, m, n);
        }

        // Hashing the string(substrings of size m) into the hash table of sizetwo
        // select1 and select2 are passed as arguments to choose the hash code and compression method
        select2 = 2;
        for (select1 = 0; select1 < 4; select1++)
            twotable[select1]->hash(st, sizetwo, select1, select2, m, n);

        // Opening the file to write the results
        fout1.open("2015csb1032Output1.txt");

        // Creating a tuple object which will store the comparisons and false positive
        // for a particular substring and a particular hash code and compression function at a time
        tuple* compfalse;

        // Matrices to store comparisons and false positives
        int scomp[4][3], sfalsepos[4][3], comp[4][3], falsepos[4][3];

        // Initiliaze both the 2D arrays with 0
        for (select2 = 0; select2 < 3; select2++) {
            for (select1 = 0; select1 < 4; select1++) {
                scomp[select1][select2] = 0;
                sfalsepos[select1][select2] = 0;
            }
        }

        // Open the text file containing the patterns
        fin2.open(pat.c_str());

        // Read the text file until you reach the end
        while (!fin2.eof()) {
            // Read one substring to be tested at a time
            fin2 >> P;

            // To printout the matches of pattern at respective indexes
            // Using hashcode function - polynomial sum and compression function - MAD
            select1 = 2;
            select2 = 1;
            cout << "********************************************************************************************\nFor pattern :" << P << endl;
            fout1 << "********************************************************************************************\nFor pattern :" << P << endl;
            primetable[select2 * 4 + select1]->findin(P, st, sizeprime, select1, select2, m, fout1);

            // Iterating over compression function MAD and division (sizeprime table)
            for (select2 = 0; select2 < 2; select2++) {
                for (select1 = 0; select1 < 4; select1++) {
                    // Finding the substring P in string st using the hashtable constructed by different hashcode and compression functions
                    // Storing the comparisons and false positive in the tuple compfalse
                    compfalse = primetable[select2 * 4 + select1]->find(P, st, sizeprime, select1, select2, m);
                    //Extracting the value of comparisons and falsepositive from tuple and storing it in respective array
                    comp[select1][select2] = compfalse->get(0);
                    falsepos[select1][select2] = compfalse->get(1);
                    scomp[select1][select2] += comp[select1][select2];
                    sfalsepos[select1][select2] += falsepos[select1][select2];
                }
            }

            // Iterating over compression function Multiplication (sizetwo table)
            select2 = 2;
            for (select1 = 0; select1 < 4; select1++) {
                // Finding the substring P in string st using the hashtable constructed by different hashcode and compression functions
                // Storing the comparisons and false positive in the tuple compfalse
                compfalse = twotable[select1]->find(P, st, sizetwo, select1, select2, m);
                //Extracting the value of comparisons and falsepositive from tuple and storing it in respective array
                comp[select1][select2] = compfalse->get(0);
                falsepos[select1][select2] = compfalse->get(1);
                scomp[select1][select2] += comp[select1][select2];
                sfalsepos[select1][select2] += falsepos[select1][select2];
            }

            cout << "False Positives: \n";
            fout1 << "False Positives: \n";
            for (select1 = 0; select1 < 4; select1++) {
                for (select2 = 0; select2 < 3; select2++) {
                    cout << sfalsepos[select1][select2] << "\t";
                    fout1 << sfalsepos[select1][select2] << "\t";
                }
                cout << endl;
                fout1 << endl;
            }

            cout << "\nComparisons: \n";
            fout1 << "\nComparisons: \n";
            for (select1 = 0; select1 < 4; select1++) {
                for (select2 = 0; select2 < 3; select2++) {
                    cout << scomp[select1][select2] << "\t";
                    fout1 << scomp[select1][select2] << "\t";
                }
                cout << endl;
                fout1 << endl;
            }
            cout << endl;
            fout1 << endl;
        }

        //Closing the input file
        fin2.close();

        // Displaying the False positives and Comparisons
        // Hash codes are rows
        // Compression functions are columns

        cout << "*********************************************************************\nTotal Sum of false positives and Comparisons: \n";
        fout1 << "*********************************************************************\nTotal Sum of false positives and Comparisons: \n";
        cout << "\nFalse Positives: \n";
        fout1 << "\nFalse Positives: \n";
        for (select1 = 0; select1 < 4; select1++) {
            for (select2 = 0; select2 < 3; select2++) {
                cout << sfalsepos[select1][select2] << "\t";
                fout1 << sfalsepos[select1][select2] << "\t";
            }
            cout << endl;
            fout1 << endl;
        }

        cout << "\nComparisons: \n";
        fout1 << "\nComparisons: \n";
        for (select1 = 0; select1 < 4; select1++) {
            for (select2 = 0; select2 < 3; select2++) {
                cout << scomp[select1][select2] << "\t";
                fout1 << scomp[select1][select2] << "\t";
            }
            cout << endl;
            fout1 << endl;
        }
        cout << endl;
        fout1 << endl;

        // Closing the output text file
        fout1.close();
    }

    //If the question to be evaluated is the second
    else if (answer == 2) {

        // Using hashcode function - polynomial sum and compression function - MAD
        select1 = 2;
        select2 = 1;

        // Constructing hash tables of sizeprime (for MAD compression)
        hashtable* ptable;
        ptable = new hashtable(sizeprime);

        // Hashing the string(substrings of size m) into the hash table of sizeprime
        // select1 and select2 are passed as arguments to choose the hash code and compression method
        ptable->hash(st, sizeprime, select1, select2, m, n);

        ofstream fout2;
        // Opening the file to write the results
        fout2.open("2015csb1032Output2.txt");

        // Opening the file contains the patterns
        fin3.open(pat.c_str());
        // Read till end of file
        while (!fin3.eof()) {
            fin3 >> P;

            // Flag here represents existence of a question mark in the pattern string
            int flag = 0;

            // Iterate over the pattern string
            for (i = 0; i < m; i++) {

                // If a question mark is found
                if (P[i] == '?') {
                    // Set flag to 1 (Question marks present in string)
                    flag = 1;
                    // Set the question mark to all the ascii characters, starting from 0
                    // We are considering all ascii characters not just alphabets,
                    // because there are commas(in the file given) or there may be other symbols present in the test file
                    P[i] = 0;
                    while (P[i] <= 126) {
                        // For each question mark set to some ascii value, search the string using hash table
                        ptable->findin(P, st, sizeprime, select1, select2, m, fout2);
                        P[i]++;
                    }
                }
            }

            // If no question mark, found in the pattern string, search the pattern as it is,
            // Passing the file pointer as argument to write the result
            if (flag == 0)
                ptable->findin(P, st, sizeprime, select1, select2, m, fout2);
        }

        // Close the text file
        fin3.close();
        fout2.close();
    }

    // If 1 or 2 is not entered as the input for question number
    else {
        cout << "Wrong input for question number\n";
    }

    return 0;
}
