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
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					hand[card].suitIndex = row;
					hand[card].faceIndex = column;
				}
			}
		}
	}
}

void calcNumTimes(Card hand[], int numTimes[13]) {
	//Reinitializes array
	for (int i = 0; i < 13; i++) {
		numTimes[i] = 0;
	}

	//Populate numTimes array with count of every specific face card
	for (int i = 0; i < HAND_SIZE; i++) {
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
	for (int i = 0; i < 13; i++) {
		if (numTimes[i] == 2) {
			return 1;
		}
	}
	return 0;
}

int containsTwoPair(Card hand[], int numTimes[13]) {
	int count = 0;
	//Two of the same face indices in hand array... twice
	for (int i = 0; i < 13; i++) {
		if (numTimes[i] == 2) {
			count++;
		}
	}
	if (count == 2) {
		return 1;
	}
	return 0;
}

int containsThreeOfKind(Card hand[], int numTimes[13]) {
	for (int i = 0; i < 13; i++) {
		if (numTimes[i] == 3) {
			return 1;
		}
	}
	return 0;
}