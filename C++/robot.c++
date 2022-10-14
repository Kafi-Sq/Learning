#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

int robot;
int bomb;
int gold1;
int gold2;
int steps = 0;
int endGame = 0;
char space[17] = { 'o', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' };

void field() {
	system("cls");
	cout << steps << endl;
	cout << endl;

	cout << "--------------------------" << endl;
	cout << "|  " << space[1] << "  |  " << space[2] << "  |  " << space[3] << "  |  " << space[4] << "  |" << endl;
	cout << "--------------------------" << endl;
	cout << "|  " << space[5] << "  |  " << space[6] << "  |  " << space[7] << "  |  " << space[8] << "  |" << endl;
	cout << "--------------------------" << endl;
	cout << "|  " << space[9] << "  |  " << space[10] << "  |  " << space[11] << "  |  " << space[12] << "  |" << endl;
	cout << "--------------------------" << endl;
	cout << "|  " << space[13] << "  |  " << space[14] << "  |  " << space[15] << "  |  " << space[16] << "  |" << endl;
	cout << "--------------------------" << endl;
}

void move() {
	int move = rand() % 3;
	cout << move << endl;

	if (steps == 2) {
		int BMove = rand() % 3;
		if (move == 1 || move == 2) {
			(move == 1) ? space[robot + 1] == 'B' : space[robot - 1] = 'B';
		}
		steps = 0;
	}

	if (move == 1 || move == 2) {
		if (space[robot] != 1 && space[robot] != 16) {
			if (space[robot - 1] == 'G' || space[robot + 1] == 'G') {
				cout << "Found Gold";
				endGame++;
			}
			else if (space[robot - 1] == 'B' || space[robot + 1] == 'B') {
				cout << "Hit Bomb";
				endGame++;
			}
			else {
				(move == 1) ? space[robot + 1] == 'R' : space[robot - 1] = 'R';
			}
		}
		else {
			(move == 1) ? space[1] = 'R' : space[16] = 'R';
		}
		space[robot] = '-';
		steps++;
	}
	else {
		space[robot] = 'R';
	}
}

void play() {
	// draw field

	// Spawn robot, bomb, and gold in random places
	robot = rand() % 17;
	bomb = rand() % 17;
	gold1 = rand() % 17;
	gold2 = rand() % 17;
	field();

	if (robot == 1) {
		space[1] = 'R';
	}
	else if (robot == 2) {
		space[2] = 'R';
	}
	else if (robot == 3) {
		space[3] = 'R';

	}
	else if (robot == 4) {
		space[4] = 'R';
	}
	else if (robot == 5) {
		space[5] = 'R';

	}
	else if (robot == 6) {
		space[6] = 'R';
	}
	else if (robot == 7) {
		space[7] = 'R';

	}
	else if (robot == 8) {
		space[8] = 'R';
	}
	else if (robot == 9) {
		space[9] = 'R';

	}
	else if (robot == 10) {
		space[10] = 'R';

	}
	else if (robot == 11) {
		space[11] = 'R';

	}
	else if (robot == 12) {
		space[12] = 'R';

	}
	else if (robot == 13) {
		space[13] = 'R';

	}
	else if (robot == 14) {
		space[14] = 'R';

	}
	else if (robot == 15) {
		space[15] = 'R';

	}
	else if (robot == 16) {
		space[16] = 'R';

	}

	if (bomb == 1) {
		space[1] = 'B';
	}
	else if (bomb == 2) {
		space[2] = 'B';
	}
	else if (bomb == 3) {
		space[3] = 'B';

	}
	else if (bomb == 4) {
		space[4] = 'B';
	}
	else if (bomb == 5) {
		space[5] = 'B';

	}
	else if (bomb == 6) {
		space[6] = 'B';
	}
	else if (bomb == 7) {
		space[7] = 'B';

	}
	else if (bomb == 8) {
		space[8] = 'B';
	}
	else if (bomb == 9) {
		space[9] = 'B';

	}
	else if (bomb == 10) {
		space[10] = 'B';

	}
	else if (bomb == 11) {
		space[11] = 'B';

	}
	else if (bomb == 12) {
		space[12] = 'B';

	}
	else if (bomb == 13) {
		space[13] = 'B';

	}
	else if (bomb == 14) {
		space[14] = 'B';

	}
	else if (bomb == 15) {
		space[15] = 'B';

	}
	else if (bomb == 16) {
		space[16] = 'B';

	}

	if (gold1 == 1) {
		space[1] = 'G';
	}
	else if (gold1 == 2) {
		space[2] = 'G';
	}
	else if (gold1 == 3) {
		space[3] = 'G';

	}
	else if (gold1 == 4) {
		space[4] = 'G';
	}
	else if (gold1 == 5) {
		space[5] = 'G';

	}
	else if (gold1 == 6) {
		space[6] = 'G';
	}
	else if (gold1 == 7) {
		space[7] = 'G';

	}
	else if (gold1 == 8) {
		space[8] = 'G';
	}
	else if (gold1 == 9) {
		space[9] = 'G';

	}
	else if (gold1 == 10) {
		space[10] = 'G';

	}
	else if (gold1 == 11) {
		space[11] = 'G';

	}
	else if (gold1 == 12) {
		space[12] = 'G';

	}
	else if (gold1 == 13) {
		space[13] = 'G';

	}
	else if (gold1 == 14) {
		space[14] = 'G';

	}
	else if (gold1 == 15) {
		space[15] = 'G';

	}
	else if (gold1 == 16) {
		space[16] = 'G';

	}

	if (gold2 == 1) {
		space[1] = 'G';
	}
	else if (gold2 == 2) {
		space[2] = 'G';
	}
	else if (gold2 == 3) {
		space[3] = 'G';

	}
	else if (gold2 == 4) {
		space[4] = 'G';
	}
	else if (gold2 == 5) {
		space[5] = 'G';

	}
	else if (gold2 == 6) {
		space[6] = 'G';
	}
	else if (gold2 == 7) {
		space[7] = 'G';

	}
	else if (gold2 == 8) {
		space[8] = 'G';
	}
	else if (gold2 == 9) {
		space[9] = 'G';

	}
	else if (gold2 == 10) {
		space[10] = 'G';

	}
	else if (gold2 == 11) {
		space[11] = 'G';

	}
	else if (gold2 == 12) {
		space[12] = 'G';

	}
	else if (gold2 == 13) {
		space[13] = 'G';

	}
	else if (gold2 == 14) {
		space[14] = 'G';

	}
	else if (gold2 == 15) {
		space[15] = 'G';

	}
	else if (gold2 == 16) {
		space[16] = 'G';

	}

	field();

	// Move robot one step
	do {
		move();
		field();
	} while (endGame != 1);
	// record how many steps she took
	// check if bomb or gold

	// if neither
}



int main() {
	srand(time(0));
	play();

	return 0;
}