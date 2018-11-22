#include "functions.h"

/* shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], Card handTwo[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int i = 1;

					/* deals 10 cards */
	for (card = 1; card <= 10; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					if (card % 2 == 0) {
						//Player's card
						hand[i].suitIndex = row;
						hand[i].faceIndex = column;
						i++;
					} else {
						handTwo[i].suitIndex = row;
						handTwo[i].faceIndex = column;
					}
				}
			}
		}
	}
}

//Function printHand, no return, parameters string arrays wFace and Wsuit, array of Cards.
//Removed print functionality from deal function and labeled individual indices for a hand.
void printHand(const char *wFace[], const char *wSuit[], Card hand[]) {
	for (int i = 1; i <= 5; i++) {
		printf("%d: %5s of %-8s%c", i, wFace[hand[i].faceIndex], wSuit[hand[i].suitIndex], i % 2 == 0 ? '\n' : '\t');
	}
}

//Function calcNumTimes, no return, parameters array of Card objects hand and array of integers numTimes.
//Populates numTimes array with specific count of every face card.
//For example, numTimes at index 0 will contain 4 if there are 4 aces in a hand.
void calcNumTimes(Card hand[], int numTimes[13]) {
	//Reinitializes array
	for (int i = 0; i < FACE_TYPES; i++) {
		numTimes[i] = 0;
	}

	//Populate numTimes array with count of every specific face card
	for (int i = 1; i < HAND_SIZE; i++) {
		switch (hand[i].faceIndex) {
		case 0: //Ace
			numTimes[0]++;
			break;
		case 1: //Deuce
			numTimes[1]++;
			break;
		case 3: //Three
			numTimes[2]++;
			break;
		case 4: //Four
			numTimes[3]++;
			break;
		case 5: //Five
			numTimes[4]++;
			break;
		case 6: //Six
			numTimes[5]++;
			break;
		case 7: //Seven
			numTimes[6]++;
			break;
		case 8: //Eight
			numTimes[7]++;
			break;
		case 9: //Nine
			numTimes[8]++;
			break;
		case 10: //Ten
			numTimes[9]++;
			break;
		case 11: //Jack
			numTimes[10]++;
			break;
		case 12: //Queen
			numTimes[11]++;
			break;
		case 13: //King
			numTimes[12]++;
			break;
		}
	}
}

//Function containsPair, return integer, parameters array of Card objects hand and array of integers numTimes.
//Prerequisite: calcNumTimes has been called
//Sees if numTimes contains a 2 (has a pair), returns 1 if so and 0 if not.
int containsPair(Card hand[], int numTimes[13]) {
	//Two of the same face indices in hand array
	//Iterate through all possible options for face values (indices 0-12)
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 2) {
			return 1;
		}
	}
	return 0;
}

//Function containsTwoPair, return integer, parameters array of Card objects hand and array of integers numTimes.
//Prerequisite: calcNumTimes has been called
//Essentially does the same logic as containsPair twice with an additional count variable for tracking, returning 1
//if true, 0 if false.
int containsTwoPair(Card hand[], int numTimes[13]) {
	int count = 0;
	//Two of the same face indices in hand array... twice
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 2) {
			count++;
		}
	}
	if (count == 2) {
		return 1;
	}
	return 0;
}

//Function containsThreeOfAKind, return integer, parameters array of Card objects hand and array of integers numTimes.
//Prerequisite: calcNumTimes has been called
//Checks if numTimes contains a 3 (3 cards with same face value), returns 1 if so, 0 if not.
int containsThreeOfAKind(Card hand[], int numTimes[13]) {
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 3) {
			return 1;
		}
	}
	return 0;
}

//Function containsFourOfAKind, return integer, parameters array of Card objects hand and array of integers numTimes.
//Prerequisite: calcNumTimes has been called
//Checks if numTimes contains a 4 (4 cards with same face value), returns 1 if so, 0 if not.
int containsFourOfAKind(Card hand[], int numTimes[13]) {
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 4) {
			return 1;
		}
	}
	return 0;
}

//Function calcCountSuit, no return, parameters array of Card objects hand and array of integers suitCount.
//Populates suitCount array with count of each suit in the hand.
//For example, suitCount at index 0 will contain 5 if all 5 cards in the hand are hearts.
void calcCountSuit(Card hand[], int suitCount[4]) {
	//Reinitializes array
	for (int i = 0; i < SUIT_TYPES; i++) {
		suitCount[i] = 0;
	}

	for (int i = 1; i < HAND_SIZE; i++) {
		switch (hand[i].suitIndex) {
		case 0:
			suitCount[0]++;
			break;
		case 1:
			suitCount[1]++;
			break;
		case 2:
			suitCount[2]++;
			break;
		case 3:
			suitCount[3]++;
			break;
		}
	}
}

//Function containsFlush, return integer, parameters array of Card objects hand, array of integers suitCount
//Prerequisite: calcCountSuit has been called
//Checks if there is a 5 in suitCount array, or if all cards in the hand are of the same suit.
//1 returned if found, 0 if not.
int containsFlush(Card hand[], int suitCount[4]) {
	//Hand contains 5 of the same suit
	for (int i = 0; i < SUIT_TYPES; i++) {
		if (suitCount[i] == 5) {
			return 1;
		}
	}
	return 0;
}

//Function containsStraight, return integer, parameters array of Card objects hand, array of integers numTimes
//Prerequisite: calcNumTimes has been called
//Checks if there are a row of five 1's in numTimes consecutively (hand contains 5 consecutive face values).
//Returns 1 if found, returns 0 if not.
int containsStraight(Card hand[], int numTimes[13]) {
	int count = 0;
	//Hand is of 5 consecutive face values
	//There should be a row of five 1's in numTimes consecutively
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 1) {
			count++;
		} else if (numTimes[i] == 0 && count == 5) {
			return 1;
		} else {
			count = 0;
		}
	}

	if (count == 5) {
		return 1;
	}

	return 0;
}

//Function printMenu, no return, no parameters.
//Prints out the menu using printf functions.
void printMenu(void) {
	//ASCII art generated at http://patorjk.com/software/taag/
	printf(" ########     ######     ###    ########  ########     ########  ########     ###    ##      ##\n");
	printf(" ##          ##    ##   ## ##   ##     ## ##     ##    ##     ## ##     ##   ## ##   ##  ##  ##\n");
	printf(" ##          ##        ##   ##  ##     ## ##     ##    ##     ## ##     ##  ##   ##  ##  ##  ##\n");
	printf(" #######     ##       ##     ## ########  ##     ##    ##     ## ########  ##     ## ##  ##  ##\n");
	printf("       ##    ##       ######### ##   ##   ##     ##    ##     ## ##   ##   ######### ##  ##  ##\n");
	printf(" ##    ##    ##    ## ##     ## ##    ##  ##     ##    ##     ## ##    ##  ##     ## ##  ##  ##\n");
	printf("  ######      ######  ##     ## ##     ## ########     ########  ##     ## ##     ##  ###  ### \n");
	printf("								 implemented by Zach Nett\n");
	printf(" [N]ew Game\n");
	printf(" [R]ules\n");
	printf(" [Q]uit\n");
}

//Function handleCharInput, return character, no parameters.
//Uses a scanf call to read in and return a character from user.
char handleCharInput(void) {
	char in = '\0';
	scanf(" %c", &in);
	in = toupper(in);
	return in;
}

//Function clearScreen, no return, no parameters.
//Uses a system call to clear the screen. (Windows-specific.)
void clearScreen(void) {
	system("cls");
}

//Function evaluateHand, return integer, parameter array of Card objects hand.
//Function to evaluate the parameter hand. It generates and returns a point matrix based on
//aspects of the hand.
int evaluateHand(Card hand[]) {
	int points = 0;
	int numTimes[13], suitCount[4];
	calcNumTimes(hand, numTimes);
	calcCountSuit(hand, suitCount);
	//A pair is worth 1, two pairs is worth 2, three of a kind is worth 3, straight is worth 4, flush 5, four of a kind 6
	if (containsPair(hand, numTimes))
		points++;
	if (containsTwoPair(hand, numTimes) && containsPair(hand, numTimes))
		points++;
	if (containsThreeOfAKind(hand, numTimes))
		points += 3;
	if (containsStraight(hand, numTimes))
		points += 4;
	if (containsFlush(hand, suitCount))
		points += 5;
	if (containsFourOfAKind(hand, numTimes))
		points += 6;
	return points;
}

//Function pressKeyToContinue, no return, no parameters.
//Uses a system call to pause program execution. (Windows-specific.)
void pressKeyToContinue(void) {
	system("pause");
}

//Function reinitializeArrays, no return, parameters arrays of Card objects handOne and handTwo, 2D array of integers deck
//Resets all values of arrays back to 0.
void reinitializeArrays(Card handOne[], Card handTwo[], int deck[4][13]) {
	for (int i = 0; i < 6; i++) {
		handOne[i].faceIndex = 0;
		handOne[i].suitIndex = 0;
		handTwo[i].faceIndex = 0;
		handTwo[i].suitIndex = 0;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[i][j] = 0;
		}
	}
}

//Function dealerAI, return integer, parameters array of Card objects hands, integers playerOneScore and playerTwoScore.
//Prerequisite: evaluateHand called on both hands and stored.
//Determines how many cards the dealer needs to pull based on current hand score.
int dealerAI(Card hand[], int playerOneScore, int playerTwoScore) {
	if (playerTwoScore <= playerOneScore) {
		if (playerTwoScore < 3) {
			//draw 1 card
			return 1;
		}
		else if (playerTwoScore < 2) {
			//draw 2 cards
			return 2;
		}
		else if (playerTwoScore < 1) {
			//draw 3 cards
			return 3;
		}
	}
	return 0;
}

//Function drawNCards, no return, parameters array of Card objects hand and handTwo, integer n
//Generates a random card and index for dealer to draw a card. This will repeat n times.
void drawNCards(Card hand[], Card handTwo[], int n) {
	int usedIndices[6] = { 0 };
	int randIndex = 0, generating = 0, creatingCard = 0, face = 0, suit = 0;
	//Generate random index to place card in
	for (int i = 0; i < n; i++) {
		generating = 1;
		while (generating) {
			randIndex = rand() % 5 + 1;
			for (int j = 1; j < 6; j++) {
				if (randIndex == j && usedIndices[randIndex] == 1) {
					generating = 1;
					break;
				}
				generating = 0;
			}
		}

		creatingCard = 1;
		while (creatingCard) {
			generateCard(&face, &suit);
			if (ifCardHasBeenDrawn(face, suit, hand, handTwo) == 0) {
				creatingCard = 0;
			}
		}
		usedIndices[randIndex] = 1;
		hand[randIndex].faceIndex = face;
		hand[randIndex].suitIndex = suit;
	}
}

//Function drawNCardsPlayer, array of Card objects hand and handTwo, integer n
//Generates a random card to be drawn, requests which card to be drawn, replaces respective card in hand.
void drawNCardsPlayer(Card hand[], Card handTwo[], int n) {
	int input = 0, face = 0, suit = 0, generating = 0;
	for (int i = 0; i < n; i++) {
		generating = 1;
		while (generating) {
			generateCard(&face, &suit);
			if (ifCardHasBeenDrawn(face, suit, hand, handTwo) == 0) {
				generating = 0;
			}
		}
		printf("What card would you like to redraw? 1-5: ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			hand[1].faceIndex = face;
			hand[1].suitIndex = suit;
			break;
		case 2:
			hand[2].faceIndex = face;
			hand[2].suitIndex = suit;
			break;
		case 3:
			hand[3].faceIndex = face;
			hand[3].suitIndex = suit;
			break;
		case 4:
			hand[4].faceIndex = face;
			hand[4].suitIndex = suit;
			break;
		case 5:
			hand[5].faceIndex = face;
			hand[5].suitIndex = suit;
			break;
		}
	}
}

//Function ifCardHasBeenDrawn, return integer, parameters integers desiredFace and desiredSuit, array of Card objects handOne and handTwo.
//Checks if the desiredFace and desiredSuit integers are already in handOne and handTwo, returns 1 if they are, 0 if not.
//This is necessary because the D&D starter code does not modify the deck once a card has been dealt.
int ifCardHasBeenDrawn(int desiredFace, int desiredSuit, Card handOne[], Card handTwo[]) {
	//Check through first hand
	for (int i = 1; i < 6; i++) {
		if ((handOne[i].faceIndex == desiredFace && handOne[i].suitIndex == desiredSuit) || (handTwo[i].faceIndex == desiredFace && handTwo[i].suitIndex == desiredSuit)) {
			return 1;
		}
	}
	return 0;
}

//Function generateCard, no return, parameters pointers to integer face and suit.
//Generates a random number 0-12 and assigns it to indirect value of face pointer.
//Generates a random number 0-3 and assigns it to indirect value of suit pointer.
void generateCard(int *face, int *suit) {
	*face = rand() % 13;
	*suit = rand() % 4;
}