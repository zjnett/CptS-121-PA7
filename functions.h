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

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]);

#endif