#include <stdio.h>
#include <stdlib.h>

// Define the maximum length of expense description
#define MAX_DESCRIPTION_LENGTH 100

// Structure to represent an expense
struct Expense {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    struct Expense* next;
};

// Function to add a new expense to the list
struct Expense* addExpense(struct Expense* head, const char* description, double amount) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    if (newExpense == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newExpense->description, description, MAX_DESCRIPTION_LENGTH - 1);
    newExpense->description[MAX_DESCRIPTION_LENGTH - 1] = '\0';
    newExpense->amount = amount;
    newExpense->next = head;

    return newExpense;
}

// Function to calculate the total expenses
double calculateTotalExpenses(const struct Expense* head) {
    double total = 0.0;
    const struct Expense* current = head;

    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }

    return total;
}

// Function to calculate the average daily expense
double calculateAverageExpense(const struct Expense* head, int days) {
    double total = calculateTotalExpenses(head);
    
    if (days > 0) {
        return total / days;
    } else {
        return 0.0;
    }
}

// Function to print all expenses in the list
void printExpenses(const struct Expense* head) {
    const struct Expense* current = head;
    while (current != NULL) {
        printf("%s: $%.2lf\n", current->description, current->amount);
        current = current->next;
    }
}

// Function to free the memory allocated for expenses
void freeExpenses(struct Expense* head) {
    struct Expense* current = head;
    while (current != NULL) {
        struct Expense* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Expense* expenseList = NULL;
    int days = 0;

    while (1) {
        printf("\n1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. View Total Expenses\n");
        printf("4. View Average Daily Expense\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char description[MAX_DESCRIPTION_LENGTH];
                double amount;

                // Get user input for expense
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);

                printf("Enter expense amount: $");
                scanf("%lf", &amount);

                // Add expense to the list
                expenseList = addExpense(expenseList, description, amount);
                days++;  // Increment days to calculate average expense
                printf("Expense added successfully!\n");
                break;
            }
            case 2:
                printf("\nExpenses:\n");
                printExpenses(expenseList);
                break;
            case 3:
                printf("Total Expenses: $%.2lf\n", calculateTotalExpenses(expenseList));
                break;
            case 4:
                printf("Average Daily Expense: $%.2lf\n", calculateAverageExpense(expenseList, days));
                break;
            case 5:
                // Clean up and exit
                freeExpenses(expenseList);
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
