/* HW #3 Rock-paper-scissors starter program */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//See p. 309 of textbook for discussion of Enumerated types
typedef enum {
	ROCK,
	PAPER,
	SCISSORS
} Gesture;

typedef enum {
	HUMAN,
	COMPUTER, 
	TIE
} Winner;

typedef enum {
	FALSE,
	TRUE
} Boolean;

const int SIZE = 50;

// Function prototype -- YOU WILL NEED TO COMPLETE THESE WITH RETURN TYPES AND PARAMETER TYPES
int randomInteger(int rangeStart, int rangeEnd);
void playGame(int *, int*);
void getComputersChoice(Gesture*);
void getHumanChoice(Gesture*);
void printGesture(Gesture, Gesture);
void determineWinner(Gesture, Gesture, Winner*);




/* The main function acts as an outline of the whole program calling functions to perform sub-tasks. 
   Typically, I'm okay with the main function having the "main" loop for the program. */
int main() {
	char playAgain[SIZE];
	int numberOfComputerWins = 0;
	int numberOfHumanWins = 0;
	
	do {
		printf("\nWelcome to Rock, Paper, and Scissors Game!!!\n");
		
		playGame(&numberOfComputerWins, &numberOfHumanWins);
		
		
		
		printf("\n\nWould you like to play again (y or n)? ");
		scanf("%s", playAgain);
	} while(playAgain[0] == 'y' || playAgain[0] == 'Y');  // end do-while
	
	printf("\nYou won %d game(s), and the computer won %d game(s).\n", numberOfHumanWins, numberOfComputerWins);
	
} // end main


/* The playGame function plays a game of rock-paper-scissors between the computer and human
   until either the computer or human wins, and the corresponding win is tallied by updating 
   either the numberOfComputerWins or numberOfHumanWins. */   
void playGame(int *numberOfComputerWins, int *numberOfHumanWins) {
	Winner theWinner;
	Gesture humanChoice, computerChoice;
	
	do {
	getHumanChoice(&humanChoice);	
	getComputersChoice(&computerChoice);
	printGesture(humanChoice, computerChoice);
	determineWinner(humanChoice, computerChoice, &theWinner);
	
	if (theWinner == HUMAN){
	    *numberOfHumanWins = *numberOfHumanWins + 1;
	} else if (theWinner == COMPUTER){
	    *numberOfComputerWins = *numberOfComputerWins + 1;
	}
	} while (theWinner == TIE);

	
} // end playGame


/* The getComputersChoice function randomly picks and returns the computer's Gesture. */
void getComputersChoice(Gesture * computerChoice) {
    int startInt, endInt, temp;
    startInt = 0;
    endInt = 2;
    
    temp = randomInteger(startInt, endInt);
    
    *computerChoice = temp;
    
	
} // end getComputersChoice


/* The getHumanChoice function repeatedly asks the user to enter a valid 
   choice of r, p, or s, then returns the corresponding Gesture for rock, paper, or scissors. */  
void getHumanChoice(Gesture * humanChoice) {
	char humanResponse[SIZE];
	do {
	printf ("\nEnter your choice of rock, paper, or scissors (r, p, or s):");
	scanf ("%s", humanResponse);
	
	
	if (humanResponse[0] == 'r'){
	    *humanChoice = 0;
	} else if (humanResponse[0] == 'p'){
	    *humanChoice = 1;
	} else if (humanResponse[0] == 's'){
	    *humanChoice = 2;
	} else if (!((humanResponse[0] == 'r') || (humanResponse[0] == 'p') || (humanResponse[0] == 's'))){
	    printf("\nInvalid option, try again");
	}
	} while (!((humanResponse[0] == 'r') || (humanResponse[0] == 'p') || (humanResponse[0] == 's')));
} // end getHumanChoice


/* The printGesture function is passed a Gesture as a parameter and prints its corresponding 
   string "rock", "paper", or "scissors" to standard output. */
void printGesture(Gesture humanChoice,Gesture computerChoice) {
    if (computerChoice == 0){
        printf ("\nThe computer choice is rock");
    }else if (computerChoice == 1) {
        printf ("\nThe computer choice is paper");
    }else if (computerChoice == 2) {
        printf ("\nThe computer choice is scissors");
    }
        
    if (humanChoice == 0 ){
        printf ("\nThe human choice is rock");
    }else if (humanChoice == 1 ){
        printf ("\nThe human choice is paper");
    }else if (humanChoice == 2 ){
        printf ("\nThe human choice is scissors");
    }  
} // end printGesture


/* The determineWinner function decides whether the computer wins, the human wins, or if it is a tie.
   Plus, it outputs its decision to the user, updates the numberOfComputerWins or numberOfHumanWins if 
   necessary, and returns a Winner. */  
void determineWinner(Gesture humanChoice,Gesture computerChoice, Winner *theWinner) {
	if (humanChoice == computerChoice){
	    *theWinner = 2;
	    printf ("\nTie -- play on!");
	} else if (humanChoice == 0 && computerChoice == 2){
	    *theWinner = 0;
	    printf ("\nHuman wins! Rock crushes scissors");
	} else if (humanChoice == 1 && computerChoice == 0){
	    *theWinner = 0;
	    printf ("\nHuman wins! Paper covers rock");
	} else if (humanChoice == 2 && computerChoice == 1){
	    *theWinner = 0; 
	    printf ("\nHuman wins! Scissors cut paper");
	} else if (humanChoice == 0 && computerChoice == 1){
	    *theWinner = 1;
	    printf ("\nComputer wins! Paper covers rock");
	} else if (humanChoice == 1 && computerChoice == 2){
	    *theWinner = 1;
	    printf ("\nComputer wins! Scissors cut paper");
	} else if (humanChoice == 2 && computerChoice == 0){
	    *theWinner = 1; 
	    printf ("\nComputer wins! Rock crushes scissors");
	}
} // end determineWinner




/* The randomInteger function returns a random integer between the parameters 
   rangeStart and rangeEnd inclusively. */
int randomInteger(int rangeStart, int rangeEnd) {
	int temp;
	int seed;
	
	// Flag used to initialize the randon # generation only the first time
	static int doneOnce = 0;   // 0 means False and non-0 means True 

	if (!doneOnce) {
		seed = time(0);
		srand(seed);
		doneOnce = 1;
	} // end if	

	temp = rand() % (rangeEnd - rangeStart + 1) + rangeStart;

	return temp;
} // end randomInteger 