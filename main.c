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
	int numHands = 0, playerOneScore = 0, playerTwoScore = 0, numCardsToDraw = 0, compCardsToDraw = 0;
	int rowCount = 3, colCount = 12;
	int running = 1;
	int playerScore = 0, houseScore = 0;
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
				deal(deck, face, suit, playerOneHand, playerTwoHand);
				printf("DEALER'S HAND:\n");
				printHand(face, suit, playerTwoHand);
				printf("YOUR HAND:\n");
				printHand(face, suit, playerOneHand);

				//Initial evaluation
				playerOneScore = evaluateHand(playerOneHand);
				playerTwoScore = evaluateHand(playerTwoHand);

				printf("Points: %d\n", playerOneScore);
				printf("Would you like to redraw cards? Y/N: ");
				input = handleCharInput();
				if (input == 'Y') {
					do {
						clearScreen();
						printHand(face, suit, playerOneHand);
						printf("How many cards would you like to redraw? (max of 3): ");
						scanf("%d", &numCardsToDraw);
					} while (numCardsToDraw > 3);
					clearScreen();
					printHand(face, suit, playerOneHand);
					drawNCardsPlayer(playerOneHand, playerTwoHand, numCardsToDraw);
					printHand(face, suit, playerOneHand);
				}
				playerOneScore = evaluateHand(playerOneHand);
				compCardsToDraw = dealerAI(playerTwoHand, playerOneScore, playerTwoScore);
				drawNCards(playerTwoHand, playerOneHand, compCardsToDraw);
				playerTwoScore = evaluateHand(playerTwoHand);
				if (playerOneScore > playerTwoScore) {
					//player 1 has the better hand
					printf("You won the hand!\n");
					playerScore++;

				}
				else if (playerTwoScore > playerOneScore || playerTwoScore == playerOneScore) {
					//player 2 has the better hand (house always wins)
					printf("The house won the hand.\n");
					houseScore++;
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