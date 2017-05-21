// 6_TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct player {
	int move;
} p1[9], p2[9];

bool checkMarks(int move, char squares[]){		// Check if move exists in history
	// move + '0' - This converts the int to a char with the same value. i.e. int 5, will be char '5'.
	// squares[ move ] - This will check the index of the number entered.
	//		User enters '1', squares[ 1 ] hasn't been used, so it's sill '1'.
	if( ( move + '0' ) == squares[ move ] )
		return false;

	return true;
}

bool chickenDinner(char squares[], bool& winner, char mark) {		// Winner, Winner, Chicken Dinner - Check
	if (squares[0] == mark && squares[1] == mark && squares[2] == mark) {
		return true;
	}else if (squares[3] == mark && squares[4] == mark && squares[5] == mark){
		return true;
	}else if (squares[6] == mark && squares[7] == mark && squares[8] == mark){
		return true;
	}else if (squares[0] == mark && squares[4] == mark && squares[8] == mark){
		return true;
	}else if (squares[2] == mark && squares[4] == mark && squares[6] == mark){
		return true;
	}else if (squares[0] == mark && squares[3] == mark && squares[6] == mark){
		return true;
	}else if (squares[1] == mark && squares[4] == mark && squares[7] == mark){
		return true;
	}else if (squares[2] == mark && squares[5] == mark && squares[8] == mark){
		return true;
	}else{
		return false;
	}
}

void drawBoard(char squares[]) {		// Board
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)\tPlayer 2(O)\n\n";
	cout << "     |     |     " << endl;
	cout << "  " << squares[0] << "  |  " << squares[1] << "  |  " << squares[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << squares[3] << "  |  " << squares[4] << "  |  " << squares[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << squares[6] << "  |  " << squares[7] << "  |  " << squares[8] << endl << endl << endl;
}


void play(char squares[]) {			// Get player moves and load other functions
	drawBoard(squares);
	int count = 1;
	bool winner = false;
	int indexP1 = 0;
	int indexP2 = 0;
	char mark = 'Z';
	int player = 0;
	while (winner == false) {
		for (int i=0; i<9; i++) {
				bool used = true;
				bool cont = true;
				if (count % 2 != 0) {
					mark = 'X';
					while (used == true || p1[indexP1].move > 8) {
						cout << "\aPlayer 1 (X) please select a block to mark.";
						cin >> p1[indexP1].move;
						used = checkMarks(p1[indexP1].move, squares);
					}
					squares[p1[indexP1].move] = 'X';
					indexP1++;
					count++;
				}else{
					mark = 'O';
					while (used == true|| p1[indexP1].move > 8) {
						cout << "\aPlayer 2 (O) please select a block to mark.";
						cin >> p2[indexP2].move;
						used = checkMarks(p2[indexP2].move, squares);
					}
					squares[p2[indexP2].move] = 'O';
					indexP2++;
					count--;
				}

				while (cont == true) {
					drawBoard(squares);
					winner = chickenDinner(squares, winner, mark);
					cont = false;
				}

				if (winner == true && mark == 'X'){
					player = 1;
					break;
				}else if (winner == true && mark == 'O'){
					player = 2;
					break;
				}
			}	
	}
	cout << "\n\n\a\a\a\aPlayer " << player << " wins!\n\n" << endl;
}

int main()
{
	char squares[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
	play(squares);
	cin.get();
}

