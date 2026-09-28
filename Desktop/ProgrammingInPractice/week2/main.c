#include <stdio.h>

int main()
{
    /* Declare variables */
    double revenue;
    double expenses;
    double balance;

    /* Display title */
    printf("========================================\n");
    printf("     MUNICIPAL BUDGET CALCULATOR\n");
    printf("========================================\n\n");

    /* Get revenue */
    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    /* Get expenses */
    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    /* Calculate balance */
    balance = revenue - expenses;

    /* Display results */
    printf("\n========================================\n");
    printf("          BUDGET REPORT\n");
    printf("========================================\n");
    printf("Revenue  : %.2f\n", revenue);
    printf("Expenses : %.2f\n", expenses);
    printf("Balance  : %.2f\n", balance);
    printf("========================================\n");

    return 0;
}