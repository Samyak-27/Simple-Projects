//Program to check wherther two strings are anagrams of each other (case insensitive)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Function to get the first word
void FirstWord(const char *prompt, char *word) {//prints the prompt and assigns the pointer varibale to first word
    printf("%s", prompt);
    scanf("%s", word);
}

void SecondWord(const char *prompt, char *word) {//prints the prompt and assigns the pointer varibale to second word
    printf("%s", prompt);
    scanf("%s", word);
}

//Funtion to compare the strings
void Compare(char *firstWord, char *secondWord) {//takes in the pointer variable to the first and second word
    int count1[26] = {0}; // Initialize an array to store character counts for firstWord
    int count2[26] = {0}; // Initialize an array to store character counts for secondWord
    int i;
    int len1 = strlen(firstWord);//length of first word
    int len2 = strlen(secondWord);//length of second word

    if (len1 != len2) { //checks if the length is the same
        printf("%s is NOT an anagram of %s\n", firstWord, secondWord);
        return;
    }

    // Count occurrences of each character in firstWord
    for (i = 0; i < len1; ++i) {
        count1[tolower(firstWord[i]) - 'a']++;
    }
    
    // Count occurrences of each character in secondWord
    for (i = 0; i < len2; ++i) {
        count2[tolower(secondWord[i]) - 'a']++;
    }

    // Compare character counts
    for (i = 0; i < 26; ++i) {
        if (count1[i] != count2[i]) {
            printf("%s is NOT an anagram of %s\n", firstWord, secondWord);
            return;
        }
    }

    printf("%s is an anagram of %s\n", firstWord, secondWord);
}

//Main function
int main(void){
    char firstWord[21]; 
    char secondWord[21];

    FirstWord("Please enter the first word:", firstWord);//get the firstword
    SecondWord("Please enter the second word:", secondWord);//get the second word

    Compare(firstWord, secondWord);//compare the first and second word

    return 0;
}