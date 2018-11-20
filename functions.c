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
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deals 5 cards */
	for (card = 1; card <= 5; card++)
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
					hand[card].suitIndex = row;
					hand[card].faceIndex = column;
				}
			}
		}
	}
}

void printHand(const char *wFace[], const char *wSuit[], Card hand[]) {
	for (int i = 1; i <= 5; i++) {
		printf(" %5s of %-8s%c", wFace[hand[i].faceIndex], wSuit[hand[i].suitIndex], i % 2 == 0 ? '\n' : '\t');
	}
}

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

int containsThreeOfAKind(Card hand[], int numTimes[13]) {
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 3) {
			return 1;
		}
	}
	return 0;
}

int containsFourOfAKind(Card hand[], int numTimes[13]) {
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 4) {
			return 1;
		}
	}
	return 0;
}

void calcCountSuit(Card hand[], int suitCount[4]) {
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

int containsFlush(Card hand[], int suitCount[4]) {
	//Hand contains 5 of the same suit
	for (int i = 0; i < SUIT_TYPES; i++) {
		if (suitCount[i] == 5) {
			return 1;
		}
	}
	return 0;
}

int containsStraight(Card hand[], int numTimes[13]) {
	int count = 0;
	//Hand is of 5 consecutive face values
	//There should be a row of five 1's in numTimes consecutively
	for (int i = 0; i < FACE_TYPES; i++) {
		if (numTimes[i] == 1) {
			count++;
		} else {
			count = 0;
		}
	}

	if (count == 5) {
		return 1;	
	}
	return 0;
}

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

char handleCharInput(void) {
	char in = '\0';
	scanf(" %c", &in);
	in = toupper(in);
	return in;
}

void clearScreen(void) {
	system("cls");
}

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

void pressKeyToContinue(void) {
	system("pause");
}

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

void dealerAI(Card hand[], int playerOneScore, int playerTwoScore) {
	if (playerTwoScore <= playerOneScore) {
		if (playerTwoScore < 3) {
			//draw 1 card
		}
		else if (playerTwoScore < 2) {
			//draw 2 cards
		}
		else if (playerTwoScore < 1) {
			//draw 3 cards
		}
	}
	
}