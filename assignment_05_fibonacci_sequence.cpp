// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


// PART A — Print the First N Terms of the Fibonacci Sequence
void printFibonacci(int n) {
    // Input validation: N must be a positive integer
    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return;
    }

    long long first = 0, second = 1;

    cout << "Fibonacci sequence: ";

    if (n >= 1) {
        cout << first;
    }
    if (n >= 2) {
        cout << " " << second;
    }

    // Loop to compute and print terms from 3 to N
    for (int i = 3; i <= n; i++) {
        long long next = first + second;
        cout << " " << next;
        first = second; // Move forward in sequence
        second = next;
    }
    cout << endl;
}

// PART B — Check if a Number Belongs to the Fibonacci Sequence
bool isFibonacci(long long num) {
    if (num < 0) {
        return false; // Negative numbers are not in the standard sequence
    }

    long long first = 0, second = 1;

    // Base cases (0 and 1)
    if (num == first || num == second) {
        return true;
    }

    // Generate sequence terms iteratively until we reach or pass num
    long long next = first + second;
    while (next <= num) {
        if (next == num) {
            return true; // Match found!
        }
        first = second;
        second = next;
        next = first + second;
    }

    return false; // Reached past 'num' without finding a match
}

int main() {
    cout << "=========================================" << endl;
    cout << "      FIBONACCI SEQUENCE GENERATOR       " << endl;
    cout << "=========================================" << endl;

    // -------------------------------------------------------------------------
    // PART A DEMONSTRATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART A: Print First N Terms ---" << endl;
    int n;
    cout << "How many terms? ";
    cin >> n;

    printFibonacci(n);

    // -------------------------------------------------------------------------
    // PART B DEMONSTRATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART B: Check Fibonacci Number ---" << endl;
    long long checkNum;
    cout << "Enter a number to check: ";
    cin >> checkNum;

    if (isFibonacci(checkNum)) {
        cout << checkNum << " is a Fibonacci number." << endl;
    } else {
        cout << checkNum << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
