#include <stdio.h>

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    // Check for division by zero
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2;
    char operator;

    // Get user input
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Perform the operation based on the operator
    switch (operator) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
            break;
        case '/':
            printf("%.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    return 0;
}
