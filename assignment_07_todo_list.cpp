// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display the main menu options
void showMenu() {
    cout << "\n============================" << endl;
    cout << "     TO-DO LIST MENU        " << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Function to add a task to the vector
void addTask(vector<string>& tasks) {
    cout << "Enter task: ";
    cin.ignore(); // Clear newline character from buffer
    string task;
    getline(cin, task);
    
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

// Function to display all current tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "\nYour to-do list is empty!" << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

// Function to delete a task by its 1-based index number
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "\nYour to-do list is empty. Nothing to delete." << endl;
        return;
    }

    // First display current tasks so user knows the numbers
    viewTasks(tasks);

    int taskNum;
    cout << "\nEnter task number to delete: ";
    cin >> taskNum;

    // Validate if the number corresponds to a valid 1-based index
    if (taskNum < 1 || taskNum > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number!" << endl;
    } else {
        string removedTask = tasks[taskNum - 1];
        tasks.erase(tasks.begin() + (taskNum - 1)); // Remove element from vector
        cout << "Task \"" << removedTask << "\" has been removed." << endl;
    }
}

int main() {
    vector<string> tasks;
    int choice = 0;

    // Menu loop continues running until choice 4 (Quit) is selected
    while (choice != 4) {
        showMenu();
        cin >> choice;

        // Check for non-numeric or invalid input stream state
        if (cin.fail()) {
            cin.clear();            // Clear input error flag
            cin.ignore(1000, '\n'); // Discard invalid characters
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
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

