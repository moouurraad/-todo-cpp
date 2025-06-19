#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Vector to store tasks in memory
vector<string> tasks;

// File where tasks will be saved
const string filename = "tasks.txt";

// Loads tasks from the file into the vector
void loadTasks() {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        tasks.push_back(line);
    }
    file.close();
}

// Saves current tasks to the file
void saveTasks() {
    ofstream file(filename);
    for (const auto& task : tasks) {
        file << task << endl;
    }
    file.close();
}

// Adds a new task entered by the user
void addTask() {
    cout << "Enter a new task: ";
    string task;
    getline(cin >> ws, task); // 'ws' clears whitespace before reading input
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}

// Displays all current tasks
void showTasks() {
    if (tasks.empty()) {
        cout << "There are no tasks at the moment.\n";
        return;
    }

    cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Deletes a task by its index
void deleteTask() {
    showTasks();
    cout << "Enter the number of the task to delete: ";
    int index;
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted.\n";
    }
}

// Menu shown to the user
void menu() {
    cout << "\n--- To-Do App ---\n";
    cout << "1. Add task\n";
    cout << "2. Show tasks\n";
    cout << "3. Delete task\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

// Main function
int main() {
    // Load previously saved tasks
    loadTasks();

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: deleteTask(); break;
            case 4:
                saveTasks();
                cout << "Tasks saved. Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
