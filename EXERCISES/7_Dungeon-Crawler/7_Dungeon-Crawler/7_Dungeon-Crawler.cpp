// 7_DungeonCrawl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define VERTICLE 10		// Board Y axis dimension
#define HORIZONTAL 25	// Board X axis dimension
#define QTY_TRAPS 10 	// Amount of traps to include in game
#define QTY_ENEMIES 15	// Amount of enemies to include in game

void genStatic(int traps[], int& treasure)
// Generate random locations of traps and treasure //
{	
	// Generate traps randomly based on Horizontal and Verticle preprocessor definitions
	srand(unsigned(time(NULL)));
	for (int i=0; i < QTY_TRAPS; i++) {
		traps[i] = rand() % HORIZONTAL * VERTICLE + i;	// Set traps to random spots
		while (traps[i] == 0) {
			traps[i] += 2;	// Avoid trap at player start position
		}
	}
	treasure = rand() % HORIZONTAL * VERTICLE;		// Set treasure to random spot
	while (treasure == 0) {
		treasure++;	// Avoid treasure at player start position
	}
}

void genEnemies(int enemies[])
// Generate random locations of enemies //
{
	for (int i=0; i < QTY_ENEMIES; i++) {
		enemies[i] = rand() % HORIZONTAL * VERTICLE;
		while (enemies[i] == 0) {
			enemies[i] += 2;
		}
	}
}

char getMove (int& pos_player, int traps[], int& treasure, int enemies[])
// Get input and save player moves //
{
	char move = 'z';
	int lost = 0;
	bool needInput = true;
	while (needInput == true) {
		cin >> move;
		switch (move)
		{
			case 'w':
				if (pos_player - HORIZONTAL < 0){						// Stop out of bounds verticle top
					needInput = true;
					cout << "Character is going out of range, try again: ";
					break;
				}
				pos_player = pos_player - HORIZONTAL;	
				needInput = false;
				break;
			case 's':
				if (pos_player + HORIZONTAL >= HORIZONTAL*VERTICLE){		// Stop out of bounds verticle bottom
					needInput = true;
					cout << "Character is going out of range, try again: ";
					break;
				}
				pos_player = pos_player + HORIZONTAL;
				needInput = false;
				break;
			case 'a':
				if (pos_player - 1 < 0){
					needInput = true;
					cout << "Character is going out of range, try again: ";		// Stop out of bounds top horizontal left
					break;
				}
				pos_player = pos_player - 1;
				needInput = false;
				break;
			case 'd':
				if (pos_player + 1 > HORIZONTAL*VERTICLE-1){
					needInput = true;
					cout << "Character is going out of range, try again: ";		// Stop out of bounds horizontal bottom right
					break;
				}
				pos_player = pos_player + 1;
				needInput = false;
				break;
			default:
				cout << "Please enter correct move character: ";
				needInput = true;
				break;
		}
	}

	// Check if player landed on traps to lose
	for (int x=0; x < QTY_TRAPS; x++) {
		if (pos_player == traps[x]) {
			lost = 1;
			return lost;
		}
	}

		// Check if player touched enemies to lose
	for (int x=0; x < QTY_ENEMIES; x++) {
		if (pos_player == enemies[x]) {
			lost = 1;
			return lost;
		}
	}

	// Check if player landed on treasure to win
	if (pos_player == treasure) {
		lost = 2;
		return lost;
	} else {
	lost = 0;
	return lost;
	}
}

int drawDungeon (char board[VERTICLE][HORIZONTAL], int traps[], int treasure, int& pos_player, int enemies[])
// Draw the dungeon, according to values in board[][] //
{
	char symbol = '.';
	int place = 0;
	int randDirection = 0;
	system("cls");
	cout << "\n\n\t\tDungeon Crawler - by r0cc0 c4st0r0\n\n";
	cout << "Get(u) to the treasure($) by navigating through the traps(*) and enemies >!\n\n\n";


	// Move enemies on board every turn in random direction
	srand(unsigned(time(NULL)));
	for (int i=0; i < QTY_ENEMIES; i++) {
		while (true) {
			randDirection = rand() % 3;
			if (randDirection == 0) {
				if (enemies[i] + 1 > HORIZONTAL*VERTICLE-1){
					enemies[i] = enemies[i] - 1;
					break;
				}else{
					enemies[i] = enemies[i] + 1;
					break;
				}
			}else if (randDirection == 1){
				if (enemies[i] - 1 < 0) {
					enemies[i] = enemies[i] + 1;
				}else{
					enemies[i] = enemies[i] - 1;
					break;
				}
			}else if (randDirection == 2){
				if (enemies[i] + HORIZONTAL > 120){
					enemies[i] = enemies[i] - HORIZONTAL;
					break;
				}else{
					enemies[i] = enemies[i] + HORIZONTAL;
					break;
				}
			}else if (randDirection == 3){
				if (enemies[i] - HORIZONTAL < 0){
					enemies[i] = enemies[i] + HORIZONTAL;
					break;
				}else{
					enemies[i] = enemies[i] - HORIZONTAL;
					break;
				}
			}
		}
	}

	// // Lay board elements // //
	for (int j=0; j<VERTICLE; j++){
		cout << "\t   ";
		for (int i=0; i<HORIZONTAL; i++){

			// Lay treasure  and player on board
			if (treasure == place){
				symbol = '$';
			}else if (pos_player == place){
				symbol = 'u';
			}else{
				symbol = '.';
			}

			// Lay traps on board
			for (int x= 0; x < QTY_TRAPS; x++) {
				if (traps[x] != treasure) {
					if (traps[x] == place)
						symbol = '*';
				}
			}

			// Lay enemies on board
			for (int x= 0; x < QTY_ENEMIES; x++) {
				if (enemies[x] == place)
					symbol = '>';
				if (enemies[x] == pos_player)
					return 1;
			}

			board[j][i] = symbol;
			cout << " " << board[j][i];
			place++;
		}
		cout << "\n";
	}
	cout << "\n" << pos_player << "\n";
	cout << "\n\tControls: w-(Up), s-(Down), a-(Left), d-(Right)\n";
	cout << "\n\t\t\tEnter your move: ";
}

void play (int traps[], int& treasure, int enemies[])
{
	char board [VERTICLE][HORIZONTAL];
	int pos_player = 0;
	int stillPlay = 0;
	int turn = 0;
	genEnemies(enemies);
	while (stillPlay == 0) {
		stillPlay = drawDungeon(board, traps, treasure, pos_player, enemies);
		if (stillPlay == 1)
			break;
		stillPlay = getMove(pos_player, traps, treasure, enemies);
		turn++;
	}

	if (stillPlay == 1)
		cout << "\n\n\t\aYou lost... Really? Try again...\n";
	else
		cout << "\n\n\t\a\a\aYou WIN!\tWinner, Winner, Chicken Dinner\n";
}

int main ()
{
	
	int traps[QTY_TRAPS];			// Declare traps
	int enemies[QTY_ENEMIES];	// Declare Enemies
	int treasure = 1;						// Declare treasure
	char quarter = 'y';					// Play again?
	char tmp = 'z';

	// Run game  ///////////////////////////////////////
	while (quarter == 'y' || quarter == 'Y') {
		genStatic(traps, treasure);
		play(traps, treasure, enemies);
		cout << "\tInsert 25 Cents? y or n: ";
		cin >> quarter;
	}
	cout << "\n\nThanks for playing! Enter q to exit\n\n\n";
	cin >> tmp;
}