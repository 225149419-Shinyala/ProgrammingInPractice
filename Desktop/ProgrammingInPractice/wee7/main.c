#include <stdio.h>
#include <string.h>

/* Function prototypes */
void addSupplier();
void displaySupplier();
void searchSupplier();
void showNameLength();
void displayMenu();

/* Global variables to store supplier info */
char supplierName[100] = "";
char email[100] = "";
char phone[30] = "";
char town[50] = "";
int supplierAdded = 0;

/* ---------- MAIN ---------- */
int main()
{
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);
        getchar(); /* consume newline left by scanf */

        switch (choice)
        {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                showNameLength();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/* ---------- displayMenu ---------- */
void displayMenu()
{
    printf("\n========================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Show Name Length\n");
    printf("5. Exit\n");
    printf("========================================\n");
    printf("Enter choice: ");
}

/* ---------- addSupplier ---------- */
void addSupplier()
{
    printf("\n--- ADD SUPPLIER ---\n");

    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0'; /* remove newline */

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    supplierAdded = 1;
    printf("\nSupplier added successfully.\n");
}

/* ---------- displaySupplier ---------- */
void displaySupplier()
{
    if (!supplierAdded)
    {
        printf("\nNo supplier has been added yet.\n");
        return;
    }

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);
}

/* ---------- searchSupplier ---------- */
void searchSupplier()
{
    char searchName[100];
    char backup[100];

    /* Use strcpy to backup the supplier name (demonstrates strcpy) */
    strcpy(backup, supplierName);

    printf("\n--- SEARCH SUPPLIER ---\n");
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    /* Use strcmp to compare */
    if (strcmp(backup, searchName) == 0)
    {
        printf("\nSupplier found: %s\n", searchName);
    }
    else
    {
        printf("\nSupplier not found: %s\n", searchName);
    }
}

/* ---------- showNameLength ---------- */
void showNameLength()
{
    char sentence[200];

    if (!supplierAdded)
    {
        printf("\nNo supplier has been added yet.\n");
        return;
    }

    printf("\n--- NAME LENGTH ---\n");
    printf("Supplier name length : %zu\n", strlen(supplierName));
    printf("Email length         : %zu\n", strlen(email));
    printf("Town length          : %zu\n", strlen(town));

    /* Demonstrate strcat: build a sentence */
    strcpy(sentence, supplierName);
    strcat(sentence, " operates in ");
    strcat(sentence, town);
    strcat(sentence, ".");

    printf("\nDescription: %s\n", sentence);
}