#include <stdio.h>

// Function to generate the Fibonacci series up to n terms
void fibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series up to %d terms: %d, %d, ", n, first, second);

    for (int i = 3; i <= n; ++i) {
        next = first + second;
        printf("%d, ", next);
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    int terms;

    // Get user input
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    // Generate and print the Fibonacci series
    fibonacci(terms);

    return 0;
}
