#include "functions.h"

int main(void) {
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	//Card array initialization, size 6 to account for 1-5 index cycling in provided code
	Card playerOneHand[6] = { 0 };
	Card playerTwoHand[6] = { 0 };
	int numHands = 0, playerOneScore = 0, playerTwoScore = 0;
	int running = 1;
	char input = '\0';

	srand((unsigned)time(NULL)); /* seed random-number generator */
	
	do {
		printMenu();
		input = handleCharInput();
		if (input == 'N') {
			//New game processing
			while (numHands < 10) {
				clearScreen();
				shuffle(deck);
				deal(deck, face, suit, playerOneHand);
				printHand(face, suit, playerOneHand);
				deal(deck, face, suit, playerTwoHand);

				//Initial evaluation
				playerOneScore = evaluateHand(playerOneHand);
				playerTwoScore = evaluateHand(playerTwoHand);
				
				printf("Points: %d\n", playerOneScore);

				if (playerOneScore > playerTwoScore) {
					//player 1 has the better hand

				}
				else if (playerTwoScore > playerOneScore) {
					//player 2 has the better hand

				}
				else {
					//Players hands are equal

				}

				pressKeyToContinue();
				reinitializeArrays(playerOneHand, playerTwoHand, deck);
				numHands++;
			}
		} else if (input == 'R') {
			//Rules processings
			clearScreen();
		} else if (input == 'Q') {
			running = 0;
		}
	} while (running);
	
	return 0;
}