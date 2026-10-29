#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================================
   WEEK 11: STRUCTURES (Combined implementation)
   ========================================================= */

#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

// 1. Nested Date Structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// 2. The 5 MFMS Structures
typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[40];
    char town[20];
} Supplier;

typedef struct {
    int id;
    char description[40];
    double value;
    Date acquired; // Nested structure
} Asset;

typedef struct {
    char department[20];
    double allocated;
    double spent;
} Budget;

typedef struct {
    int id;
    char title[40];
    double budget;
    Date startDate;
    Date endDate;
} Project;

#endif // RECORDS_H

/* =========================================================
   UTILITIES MODULE
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
        printf("Invalid. Enter a number: ");
    }
    clearInputBuffer();
    return value;
}

double getDoubleInput(void) {
    double value;
    while (scanf("%lf", &value) != 1) {
        clearInputBuffer();
        printf("Invalid. Enter a number: ");
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
   MAIN APPLICATION MODULE
   ========================================================= */
#ifndef MAIN_H
#define MAIN_H

// Global Arrays of Structures
Employee employees[MAX_RECORDS];
int employeeCount = 0;

Supplier suppliers[MAX_RECORDS];
int supplierCount = 0;

Asset assets[MAX_RECORDS];
int assetCount = 0;

Budget budgets[MAX_RECORDS];
int budgetCount = 0;

Project projects[MAX_RECORDS];
int projectCount = 0;

// --- Employee Functions ---
void addEmployee(void) {
    if (employeeCount >= MAX_RECORDS) { printf("Limit reached!\n"); return; }
    printf("Enter ID: "); employees[employeeCount].id = getIntInput();
    printf("Enter Name (No spaces): "); scanf("%29s", employees[employeeCount].name); clearInputBuffer();
    printf("Enter Department: "); scanf("%19s", employees[employeeCount].department); clearInputBuffer();
    printf("Enter Salary: "); employees[employeeCount].salary = getDoubleInput();
    employeeCount++;
    printf("Employee added.\n");
}

void displayEmployees(void) {
    printf("\n--- Employees ---\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d | Name: %s | Dept: %s | Salary: %.2f\n", 
            employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

// --- Supplier Functions ---
void addSupplier(void) {
    if (supplierCount >= MAX_RECORDS) { printf("Limit reached!\n"); return; }
    printf("Enter ID: "); suppliers[supplierCount].id = getIntInput();
    printf("Enter Name: "); scanf("%39s", suppliers[supplierCount].name); clearInputBuffer();
    printf("Enter Town: "); scanf("%19s", suppliers[supplierCount].town); clearInputBuffer();
    supplierCount++;
}

void displaySuppliers(void) {
    printf("\n--- Suppliers ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("ID: %d | Name: %s | Town: %s\n", suppliers[i].id, suppliers[i].name, suppliers[i].town);
    }
}

// --- Asset Functions (Nested Structure) ---
void addAsset(void) {
    if (assetCount >= MAX_RECORDS) { printf("Limit reached!\n"); return; }
    printf("Enter ID: "); assets[assetCount].id = getIntInput();
    printf("Enter Description: "); scanf("%39s", assets[assetCount].description); clearInputBuffer();
    printf("Enter Value: "); assets[assetCount].value = getDoubleInput();
    printf("Enter Acquired Date (DD MM YYYY): ");
    assets[assetCount].acquired.day = getIntInput();
    assets[assetCount].acquired.month = getIntInput();
    assets[assetCount].acquired.year = getIntInput();
    assetCount++;
}

void displayAssets(void) {
    printf("\n--- Assets ---\n");
    for (int i = 0; i < assetCount; i++) {
        printf("ID: %d | %s | Value: %.2f | Acq: %02d/%02d/%d\n", 
            assets[i].id, assets[i].description, assets[i].value,
            assets[i].acquired.day, assets[i].acquired.month, assets[i].acquired.year);
    }
}

// --- Budget Functions ---
void addBudget(void) {
    if (budgetCount >= MAX_RECORDS) { printf("Limit reached!\n"); return; }
    printf("Enter Department: "); scanf("%19s", budgets[budgetCount].department); clearInputBuffer();
    printf("Enter Allocated Amount: "); budgets[budgetCount].allocated = getDoubleInput();
    printf("Enter Spent Amount: "); budgets[budgetCount].spent = getDoubleInput();
    budgetCount++;
}

void displayBudgets(void) {
    printf("\n--- Budgets ---\n");
    for (int i = 0; i < budgetCount; i++) {
        printf("Dept: %s | Allocated: %.2f | Spent: %.2f | Balance: %.2f\n", 
            budgets[i].department, budgets[i].allocated, budgets[i].spent, 
            budgets[i].allocated - budgets[i].spent);
    }
}

// --- Project Functions ---
void addProject(void) {
    if (projectCount >= MAX_RECORDS) { printf("Limit reached!\n"); return; }
    printf("Enter ID: "); projects[projectCount].id = getIntInput();
    printf("Enter Title: "); scanf("%39s", projects[projectCount].title); clearInputBuffer();
    printf("Enter Budget: "); projects[projectCount].budget = getDoubleInput();
    printf("Enter Start Date (DD MM YYYY): ");
    projects[projectCount].startDate.day = getIntInput();
    projects[projectCount].startDate.month = getIntInput();
    projects[projectCount].startDate.year = getIntInput();
    printf("Enter End Date (DD MM YYYY): ");
    projects[projectCount].endDate.day = getIntInput();
    projects[projectCount].endDate.month = getIntInput();
    projects[projectCount].endDate.year = getIntInput();
    projectCount++;
}

void displayProjects(void) {
    printf("\n--- Projects ---\n");
    for (int i = 0; i < projectCount; i++) {
        printf("ID: %d | Title: %s | Budget: %.2f | Ends: %02d/%02d/%d\n", 
            projects[i].id, projects[i].title, projects[i].budget,
            projects[i].endDate.day, projects[i].endDate.month, projects[i].endDate.year);
    }
}

// --- File Handling (Binary) ---
void saveEmployeesBinary(void) {
    FILE *fp = fopen("employees.dat", "wb");
    if (!fp) { perror("Error opening file"); return; }
    fwrite(&employeeCount, sizeof(int), 1, fp);
    fwrite(employees, sizeof(Employee), employeeCount, fp);
    fclose(fp);
    printf("Employees saved to binary file.\n");
}

void loadEmployeesBinary(void) {
    FILE *fp = fopen("employees.dat", "rb");
    if (!fp) { printf("No data file found.\n"); return; }
    fread(&employeeCount, sizeof(int), 1, fp);
    fread(employees, sizeof(Employee), employeeCount, fp);
    fclose(fp);
    printf("Loaded %d employees from binary file.\n", employeeCount);
}

void displayMenu(void) {
    printf("\n=== MFMS (Week 11: Structures) ===\n");
    printf("1. Add Employee\n2. Display Employees\n");
    printf("3. Add Supplier\n4. Display Suppliers\n");
    printf("5. Add Asset\n6. Display Assets\n");
    printf("7. Add Budget\n8. Display Budgets\n");
    printf("9. Add Project\n10. Display Projects\n");
    printf("11. Save Employees (Binary)\n12. Load Employees (Binary)\n");
    printf("0. Exit\nSelect: ");
}

int main(void) {
    int choice;
    do {
        displayMenu();
        choice = getIntInput();
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: addSupplier(); break;
            case 4: displaySuppliers(); break;
            case 5: addAsset(); break;
            case 6: displayAssets(); break;
            case 7: addBudget(); break;
            case 8: displayBudgets(); break;
            case 9: addProject(); break;
            case 10: displayProjects(); break;
            case 11: saveEmployeesBinary(); break;
            case 12: loadEmployeesBinary(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);
    return 0;
}
#endif