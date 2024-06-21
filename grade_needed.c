#include<stdio.h>

int main(void){
    char grade;
    double percentNeeded;
    double currentPercent;
    double finalWeight;
    double finalPercent;
    double currentWeight;

    printf("Enter the grade you want in the class: ");
    scanf("%c", &grade);
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &percentNeeded);
    printf("Enter your current percent in the class: ");
    scanf("%lf", &currentPercent);
    printf("Enter the weight of the final: ");
    scanf("%lf", &finalWeight);

    currentWeight = 100 - finalWeight; 

    finalPercent = ((percentNeeded * 100)- (currentWeight * currentPercent)) / finalWeight;

    printf("You need to get at least %.2lf%% on the final to get a %c in the class.\n" , finalPercent, grade);



    return 0;
}