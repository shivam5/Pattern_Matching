*********************************************************************************************************************************

PROJECT DETAILS
This project implements hash tables and string matching using RabinKarp algorithm.


Task
---------
You task is to implement the Rabin­Karp algorithm using: 
(1) all four hash codes  
(Integer casting, Component sum, Polynomial sum, Cyclic sum) and 

(2) all three hash  
functions (Division, MAD, Multiplication). You can use linear probing to handle  
collisions. For each of the cases above (there will be 12), count: 
* False positives. The number of times hash value matches but not the actual  
string. 
* Comparisons: The number of string comparisons including the one’s that return  
true. 
Input will be given as a raw text file. The pattern will be given to you during the demo.  
The output should be two 4X3 matrices. You should display as well as store the results  
in a file named EntryNumOutput1.txt. 
 
Modify the the above algorithm (and program) to be able to search for  
incomplete words. You would like to type in something like ?orcius and have the  program match this pattern quickly to the correct answer Porcius. 

*********************************************************************************************************************************

AUTHOR
Shivam Mittal
2nd year B.Tech Computer Science Engineering, IIT Ropar
Email - 2015csb1032@iitrpr.ac.in
Github profile - github.com/shivam5

*********************************************************************************************************************************

IMPLEMENTATION
ALl the questions are implemented in C++ language.
Hashing method used : Separate Chaining

*********************************************************************************************************************************

COMPILING AND RUNNING PROGRAM
1. Extract the contents of this archive in a folder.
2. Navigate to the folder which contains all these files using cd commands.
3. Type make and press enter. This will automatically compile the necessary file  and links them and create a file 'run' which is necessary executable file.
4. Type ./run on linux (run on windows) and press enter. 
5. The program would run, just follow the instructions from there.
6. You would have enter the question number, the text files for the test and pattern string, and the length of the pattern string (assumed to be constant)
7. The length of the pattern string is taken as input and not calculated, because in the question it was mentioned to first hash the test string and then open the pattern string.

*********************************************************************************************************************************

FILE INFORMATION

Header Files -  node.h -> Defines a node class to be used in linked list 
		functions.h -> Header file for general functions used throughout the assignment
		tuple.h -> Defines tuple class, for storing and returning the comparisons and false positive for a particular search
		linkedlist.h -> Defines Linked list class (Maintains buckets)
		hashtable.h -> Defines hashtable class, implemented using separate chaining (Linked List method)

CPP Files -   main.cpp -> Contains the main program
		node.h -> Defines functions for the node class 
		functions.h -> Defines general functions
		tuple.h -> Defines functions for the tuple class
		linkedlist.h -> Defines functions for the linkedlist class
		hashtable.h -> Defines functions for the hashtable class

Text Files-		T1.txt - Test string file for Q1
		P1.txt - Pattern string file for Q1
		T2.txt - Test string file for Q2
		P2.txt - Pattern string file for Q2
		2015csb1032Output1.txt -> Output file for Q1
		2015csb1032Output2.txt -> Output file for Q2
		Readme.txt -> Inception :3


Makefile - File used to compile and link all the various cpp files in one go - Easy compilation.



THANK YOU

***********************************************************************************************************************************