// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Requirement: Define the Student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Helper function to calculate a student's average score
double getAverageScore(const Student& s) {
    if (s.scores.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double score : s.scores) {
        sum += score;
    }
    return sum / s.scores.size();
}

// Function to display the main menu options
void showMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// FEATURE 1: Add a Student
void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Student name: ";
    cin.ignore(); // Clear newline buffer
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

// FEATURE 2: Display All Students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available." << endl;
        return;
    }

    cout << "\n----------------------------------------------------------------------" << endl;
    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(25) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (const auto& student : students) {
        // Build scores string
        string scoresStr = "";
        for (size_t i = 0; i < student.scores.size(); i++) {
            scoresStr += to_string((int)student.scores[i]);
            if (i + 1 < student.scores.size()) {
                scoresStr += ", ";
            }
        }

        cout << left << setw(10) << student.id
             << setw(20) << student.name
             << setw(25) << scoresStr
             << fixed << setprecision(2) << getAverageScore(student) << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}

// FEATURE 3: Calculate Average Score for a Specific Student
void calculateAverageByID(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available." << endl;
        return;
    }

    int searchID;
    cout << "Enter student ID: ";
    cin >> searchID;

    for (const auto& student : students) {
        if (student.id == searchID) {
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: " << getAverageScore(student) << endl;
            return;
        }
    }

    cout << "Error: Student ID " << searchID << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageByID(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid menu option (1-4)." << endl;
                break;
        }
    }

    return 0;
}

