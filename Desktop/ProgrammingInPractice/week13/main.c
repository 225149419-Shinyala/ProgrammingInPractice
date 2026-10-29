#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================================
   WEEK 13: DYNAMIC MEMORY ALLOCATION
   Lab: Unlimited Employees in the MFMS
   ========================================================= */

#ifndef WEEK13_H
#define WEEK13_H

/* --- Employee Structure --- */
typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

/* =========================================================
   UTILITIES MODULE
   ========================================================= */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getIntInput(void) {
    int value;
    while (scanf("%d", &value) != 1) {
        clearInputBuffer();
        printf("Invalid input. Enter a number: ");
    }
    clearInputBuffer();
    return value;
}

double getDoubleInput(void) {
    double value;
    while (scanf("%lf", &value) != 1) {
        clearInputBuffer();
        printf("Invalid input. Enter a number: ");
    }
    clearInputBuffer();
    return value;
}

void pauseScreen(void) {
    printf("\nPress Enter to continue...");
    getchar();
}

/* =========================================================
   MAIN APPLICATION MODULE
   ========================================================= */

// Global variables for dynamic memory management
Employee *employees = NULL;
int count = 0;
int capacity = 2; // Start with room for 2 employees

// TODO 1: Allocate initial memory
void initializeArray(void) {
    employees = (Employee *)malloc(capacity * sizeof(Employee));
    if (employees == NULL) {
        printf("Out of memory!\n");
        exit(1); // Exit program if initial allocation fails
    }
}

// Function to add an employee
void addEmployee(void) {
    // TODO 2: Check if capacity is reached and resize with realloc()
    if (count == capacity) {
        int newCapacity = capacity * 2;
        Employee *bigger = (Employee *)realloc(employees, newCapacity * sizeof(Employee));
        
        if (bigger == NULL) {
            printf("Out of memory! Could not resize array.\n");
            free(employees); // Clean up before failing
            exit(1);
        }
        
        employees = bigger; // Update pointer to the new memory block
        capacity = newCapacity;
        printf("  [System: Array grown to %d slots]\n", capacity);
    }

    // TODO 3: Store employee and increment count
    printf("Enter Employee ID (0 to stop): ");
    employees[count].id = getIntInput();

    if (employees[count].id == 0) {
        return; // Stop adding if ID is 0
    }

    printf("Enter Name (No spaces): ");
    scanf("%29s", employees[count].name);
    clearInputBuffer();

    printf("Enter Salary: ");
    employees[count].salary = getDoubleInput();

    count++;
}

// Function to search for an employee by ID (Lab Task 8)
void searchEmployee(void) {
    if (count == 0) {
        printf("\nNo employees to search.\n");
        return;
    }
    
    printf("Enter Employee ID to search: ");
    int searchId = getIntInput();
    
    for (int i = 0; i < count; i++) {
        if (employees[i].id == searchId) {
            printf("\n--- Employee Found ---\n");
            printf("ID: %d\nName: %s\nSalary: N$%.2f\n", 
                   employees[i].id, employees[i].name, employees[i].salary);
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", searchId);
}

// TODO 4: Display all employees and stats
void displayEmployees(void) {
    if (count == 0) {
        printf("\nNo employees found.\n");
        return;
    }

    printf("\n%-6s %-15s %12s\n", "ID", "Name", "Salary (N$)");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-15s %12.2f\n", 
               employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("----------------------------------------\n");
    printf("Employees: %d | Capacity: %d\n", count, capacity);
}

/* =========================================================
   MAIN COORDINATOR
   ========================================================= */
void displayMenu(void) {
    printf("\n=== MFMS (Week 13: Unlimited Employees) ===\n");
    printf("1. Add Employees\n");
    printf("2. Display All Employees\n");
    printf("3. Search Employee by ID\n");
    printf("0. Exit & Free Memory\n");
    printf("Select an option: ");
}

int main(void) {
    int choice;

    // Allocate the initial memory block before starting
    initializeArray();

    do {
        displayMenu();
        choice = getIntInput();

        switch (choice) {
            case 1:
                addEmployee(); // Allows multiple additions until ID 0
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 0:
                printf("\nExiting system...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);

    // TODO 5: Free the dynamically allocated memory
    if (employees != NULL) {
        free(employees);
        employees = NULL;
        printf("Dynamic memory successfully freed.\n");
    }

    return 0;
}
#endif