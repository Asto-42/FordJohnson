PmergeMe
---------------
PmergeMe is a C++ project designed to implement a custom sorting algorithm using a divide-and-conquer approach. This program takes a list of integers, pairs them, and recursively sorts and merges the pairs to achieve a fully sorted list. The project uses various templates and custom structures for sorting, allowing users to specify the comparison limits.

Features
---------------
Custom pair-based sorting algorithm
Recursive splitting and merging technique
Command-line input for list elements and sorting constraints
Efficient comparison and insertion logic

How It Works
---------------
Pairing Elements: The program splits the list of integers into pairs and compares them.

Recursive Sorting: It recursively sorts the pairs and merges them into a sorted sequence.

Comparison Optimization: It optimizes comparisons based on user-specified limits (max_comp).

Command-Line Input: Users can pass the list of integers via command-line arguments.
(For example : ./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " "`)

File Descriptions
---------------
PmergeMe.cpp: Contains the main sorting algorithm, pairing logic, and recursive merging functions.
PmergeMe.hpp: Header file defining the class and struct used in the sorting process.
