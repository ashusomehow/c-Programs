#include <stdio.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void simpleLoop();
void checkPalindrome();
void generateFibonacci();

int main() {
    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Simple Loop\n");
        printf("6. Check Palindrome\n");
        printf("7. Generate Fibonacci Series\n");
        printf("0. Exit\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on choice
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                simpleLoop();
                break;
            case 6:
                checkPalindrome();
                break;
            case 7:
                generateFibonacci();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function definitions
void add() {
    int num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = num1 + num2;
    printf("Result: %d\n", result);
}

void subtract() {
    int num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = num1 - num2;
    printf("Result: %d\n", result);
}

void multiply() {
    int num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = num1 * num2;
    printf("Result: %d\n", result);
}

void divide() {
    int num1, num2;
    float result;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num2 == 0) {
        printf("Error: Division by zero is undefined.\n");
    } else {
        result = (float)num1 / num2;
        printf("Result: %.2f\n", result);
    }
}

void simpleLoop() {
    int i, n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Looping %d times:\n", n);
    for (i = 1; i <= n; ++i) {
        printf("Iteration %d\n", i);
    }
}

void checkPalindrome() {
    int num, reversedNum = 0, originalNum;

    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num;

    // Reverse the number
    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }

    // Check if it's a palindrome
    if (originalNum == reversedNum) {
        printf("%d is a palindrome.\n", originalNum);
    } else {
        printf("%d is not a palindrome.\n", originalNum);
    }
}

void generateFibonacci() {
    int n, first = 0, second = 1, next, i;

    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci series:\n");

    for (i = 0; i < n; i++) {
        printf("%d, ", first);

        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}
