#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================================
   WEEK 12: POINTERS (Combined implementation)
   ========================================================= */

#ifndef POINTERS_LAB_H
#define POINTERS_LAB_H

#define MAX_EMPLOYEES 5

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

// --- Utilities ---
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getIntInput(void) {
    int value;
    while (scanf("%d", &value) != 1) {
        clearInputBuffer(); printf("Invalid: ");
    }
    clearInputBuffer(); return value;
}

double getDoubleInput(void) {
    double value;
    while (scanf("%lf", &value) != 1) {
        clearInputBuffer(); printf("Invalid: ");
    }
    clearInputBuffer(); return value;
}

// --- Part B: Swap Salaries ---
// The wrong way (pass by value)
void swapWrong(double a, double b) {
    double temp = a; a = b; b = temp;
}

// The right way (pass by address/pointer)
void swapSalaries(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// --- Part C: Pass Arrays to Functions ---
void displaySalaries(const double salaries[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n) {
    double highest = salaries[0];
    for (int i = 1; i < n; i++) {
        if (salaries[i] > highest) highest = salaries[i];
    }
    return highest;
}

double calculateAverage(const double salaries[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) total += salaries[i];
    return total / n;
}

void giveRaise(double salaries[], int n, double percent) {
    for (int i = 0; i < n; i++) {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

// --- Part D: Modify Employee Records (Arrow Operator) ---
void updateSalary(Employee *e, double newSalary) {
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i]; // Return the address (pointer)
        }
    }
    return NULL; // Not found
}

// --- Menu System ---
void displayMenu(void) {
    printf("\n=== MFMS (Week 12: Pointers) ===\n");
    printf("1. Demonstrate Swap (Wrong vs Right)\n");
    printf("2. Display Salaries & Find Highest/Average\n");
    printf("3. Give 10%% Raise (Modify Array via Pointer)\n");
    printf("4. Update Employee Salary (Find via Pointer)\n");
    printf("0. Exit\nSelect: ");
}

int main(void) {
    int choice;
    double salaries[3] = {15000.00, 18500.50, 21000.75};
    
    Employee staff[MAX_EMPLOYEES] = {
        {1001, "Maria", 18500.50},
        {1002, "Simon", 17200.00},
        {1003, "Anna",  21000.75}
    };
    int staffCount = 3;

    do {
        displayMenu();
        choice = getIntInput();

        switch (choice) {
            case 1: {
                printf("\nBefore swap: Sal[0]=%.2f, Sal[2]=%.2f\n", salaries[0], salaries[2]);
                swapWrong(salaries[0], salaries[2]);
                printf("After swapWrong (Fails): Sal[0]=%.2f, Sal[2]=%.2f\n", salaries[0], salaries[2]);
                swapSalaries(&salaries[0], &salaries[2]);
                printf("After swapSalaries (Works): Sal[0]=%.2f, Sal[2]=%.2f\n", salaries[0], salaries[2]);
                break;
            }
            case 2: {
                printf("\n--- Array Functions ---\n");
                displaySalaries(salaries, 3);
                printf("Highest: N$%.2f\n", findHighest(salaries, 3));
                printf("Average: N$%.2f\n", calculateAverage(salaries, 3));
                break;
            }
            case 3: {
                printf("\nBefore Raise:\n");
                displaySalaries(salaries, 3);
                giveRaise(salaries, 3, 10.0);
                printf("\nAfter 10%% Raise (Original array modified):\n");
                displaySalaries(salaries, 3);
                break;
            }
            case 4: {
                printf("\nEnter Employee ID to update: ");
                int id = getIntInput();
                Employee *found = findEmployee(staff, staffCount, id);
                
                if (found != NULL) {
                    printf("Found: %s (Current: %.2f)\n", found->name, found->salary);
                    printf("Enter new salary: ");
                    double newSal = getDoubleInput();
                    updateSalary(found, newSal);
                    printf("Updated! %s now earns %.2f\n", found->name, found->salary);
                } else {
                    printf("Employee with ID %d not found.\n", id);
                }
                break;
            }
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    
    return 0;
}
#endif