#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   MODULE 1: UTILITIES (Reusable helpers)
   ========================================================= */
#ifndef UTILITIES_H
#define UTILITIES_H

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

void pauseScreen(void) {
    printf("\nPress Enter to continue...");
    getchar();
}
#endif


/* =========================================================
   MODULE 2: EMPLOYEES (Employee operations)
   ========================================================= */
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
int employeeIds[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][50];
double employeeSalaries[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached!\n");
        return;
    }
    printf("Enter Employee ID: ");
    employeeIds[employeeCount] = getIntInput();
    
    printf("Enter Employee Name (No spaces): ");
    scanf("%49s", employeeNames[employeeCount]);
    clearInputBuffer();
    
    printf("Enter Salary: ");
    while (scanf("%lf", &employeeSalaries[employeeCount]) != 1) {
        clearInputBuffer();
        printf("Invalid. Enter a number: ");
    }
    clearInputBuffer();
    
    employeeCount++;
    printf("Employee added successfully.\n");
}

void listEmployees(void) {
    if (employeeCount == 0) {
        printf("No employees found.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", 
               employeeIds[i], employeeNames[i], employeeSalaries[i]);
    }
}
#endif


/* =========================================================
   MODULE 3: MAIN (Application flow and coordinator)
   ========================================================= */
#ifndef MAIN_H
#define MAIN_H

void displayMenu(void) {
    printf("\n=== MFMS (Week 9) ===\n");
    printf("1. Add Employee\n");
    printf("2. List Employees\n");
    printf("0. Exit\n");
    printf("Select an option: ");
}

int main(void) {
    int choice;
    do {
        displayMenu();
        choice = getIntInput();
        
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);
    
    return 0;
}
#endif