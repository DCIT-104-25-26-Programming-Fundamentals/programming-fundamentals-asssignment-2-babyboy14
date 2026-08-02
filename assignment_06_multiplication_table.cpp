// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// PART A — Print Multiplication Table for a Single Number (1 to 12)
void printTable(int num) {
    // Input validation for Part A function
    if (num <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return;
    }

    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i << "  =  " << (num * i) << endl;
    }
}

// PART B — Print Multiplication Tables for All Numbers from 1 to N
void printTablesUpTo(int n) {
    // Input validation for Part B function
    if (n <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        printTable(i); // Reuse Part A function to print table for 'i'
        
        // Print separator line between tables
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    cout << "=========================================" << endl;
    cout << "     MULTIPLICATION TABLE GENERATOR      " << endl;
    cout << "=========================================" << endl;

    // -------------------------------------------------------------------------
    // PART A DEMONSTRATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART A: Single Table ---" << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    printTable(num);

    // -------------------------------------------------------------------------
    // PART B DEMONSTRATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART B: Tables from 1 to N ---" << endl;
    int limit;
    cout << "Enter a number N: ";
    cin >> limit;

    printTablesUpTo(limit);

    return 0;
}

