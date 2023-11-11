/*
 * Convert a C program to C++
 *
 * This program converts a C-style array and sum function into C++ using vectors,
 * inline functions, and C++ style IO.
 *
 * Author: Alan Hu
 * Date: 11-8-2023
 * Course: C++ For C Programmers, Part A
 */

#include <iostream>
#include <vector>

// Define the number of elements as a constant.
const int NUM_ELEMENTS = 40;

/**
 * Sums the elements of a vector.
 * @param sum Reference to an integer where the sum will be stored.
 * @param data A vector of integers to sum.
 */
inline void sum(int& sum, const std::vector<int>& data) {
    sum = 0; // Initialize the sum to zero.
    // Use a range-based for loop for more elegant and clear iteration over the vector elements.
    for (int num : data) {
        sum += num; // Add each number to the sum.
    }
}

int main() {
    int total = 0; // This will hold the sum of the vector's elements.
    std::vector<int> data(NUM_ELEMENTS); // Vector to store the numbers.

    // Initialize the vector with values from 0 to NUM_ELEMENTS - 1.
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        data[i] = i;
    }

    // Calculate the sum of the vector's elements.
    sum(total, data);

    // Output the result using C++ I/O streams.
    std::cout << "The sum is " << total << std::endl;

    return 0; // Indicate successful completion of the program.
}
