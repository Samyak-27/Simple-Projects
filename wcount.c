//Program to read the total number of words in a given file.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count the number of words in a file
int countWords(FILE *file);

// Function to check if a character is whitespace
int isWhitespace(char c);

int main(int argc, char *argv[]) {//main program with argument count and argument vector

    // Open the file
    FILE *file = fopen(argv[1], "r");

    // Check if the file can be opened
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Count words in the file
    int wordCount = countWords(file);

    // Close the file
    fclose(file);

    // Print the result
    printf("There are %d word(s).\n", wordCount);

    return 0;
}

int countWords(FILE *file) {//takes in the open file.
    int wordCount = 0;
    int inWord = 0;  // Flag to track if we are currently inside a word
    int c;
    char *word = NULL;
    unsigned int wordSize = 0;

    while ((c = fgetc(file)) != EOF) {
        if (isWhitespace(c)) {
            // If the previous character was part of a word, increment word count
            if (inWord) {
                wordCount++;
                inWord = 0;  // Reset the flag

                // Free memory allocated for the word
                free(word);
                word = NULL;
                wordSize = 0;
            }
        } 
        else {
            // We are inside a word
            inWord = 1;

            // Allocate memory for the word and add the character
            word = realloc(word, (wordSize + 1) * sizeof(char));
            word[wordSize++] = c;
        }
    }

    // If the last word in the file is not followed by whitespace, increment word count
    if (inWord) {
        wordCount++;
    }

    // Free memory allocated for the last word
    free(word);

    return wordCount; //returns the word count
}

int isWhitespace(char c) {//takes in the char
    return isspace((unsigned char)c);//returns whether if it is a white spae character or not.
}
