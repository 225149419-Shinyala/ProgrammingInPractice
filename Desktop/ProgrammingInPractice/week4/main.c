#include <stdio.h>

int main()
{
    /* Declare variables */
    char supplierName[50];
    float price;
    float budget;
    int registered;
    int documentsComplete;

    /* Display title */
    printf("========================================\n");
    printf("        TENDER EVALUATION SYSTEM\n");
    printf("========================================\n\n");

    /* Get inputs */
    printf("Enter supplier name: ");
    scanf("%49s", supplierName);

    printf("Enter tender price: ");
    scanf("%f", &price);

    printf("Enter available budget: ");
    scanf("%f", &budget);

    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered);

    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documentsComplete);

    /* Display report header */
    printf("\n========================================\n");
    printf("         TENDER EVALUATION REPORT\n");
    printf("========================================\n");
    printf("Supplier : %s\n", supplierName);
    printf("Price    : %.2f\n", price);
    printf("Budget   : %.2f\n", budget);
    printf("----------------------------------------\n");

    /* Decision logic */
    if (registered == 0 || documentsComplete == 0)
    {
        printf("Status   : Disqualified\n");
        if (registered == 0)
        {
            printf("Reason   : Not registered\n");
        }
        if (documentsComplete == 0)
        {
            printf("Reason   : Incomplete documents\n");
        }
    }
    else if (price > budget)
    {
        printf("Status   : Disqualified\n");
        printf("Reason   : Price exceeds budget\n");
    }
    else
    {
        /* Qualified — check if preferred */
        if (price <= budget * 0.90)
        {
            printf("Status   : Preferred Supplier\n");
            printf("Note     : Qualified and well within budget\n");
        }
        else
        {
            printf("Status   : Qualified\n");
        }
    }

    printf("========================================\n");

    return 0;
}