/**************************************************
Programmer: Zach Nett
Class: CptS 121 Fall 2018
Date: November 7 2018
Purpose: An implementation of 5-Card-Draw Poker.
***************************************************/
//Starting Code Authors: Deitel & Deitel - C How to Program
//Starting Code copied from https://eecs.wsu.edu/~aofallon/cpts121/progassignments/main.c

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#define HAND_SIZE 6
#define FACE_TYPES 13
#define SUIT_TYPES 4
//Datatype Initialization
typedef struct {
	int faceIndex;
	int suitIndex;
} Card;

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[]);
void printHand(const char *wFace[], const char *wSuit[], Card hand[]);
void calcNumTimes(Card hand[], int numTimes[13]);
int containsPair(Card hand[], int numTimes[13]);
int containsTwoPair(Card hand[], int numTimes[13]);
int containsThreeOfAKind(Card hand[], int numTimes[13]);
int containsFourOfAKind(Card hand[], int numTimes[13]);
void calcCountSuit(Card hand[], int suitCount[4]);
int containsFlush(Card hand[], int suitCount[4]);
int containsStraight(Card hand[], int numTimes[13]);
void printMenu(void);
char handleCharInput(void);
void clearScreen(void);
int evaluateHand(Card hand[]);
void pressKeyToContinue(void);
void reinitializeArrays(Card handOne[], Card handTwo[], int deck[4][13]);
int dealerAI(Card hand[], int playerOneScore, int playerTwoScore);
void drawNCards(Card hand[], int n, int deck[4][13], int rowCount, int colCount);
void drawNCardsPlayer(Card hand[], int n, int deck[4][13], int *rowCount, int *colCount);

#endif