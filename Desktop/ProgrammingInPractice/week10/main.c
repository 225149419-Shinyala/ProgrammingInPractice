#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   MODULE 1: UTILITIES
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
#endif


/* =========================================================
   MODULE 2: EMPLOYEES (With Week 10 File Handling)
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
    employeeSalaries[employeeCount] = getDoubleInput();
    
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

void saveEmployeesToFile(void) {
    FILE *fp = fopen("data/employees.txt", "w");
    if (fp == NULL) {
        perror("Error opening data/employees.txt for writing");
        return;
    }
    for (int i = 0; i < employeeCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n", employeeIds[i], employeeNames[i], employeeSalaries[i]);
    }
    fclose(fp);
    printf("Successfully saved %d employees to file.\n", employeeCount);
}

void loadEmployeesFromFile(void) {
    FILE *fp = fopen("data/employees.txt", "r");
    if (fp == NULL) {
        printf("No saved employee data found.\n");
        return;
    }
    employeeCount = 0;
    while (fscanf(fp, "%d|%49[^|]|%lf\n", &employeeIds[employeeCount], employeeNames[employeeCount], &employeeSalaries[employeeCount]) == 3) {
        employeeCount++;
        if(employeeCount >= MAX_EMPLOYEES) break;
    }
    fclose(fp);
    printf("Successfully loaded %d employees from file.\n", employeeCount);
}
#endif


/* =========================================================
   MODULE 3: BUDGET (With Week 10 File Handling)
   ========================================================= */
#ifndef BUDGET_H
#define BUDGET_H

double totalRevenue = 0.0;
double totalExpenses = 0.0;

void calculateBudget(void) {
    printf("Enter Total Revenue: ");
    totalRevenue = getDoubleInput();
    printf("Enter Total Expenses: ");
    totalExpenses = getDoubleInput();
    
    printf("\n--- Budget Balance ---\n");
    printf("Balance: %.2f\n", totalRevenue - totalExpenses);
}

void saveBudgetToFile(void) {
    FILE *fp = fopen("data/budget.txt", "w");
    if (fp == NULL) {
        perror("Error opening data/budget.txt");
        return;
    }
    fprintf(fp, "%.2f|%.2f\n", totalRevenue, totalExpenses);
    fclose(fp);
    printf("Budget saved to file.\n");
}

void loadBudgetFromFile(void) {
    FILE *fp = fopen("data/budget.txt", "r");
    if (fp == NULL) {
        printf("No saved budget found.\n");
        return;
    }
    if (fscanf(fp, "%lf|%lf", &totalRevenue, &totalExpenses) == 2) {
        printf("Budget loaded: Revenue=%.2f, Expenses=%.2f\n", totalRevenue, totalExpenses);
    }
    fclose(fp);
}
#endif


/* =========================================================
   MODULE 4: MAIN (Coordinator)
   ========================================================= */
#ifndef MAIN_H
#define MAIN_H

void displayMenu(void) {
    printf("\n=== MFMS (Week 10) ===\n");
    printf("1. Add Employee\n");
    printf("2. List Employees\n");
    printf("3. Calculate Budget\n");
    printf("4. Save All Data\n");
    printf("5. Load All Data\n");
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
            case 3: calculateBudget(); break;
            case 4: 
                saveEmployeesToFile(); 
                saveBudgetToFile(); 
                break;
            case 5: 
                loadEmployeesFromFile(); 
                loadBudgetFromFile(); 
                break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);
    return 0;
}
#endif