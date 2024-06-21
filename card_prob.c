//Program to find the probablity of drawing cards from at least one copy of a specific card by a given turn in a deck
#include<stdio.h>

// D = number of cards in the deck
// C = copies of a specefic card
// N = number of cards in hand
// M = number of cards in mulligan step

//Funtion to get the number of cards in the deck
int numberDeck(const char* prompt){ //prints the prompt provided to it
    int D;

    printf("%s", prompt);
    scanf("%d", &D);

    return D; //returns number of cards in the deck
}

//Funtion to get the number of copies of the specefic card in the deck
int numberCopies(const char* prompt){//prints the prompt provided to it
    int C;

    printf("%s", prompt);
    scanf("%d", &C);

    return C; //returns number of copies of the specefic card in the deck
}

//Funtion to get the number of cards in the hand
int numberHands(const char* prompt){//prints the prompt provided to it
    int N;

    printf("%s", prompt);
    scanf("%d", &N);

    return N; //returns number of cards in the hand
}

//Funtion to get the number of cards to be mulliganed
int numberMulligan(const char* prompt){//prints the prompt provided to it
    int M;

    printf("%s", prompt);
    scanf("%d", &M);

    return M; //returns the number of cards to be mulliganed
}

//Funtion to get the desired number of turns
int numberTurns(const char* prompt){//prints the prompt provided to it
    int turns;

    printf("%s", prompt);
    scanf("%d", &turns);

    return turns; //returns the desired number of terms
}

double calculateProbability(int D, int C, int N, int M, int turns) {
    double probabilityNotDrawing = 1.0;

    // Calculate probability of not drawing the card in starting hand
    for (int i = 0; i < N; ++i) {
        probabilityNotDrawing *= ((double)(D - C - i) / (D - i));
    }

    // Calculate probability of not drawing the card in mulligan step
    for (int i = 0; i <= M; ++i) {
        probabilityNotDrawing *= ((double)(D - C - N - i) / (D - N - i));
    }

    // Calculate probability of not drawing the card in subsequent turns
    double probabilityNotInTurns = 1.0;
    for (int i = 1; i <= turns - 1 ; ++i) {
        probabilityNotInTurns *= ((double)(D - C - N - M - i) / (D - N - M - i));
    }

    // Calculate total probability of not drawing the card by desired turns
    double totalProbabilityNotDrawing = probabilityNotDrawing * probabilityNotInTurns;

    // Calculate probability of drawing the card by desired turns
    double probabilityDrawing = 1.0 - totalProbabilityNotDrawing;

    return probabilityDrawing;// returns the probablity of at least one copy of the card the user is looking for by the desired turn.
}

int main() {
    //declaring the variables
    int D; // Total number of cards in the deck
    int C;  // Number of copies of the specific card
    int N;  // Number of cards drawn in starting hand
    int M;  // Number of cards drawn in mulligan step
    int turns; // Desired turns

    //functioncalls to get the user inputs
    D = numberDeck("Enter how many total cards there are in the deck: ");
    C = numberCopies("Enter how many copies of the card that you are looking for are in the deck: ");
    N = numberHands("Enter your initial hand size: ");
    M = numberMulligan("Enter how many cards you are mulliganing: ");
    turns = numberTurns("Enter what turn you want to draw the card by: ");

    //calculating thr probablity
    double probability = calculateProbability(D, C, N, M, turns);
    
     //displaying the reuslt
    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n", turns, M, probability);


    return 0;

}