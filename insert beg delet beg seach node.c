#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the employee structure
struct employee {
    int id;
    char name[50];
    float sal;
    struct employee* next;
};

// Function to insert an employee at the beginning of the list
void insertAtBeginning(struct employee** head, int id, char name[], float sal) {
    struct employee* newEmployee = (struct employee*)malloc(sizeof(struct employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->sal = sal;
    newEmployee->next = *head;
    *head = newEmployee;
}

// Function to delete the first employee from the list
void deleteFromBeginning(struct employee** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct employee* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to search for an employee by ID
struct employee* searchEmployee(struct employee* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to display all employees in the list
void displayEmployees(struct employee* head) {
    while (head != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", head->id, head->name, head->sal);
        head = head->next;
    }
}

int main() {
    struct employee* head = NULL;

    // Get input from user
    int id;
    char name[50];
    float sal;

    printf("Enter ID: ");
    scanf("%d", &id);

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter Salary: ");
    scanf("%f", &sal);

    // Insert the employee at the beginning
    insertAtBeginning(&head, id, name, sal);

    // Display employees
    printf("Employees:\n");
    displayEmployees(head);

    // Search for an employee by ID
    int searchId;
    printf("\nEnter ID to search: ");
    scanf("%d", &searchId);

    struct employee* foundEmployee = searchEmployee(head, searchId);
    if (foundEmployee != NULL) {
        printf("\nEmployee with ID %d found: Name: %s, Salary: %.2f\n", 
                foundEmployee->id, foundEmployee->name, foundEmployee->sal);
    } else {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }

    // Delete an employee from the beginning
    deleteFromBeginning(&head);

    // Display employees after deletion
    printf("\nEmployees after deletion:\n");
    displayEmployees(head);

    // Free allocated memory
    while (head != NULL) {
        struct employee* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

