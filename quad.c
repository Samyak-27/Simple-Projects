#include<stdio.h>
#include<math.h>

//Finding the discriminant to determine the number of real solutions
double Discriminant(double a, double b, double c){ //Here 'a' is the coefficent of x^2, 'b' is the coefficent of x and 'c' is the constant
    double discriminant;

    discriminant = (pow(b,2.0) - (4.0 * a * c));

    return discriminant; //returns the value of the discriminant

}

//finds the number of solutions of the given quadratic equation.
double Solution(double Discriminant){  // here Discriminant is being used to figure out the number of solutions.

    double solution;

    if (Discriminant == 0){
        solution = 1;
    }
    else if (Discriminant > 0){
        solution = 2;
    }
    else{
        solution = 0;
    }

    return solution; //returns the number of solutions. 

}

//Function to find the solution of a quadratic equation having only one real solution.
double oneReal(double a, double b, double c){//Here 'a' is the coefficent of x^2, 'b' is the coefficent of x and 'c' is the constant.
    double quadraticSolutions;

    quadraticSolutions = -b/(2*a); // formula to find the roots.

    return quadraticSolutions; // returns the solution
}


// Function to find and print the solution of a quadratic equation having only two real solution.
void twoReal(double a, double b, double c){//Here 'a' is the coefficent of x^2, 'b' is the coefficent of x and 'c' is the constant.
    double quadraticSolutions_1;
    double quadraticSolutions_2;
    double discriminant;

    discriminant = Discriminant(a,b,c);

    quadraticSolutions_1 = (-b + sqrt(discriminant)) / (2.0 * a);
    quadraticSolutions_2 = (-b - sqrt(discriminant)) / (2.0 * a);

    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", quadraticSolutions_1);
    printf("Solution 2: %.2lf\n", quadraticSolutions_2);


}


//main program
int main(void){
    double a;
    double b;
    double c;
    double discriminant;
    double quadraticSolution;
    int numberSolutions;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    discriminant= Discriminant(a, b, c); // Calling the Discriminant function
    numberSolutions = Solution(discriminant); // Calling the Solution function

    //runninf if else if loop to print answers based on the number of solutions
    if (numberSolutions == 1){
        quadraticSolution = oneReal(a, b, c);
        printf("There is one real solution: %.2lf\n", quadraticSolution);
    }
    else if (numberSolutions == 2){
        twoReal(a, b, c);
    }
    else{
        printf("There are no real solutions\n");
    }

    return 0;

}

//program end