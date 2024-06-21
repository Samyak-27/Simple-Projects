//Program to calculate the perimeter with a given binary file containing the number of vertices and their coordinates
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to represent a point in 2D space
typedef struct Point {
    int x;
    int y;
}Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {//takes in two points to calculate the distance
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));//returns the distance in between the points
}

// Function to calculate the perimeter of the shape from the binary file
double calculatePerimeter(FILE *fp) {//takes the file pointer as the parameter
    int numPoints;
    fread(&numPoints, sizeof(int), 1, fp);

    Point *points = malloc(numPoints * sizeof(Point)); //Allocate memory space for the the number of points/vertices
    if (points == NULL) {
        exit(0);
    }

    // Read the vertices from the file
    fread(points, sizeof(Point), numPoints, fp);

    // Calculate the perimeter
    double perimeter = 0.0;
    for (int i = 0; i < numPoints - 1; ++i) {
        perimeter += distance(points[i], points[i + 1]);
    }
    // Add the edge between the last and first vertices
    perimeter += distance(points[numPoints - 1], points[0]);

    free(points);

    return perimeter;//returns the perimeter
}

//Function to validate and open a binary file
FILE* validate_input(int argc, char* argv[]){//takes in argument count and argument vector as parameters

	FILE* fp = NULL;

	if(argc < 2){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 2){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}
	
	fp = fopen(argv[1], "rb");
	
	if(fp == NULL){
		printf("Unable to open file: %s\nEnding program.\n", argv[1]);
		exit(0);
	}
	
	return fp;//returns the file

}

//main program
int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    FILE* fp = validate_input(argc, argv);

    // Calculate and print the perimeter
    double perimeter = calculatePerimeter(fp);
    printf("The perimeter is %.2f\n", perimeter);

    // Close the file
    fclose(fp);

    return 0;
}
