//

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double rand_double(double low, double high) {
/*
generate a random double between low and high inclusive
@low: the lowest possible double that can be generated
@high: the highest possible double that can be generated
@returns: a random number between low and high
*/
  return low + ((double) rand()) / (((double) RAND_MAX / (high - low)));
}

double Distance(double x_value, double y_value){
    double distance;

    distance = (pow(x_value,2.0)) + (pow(y_value,2.0));

    return distance;
}

double PiEstimation(double circlePoints, double squarePoints){
    double pi;

    pi = (4.0 * circlePoints) / squarePoints;

    return pi;
}

int main(void){
    int seed;
    int i;
    int iterations;
    double rand_x, rand_y;
    int circlePoints = 0; 
    int squarePoints = 0;
    double distance;
    double pi;

    printf("Enter the seed for the random number generator: ");
    scanf("%d", &seed);
    srand(seed);

    printf("Enter the number of iterations to run: ");
    scanf("%d", &iterations);

    for (i = 0; i <  iterations ; ++i){

        rand_x = rand_double(-1,1);
        rand_y = rand_double(-1,1);

        distance = Distance(rand_x, rand_y);

        if (distance <= 1){
            circlePoints++;
        }

        squarePoints++;


    }
    pi = PiEstimation(circlePoints, squarePoints);

    printf("The value of pi is %.6lf\n", pi);

    return 0;

}

