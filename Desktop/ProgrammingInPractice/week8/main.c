#include <stdio.h>

/* ============================================================
   WEEK 8 LAB: Building Reusable MFMS Functions
   ============================================================ */

/* ---------- Function Prototypes ---------- */
void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

/* ---------- displayWelcome ---------- */
void displayWelcome()
{
    printf("========================================\n");
    printf("  Welcome to the Municipal Financial\n");
    printf("     Management System (MFMS)\n");
    printf("========================================\n");
}

/* ---------- displayMenu ---------- */
void displayMenu()
{
    printf("\n========================================\n");
    printf("           MFMS MAIN MENU\n");
    printf("========================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("========================================\n");
    printf("Enter choice: ");
}

/* ---------- calculateVAT ---------- */
float calculateVAT(float amount)
{
    return amount * 0.15f;
}

/* ---------- calculateSalary ---------- */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

/* ---------- calculateBudget ---------- */
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

/* ---------- searchEmployee ---------- */
int searchEmployee(int id, int ids[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i; /* return index where found */
        }
    }
    return -1; /* not found */
}

/* ---------- MAIN ---------- */
int main()
{
    int choice;

    displayWelcome();

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                float amount, vat;
                printf("\nEnter amount: ");
                scanf("%f", &amount);
                vat = calculateVAT(amount);
                printf("VAT (15%%): %.2f\n", vat);
                break;
            }
            case 2:
            {
                float basic, housing, transport, gross;
                printf("\nEnter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                gross = calculateSalary(basic, housing, transport);
                printf("Gross Salary: %.2f\n", gross);
                break;
            }
            case 3:
            {
                float revenue, expenses, balance;
                printf("\nEnter total revenue: ");
                scanf("%f", &revenue);
                printf("Enter total expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget Balance: %.2f\n", balance);
                if (balance > 0)
                    printf("Status: SURPLUS\n");
                else if (balance < 0)
                    printf("Status: DEFICIT\n");
                else
                    printf("Status: BALANCED\n");
                break;
            }
            case 4:
            {
                int employeeIDs[] = {101, 102, 103, 104, 105};
                int size = 5;
                int id, position;
                printf("\nEnter employee ID to search: ");
                scanf("%d", &id);
                position = searchEmployee(id, employeeIDs, size);
                if (position != -1)
                    printf("Employee found at position %d.\n", position);
                else
                    printf("Employee with ID %d not found.\n", id);
                break;
            }
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}