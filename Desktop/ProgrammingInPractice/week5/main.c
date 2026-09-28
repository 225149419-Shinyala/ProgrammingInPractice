#include <stdio.h>

int main()
{
    /* Declare variables */
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;
    int i;

    /* Display title */
    printf("========================================\n");
    printf("   MUNICIPAL EMPLOYEE SALARY ANALYSIS\n");
    printf("========================================\n\n");

    /* Capture 50 salaries using a for loop */
    for (i = 1; i <= 5; i++)
    {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        /* Add to total */
        total = total + salary;

        /* Initialize highest and lowest with the first salary */
        if (i == 1)
        {
            highest = salary;
            lowest = salary;
        }

        /* Update highest if current salary is greater */
        if (salary > highest)
        {
            highest = salary;
        }

        /* Update lowest if current salary is lower */
        if (salary < lowest)
        {
            lowest = salary;
        }
    }

    /* Calculate average AFTER the loop */
    average = total / 50;

    /* Display report */
    printf("\n========================================\n");
    printf("         SALARY REPORT\n");
    printf("========================================\n");
    printf("Total Salary   : %.2f\n", total);
    printf("Average Salary : %.2f\n", average);
    printf("Highest Salary : %.2f\n", highest);
    printf("Lowest Salary  : %.2f\n", lowest);
    printf("========================================\n");

    return 0;
}