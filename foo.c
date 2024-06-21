//Program to calculate the foo value of a number given by the user
#include <stdio.h>
#include<stdlib.h>

//Function for user input
int GetInteger(char* prmompt){//takes in the prompt to be displayed as parameter
    int n;
    printf("%s", prmompt);
    scanf("%d", &n);
    return n;//returns the user input
}

// Function to calculate Foo using recursive call with memoization
int calculateFoo(int n, int* stack) {
    // Base cases
    if (n == 0) {
        return 3;
    }
    if (n == 1) {
        return 6;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 7;
    }

    // Check if the result is already memoized
    if (stack[n] != -1) {
        return stack[n];
    }

    // Recursive call with updated values
    stack[n] = calculateFoo(n - 1, stack) + calculateFoo(n - 2, stack) + calculateFoo(n - 3, stack) - calculateFoo(n - 4, stack) + 1;

    return stack[n];
}

// Main function
int main() {
    int n;

    // Get user input with error handling
    n = GetInteger("Enter a value for n: ");

    // Allocate memory for memoization array
    int* stack = (int*)malloc((n + 1) * sizeof(int));

    // Initialize memoization array with -1
    for (int i = 0; i <= n; i++) {
        stack[i] = -1;
    }

    // Calculate and display the result
    printf("Foo(%d) = %d\n", n, calculateFoo(n, stack));

    // Free allocated memory
    free(stack);

    return 0;
}