// program that takes a binary string that also contains X's and prints out all possible binary strings where the X's can be replaced with either 0's or 1's.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the binary strings
void printBinaryString(char *str) {
    printf("%s\n", str);
}

// Recursive function to generate all possible binary strings by replacing X's
void generateBinaryStringsHelper(char *str, int index) {
    // If the entire string is processed, print it
    if (str[index] == '\0') {
        printBinaryString(str);
        return;
    }

    // If the current character is 'X', replace it with '0' and '1' and recurse
    if (str[index] == 'X' || str[index] == 'x') {
        str[index] = '0';
        generateBinaryStringsHelper(str, index + 1);
        str[index] = '1';
        generateBinaryStringsHelper(str, index + 1);
        // Reset back to 'X' for othe possible combinations
        str[index] = 'X';
    } else {
        // If the current character is not 'X', move to the next character
        generateBinaryStringsHelper(str, index + 1);
    }
}

// function to initiate the generation of binary strings
void generateBinaryStrings(char *str) {
    generateBinaryStringsHelper(str, 0);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        exit(0);
    }

    // Get the binary string from the command line vector
    char *binaryString = argv[1];

    // Call the function to generate binary strings
    generateBinaryStrings(binaryString);

    return 0;
}
