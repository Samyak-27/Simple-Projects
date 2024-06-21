#include<stdio.h>
#include<math.h>

int main(void){

    //declaring variables
    double principalAmount;
    double interestAmount;
    double numberPayments;
    double monthlyInterest;
    double periodicPayment;
    double totalPayment;
    double loanCost;

    //user inputs
    printf("Please enter the amount of money you borrowed: $");
    scanf("%lf", &principalAmount);
    printf("Please enter the annual interest rate: ");
    scanf("%lf", &interestAmount);
    printf("Please enter the number of payments to be made: ");
    scanf("%lf", &numberPayments);

    //Calculations

    monthlyInterest = interestAmount / 12; 
    periodicPayment = monthlyInterest * (principalAmount /(1 - pow((1 + monthlyInterest),(-1 * numberPayments))));
    totalPayment = periodicPayment * numberPayments ; 
    loanCost = totalPayment - principalAmount;

    //Output

    printf("A loan of $%.2lf with an annual interest of %.2lf paid off over %.0lf months will have monthly payments of $%.2lf.\n", principalAmount, interestAmount, numberPayments, periodicPayment);
    printf("In total, you will pay $%.2lf, making the cost of your loan $%.2lf.\n", totalPayment, loanCost);

    return 0 ;
}