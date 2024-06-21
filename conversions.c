
//Program to convert units of measurement for temperature or distance (depending on user input) and displaying the output

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//input validation for values in main
bool isValidFormat() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { // checks for newline charachter and end of input/file 
        if (!isspace(c)) {
            printf("Invalid formatting. Ending program.\n");
            exit(0);
        }
    }
    return true;
}

//input validation for the type of conversion (distance or temperature)
bool isValidConversion(const char conversionUnit) { // takes in the conversion unit
    if (toupper(conversionUnit) == 'T' || toupper(conversionUnit) == 'D') { // checks the validity of the conversion units
        return true;
    } 
    else {
        printf("Unknown conversion type %c chosen. Ending program.\n", toupper(conversionUnit));
        exit(0);//exits program when provided with wrong input
    }
}

// function to obtain the type of conversion needed to be done
char getValidConversion(const char* prompt){ //takes in prompt to be displayed
    char conversionUnit;
    printf("%s", prompt);
    scanf(" %c", &conversionUnit);//takes in the user input for conversionunit
    
    if(!isalnum(conversionUnit)){
        isValidFormat();
    } 

    if (!isValidConversion(conversionUnit) || getchar() != '\n') {//checks if the user input is valid
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
    
    return conversionUnit;
}


// input validation for the units of temperature

bool isValidTemp(const char unit) { // takes in the user given input
    if (toupper(unit) == 'F' || toupper(unit) == 'C' || toupper(unit) == 'K') {
        return true;
    } else {
        printf("%c is not a valid temperature type. Ending program.\n", toupper(unit));
        exit(0);
    }
}
//input validation for the units of distance

bool isValidDist(const char unit) { // takes in the user given input
    if (toupper(unit) == 'I' || toupper(unit) == 'F' || toupper(unit) == 'Y' || toupper(unit) == 'M') {
        return true;
    } else {
        printf("%c is not a valid distance type. Ending program.\n", toupper(unit));
        exit(0);
    }
}
// function to convert temperature to a standard Kelvin scale
double T_Conversion(const double value, const char unit){
    double K_value;

    switch(toupper(unit)){
        case 'C': //Celsius
            K_value = value + 273.15;
            return K_value;
        case 'F': //Fahrenheit
            K_value = ((value - 32.00) * (5.0 / 9.0)) + 273.15;
            return K_value;
        default: //Kelvin
            return value;
    }
}

// function to convert the temperature from Kelvin scale to the desired unit
double tempConversion(const double K_value, const char conversionUnit){
    double C_value;
    double F_value;

    switch (toupper(conversionUnit)){
        case 'C': //Celsius
            C_value = K_value - 273.15;
            return C_value;
        
        case 'F': //Fahrenheit
            F_value = ((K_value - 273.15) * (9.0 / 5.0)) + 32.0;
            return F_value;
        
        default: //Kelvin
            return K_value;

    }
}

// function to convert distance to a standard foot/feet scale
double D_Conversion(const double value, const char unit){
    double F_value;

    switch(toupper(unit)){
        case 'I': //Inches
            F_value = value / 12.00;
            return F_value;
        case 'Y': //Yards
            F_value = value * 3.00;
            return F_value;
        case 'M': //Miles
            F_value = value * 5280.00;
            return F_value;
        default: // Feet
            return value;
    }
}

// function to convert the distance from the foot/feet scale to the desired unit
double DistConversion(const double F_value, const char conversionUnit){
    double I_value;
    double Y_value;
    double M_value;

    switch (toupper(conversionUnit)){
        case 'I': //Inches
            I_value = F_value * 12.00;
            return I_value;
        
        case 'Y': //Yards
            Y_value = F_value / 3.00;
            return Y_value;
        
        case 'M': //Miles
            M_value = F_value / 5280.00;
            return M_value;

        default: //Feet
            return F_value;

    }
}

int main(void){
    //defining the variables
    double value;
    double K_value;
    double F_value;
    char unit;
    char conversion;
    char conversionUnit;
    double temperature;
    double distance;

    //printing information for the user to select
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");

    //recieving input whether the user wants to do temperature or distance conversion
    conversion = getValidConversion("Enter your choice: ");

    //switch statement to depend on the user input
    switch (toupper(conversion)){

        case 'T': //Temperature
            
            printf("Enter the temperature followed by its suffix(F, C, or K): ");
            scanf("%lf %c", &value, &unit);//takes input from the user with the unit
            
            isValidFormat(unit);//input validation for the double value
            isValidTemp(unit);//input validation for the unit

            K_value = T_Conversion(value, unit);//converts it to a standard Kelvin scale for conversion

            printf("Enter the new unit type (F, C, or K): ");
            scanf(" %c", &conversionUnit);//takes input for the conversion unit
            
            isValidFormat(conversionUnit);
            isValidTemp(conversionUnit);//input validation for temperature type
            
            temperature = tempConversion(K_value, conversionUnit);//calculates the temperature on the needed scale as entered by the user

            printf("%.2lf%c is %.2lf%c\n", value, toupper(unit), temperature, toupper(conversionUnit));//prints the result

            break;

        case 'D': //Distance

            printf("Enter the distance followed by its suffix (I,F,Y,M): ");
            scanf("%lf %c", &value, &unit);//takes input from the user with the unit
            
            isValidFormat(unit);//input validation fro the double value
            isValidDist(unit);//input validation for the unit
            
            F_value = D_Conversion(value, unit);//converts it to a standard Feet scale for conversion

            printf("Enter the new unit type (I,F,Y,M): ");
            scanf(" %c", &conversionUnit);//takes input for the conversion unit
            isValidFormat(conversionUnit);
            isValidDist(conversionUnit);//input validation for distance type
            
            distance = DistConversion(F_value, conversionUnit);//calculates the distance on the needed scale as entered by the user


            printf("%.2lf%c is %.2lf%c\n", value, toupper(unit), distance, toupper(conversionUnit));//prints the result

            break;

        default:
            exit(0);
    }


    return 0;
}