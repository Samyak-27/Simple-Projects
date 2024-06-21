#include<stdio.h>

int main(void){
    //declaring variables
    int amount;
    int remainder;
    int hundredNotes;
    int fiftyNotes;
    int twentyNotes;
    int tenNotes;
    int fiveNotes;
    int oneNotes;

    //getting input
    printf("Please enter the amount of money you wish to withdraw:");
    scanf("%d", &amount);

    // Calculating the number of bills
    hundredNotes = amount / 100;
    remainder = amount % 100;

    fiftyNotes = remainder / 50;
    remainder %= 50;
    
    twentyNotes = remainder / 20;
    remainder %= 20;
    
    tenNotes = remainder / 10;
    remainder %= 10;
    
    fiveNotes = remainder / 5;
    
    oneNotes = remainder% 5;

    //Displaying the number of bills.

    printf("You received %d hundred(s)\n", hundredNotes);
    printf("You received %d fifty(s)\n", fiftyNotes);
    printf("You received %d twenty(s)\n", twentyNotes);
    printf("You received %d ten(s)\n", tenNotes);
    printf("You received %d five(s)\n", fiveNotes);
    printf("You received %d one(s)\n", oneNotes);


    return 0;
}