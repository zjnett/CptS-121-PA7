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
	int numHands = 0;
	int running = 1;
	char input = '\0';

	srand((unsigned)time(NULL)); /* seed random-number generator */
	
	do {
		printMenu();
		input = handleCharInput();
		if (input == 'N') {
			//New game processing
			while (numHands < 10) {
				shuffle(deck);
				deal(deck, face, suit, playerOneHand, playerTwoHand);
				printf("Points: %d\n", evaluateHand(playerOneHand));
				pressKeyToContinue();
			}
		} else if (input == 'R') {
			//Rules processings
		} else if (input == 'Q') {
			running = 0;
		}
	} while (running);
	
	return 0;
}