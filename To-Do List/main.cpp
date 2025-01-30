#include <iostream>

using namespace std;

// Structure to hold task details
struct List
{
    unsigned int taskPriority; // Priority of the task
    string taskDescription;    // Description of the task
    string taskStatus;         // Status of the task (Pending/Completed)
};

// Node structure for linked list implementation
struct node
{
    List data;    // Task data
    node *next;   // Pointer to the next node in the list
};

// Head pointer for the linked list
node *head = nullptr;

// Function declarations
void addTask(const List *const ptr);
void viewTasks(void);
void markTaskCompleted(string description);

int main(void)
{
    List userTasks;
    unsigned int choice = 0;
    string userTaskDescription;

    // Menu loop
    while (choice >= 0 && choice < 4)
    {
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Exit\n";
        cout << "----------------------------\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cout << "----------------------------\n";

        switch (choice)
        {
        case 1:
            cout << "Enter Task Description: ";
            cin.ignore(); // Clear the leftover newline from the buffer
            getline(cin, userTasks.taskDescription);
            cout << "Enter Task Priority: ";
            cin >> userTasks.taskPriority;
            userTasks.taskStatus = "Pending"; // Default status is "Pending"
            addTask(&userTasks);
            break;
        case 2:
            viewTasks(); // Display all tasks
            break;
        case 3:
            cout << "Enter Task Description: ";
            cin.ignore(); // Clear the leftover newline from the buffer
            getline(cin, userTaskDescription);
            markTaskCompleted(userTaskDescription);
            break;
        case 4:
            cout << "End Of Program... Good Bye!\n";
            break;
        }
    }
}

// Function to add a task to the linked list
void addTask(const List *const ptr)
{
    cout << "----------------------------\n";
    node *current = nullptr;
    node *link = new node; // Create a new node

    if (ptr == nullptr)
    {
        cout << "ERROR: Invalid task data\n";
        cout << "----------------------------\n";
        return;
    }

    link->data = *ptr; // Copy task data into the node
    link->next = nullptr;

    // If list is empty, make new node the head
    if (head == nullptr)
    {
        head = link;
        return;
    }

    current = head;

    // Traverse to the end of the list
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = link; // Add new node at the end
}

// Function to display all tasks
void viewTasks(void)
{
    node *current = head;

    if (head == nullptr)
    {
        cout << "There are no Tasks\n";
        cout << "----------------------------\n";
        return;
    }

    // Traverse and print each task
    while (current != nullptr)
    {
        cout << "[ Priority: " << current->data.taskPriority
             << ", Task: " << current->data.taskDescription
             << ", Status: " << current->data.taskStatus
             << " ]\n";
        current = current->next;
    }

    cout << "----------------------------\n";
}

// Function to mark a task as completed based on description
void markTaskCompleted(string description)
{
    node *current = head;
    bool found = false;

    if (head == nullptr)
    {
        cout << "There are no Tasks\n";
        cout << "----------------------------\n";
        return;
    }

    // Traverse the list to find the task
    while (current != nullptr)
    {
        if (current->data.taskDescription == description)
        {
            current->data.taskStatus = "Completed"; // Update task status
            found = true;
            cout<<"The Task has been marked as Completed\n";
            break; // Exit loop once task is found and updated
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "This Task [ " << description << " ] is not available\n";
    }

    cout << "----------------------------\n";
}
