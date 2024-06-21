//Program to display Pascals triangle based on the number of rows input by the user (in between 1 and 28)

#include<stdio.h>

//Function to get the number of rows user wants
int numberPascal(char* prompt){//prints the prompt
    int pascalNum;
    printf("%s", prompt);
    scanf("%d", &pascalNum);
    while (pascalNum < 0 || pascalNum >28){
        printf("%s", prompt);
        while (getchar() != '\n');
        scanf("%d", &pascalNum);
    }

    return pascalNum; //returns the number of rows
}

//Function to print pascals triangle
void pascalTriangle(int pascalNum){//number of rows required to be print
    int triangle[50][50];
    int i, j;

    for (i = 0; i < pascalNum; ++i){//outer loop represent the row
        for(j = 0; j <= i; ++j){//inner loop representing columns 
            if (j == 0 || j == i){
                triangle[i][j] = 1;
            }
            else{
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];//adding the numbers above the digits place
            }
            printf("%d ", triangle[i][j]);
        }
        printf("\n");//prints a new line
    }
}


//Main function
int main(void){
    int pascalNum;

    pascalNum = numberPascal("Please enter how many levels of Pascal's Triangle you would like to see:");//user input for number of rows

    pascalTriangle(pascalNum);//calls the function to print the pascal triangle

    return 0;
}