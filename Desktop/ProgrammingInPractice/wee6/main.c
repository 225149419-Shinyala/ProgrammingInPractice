#include <stdio.h>

/* ============================================================
   WEEK 6 LAB: Municipal Information Management System
   Part A: Employee Salaries (50)
   Part B: Department Budgets (10)
   Part C: Vehicle Registrations (20)
   ============================================================ */

#define MAX_SALARIES 50
#define MAX_BUDGETS 10
#define MAX_REGISTRATIONS 20
#define REG_LENGTH 20

/* ---------- PART A: EMPLOYEE SALARIES ---------- */
void employeeSalaries()
{
    float salaries[MAX_SALARIES];
    float total = 0, average, highest, lowest, searchValue;
    int i, found = 0;

    printf("\n--- PART A: EMPLOYEE SALARIES ---\n\n");

    /* Capture 50 salaries */
    for (i = 0; i < MAX_SALARIES; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    /* Initialize highest and lowest with first salary */
    highest = salaries[0];
    lowest = salaries[0];

    /* Display all salaries and calculate total/highest/lowest */
    printf("\n--- All Salaries ---\n");
    for (i = 0; i < MAX_SALARIES; i++)
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
        total = total + salaries[i];

        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }

    average = total / MAX_SALARIES;

    printf("\n--- Salary Summary ---\n");
    printf("Total   : %.2f\n", total);
    printf("Average : %.2f\n", average);
    printf("Highest : %.2f\n", highest);
    printf("Lowest  : %.2f\n", lowest);

    /* Search for a particular salary */
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchValue);

    for (i = 0; i < MAX_SALARIES; i++)
    {
        if (salaries[i] == searchValue)
        {
            printf("Salary %.2f found at position %d (Employee %d)\n",
                   searchValue, i, i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Salary %.2f not found.\n", searchValue);
    }
}

/* ---------- PART B: DEPARTMENT BUDGETS ---------- */
void departmentBudgets()
{
    float budgets[MAX_BUDGETS];
    float total = 0, average, temp;
    int i, j;

    printf("\n--- PART B: DEPARTMENT BUDGETS ---\n\n");

    /* Capture 10 budgets */
    for (i = 0; i < MAX_BUDGETS; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    /* Display budgets and calculate total */
    printf("\n--- All Budgets ---\n");
    for (i = 0; i < MAX_BUDGETS; i++)
    {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
        total = total + budgets[i];
    }

    average = total / MAX_BUDGETS;

    printf("\nTotal Budget   : %.2f\n", total);
    printf("Average Budget : %.2f\n", average);

    /* Sort budgets from lowest to highest (bubble sort) */
    for (i = 0; i < MAX_BUDGETS - 1; i++)
    {
        for (j = 0; j < MAX_BUDGETS - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");
    for (i = 0; i < MAX_BUDGETS; i++)
    {
        printf("%.2f\n", budgets[i]);
    }
}

/* ---------- PART C: VEHICLE REGISTRATIONS ---------- */
void vehicleRegistrations()
{
    char registrations[MAX_REGISTRATIONS][REG_LENGTH];
    char searchReg[REG_LENGTH];
    int i, found = 0;

    printf("\n--- PART C: VEHICLE REGISTRATIONS ---\n\n");

    /* Capture 20 registration numbers */
    for (i = 0; i < MAX_REGISTRATIONS; i++)
    {
        printf("Enter registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    /* Display all registrations */
    printf("\n--- All Registrations ---\n");
    for (i = 0; i < MAX_REGISTRATIONS; i++)
    {
        printf("%s\n", registrations[i]);
    }

    /* Search for a registration */
    printf("\nEnter a registration to search for: ");
    scanf("%19s", searchReg);

    for (i = 0; i < MAX_REGISTRATIONS; i++)
    {
        /* Simple string compare — compare character by character */
        int match = 1;
        int k = 0;
        while (registrations[i][k] != '\0' || searchReg[k] != '\0')
        {
            if (registrations[i][k] != searchReg[k])
            {
                match = 0;
                break;
            }
            k++;
        }
        if (match)
        {
            printf("Registration %s found at position %d\n", searchReg, i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Registration %s not found.\n", searchReg);
    }
}

/* ---------- MAIN MENU ---------- */
int main()
{
    int choice;

    printf("========================================\n");
    printf("  MUNICIPAL INFORMATION MANAGEMENT\n");
    printf("========================================\n");
    printf("1. Employee Salaries\n");
    printf("2. Department Budgets\n");
    printf("3. Vehicle Registrations\n");
    printf("0. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            employeeSalaries();
            break;
        case 2:
            departmentBudgets();
            break;
        case 3:
            vehicleRegistrations();
            break;
        case 0:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}