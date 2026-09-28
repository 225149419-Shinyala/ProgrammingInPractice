#include <stdio.h>

int main()
{
    /* Declare variables */
    float basicSalary;
    float housing;
    float transport;
    float tax;
    float grossSalary;
    float netSalary;

    /* Display title */
    printf("========================================\n");
    printf("     EMPLOYEE SALARY CALCULATOR\n");
    printf("========================================\n\n");

    /* Get inputs */
    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    /* Calculate */
    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    /* Display results */
    printf("\n========================================\n");
    printf("         SALARY REPORT\n");
    printf("========================================\n");
    printf("Basic Salary      : %.2f\n", basicSalary);
    printf("Housing Allowance : %.2f\n", housing);
    printf("Transport Allow.  : %.2f\n", transport);
    printf("----------------------------------------\n");
    printf("Gross Salary      : %.2f\n", grossSalary);
    printf("Tax               : %.2f\n", tax);
    printf("----------------------------------------\n");
    printf("Net Salary        : %.2f\n", netSalary);
    printf("========================================\n");

    return 0;
}