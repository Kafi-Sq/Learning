#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <mutex>

using namespace std;

char space[17] = { 'o', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' };

int stepClock = 1;
int bombClock = 0;
int moveb1 = 0;
int robot;
int bomb1, bomb2;
int gold1, gold2;
int goldCollected = 0;
int gameOver, gameWon = 0;
int wizard = 0;


void board() {

	cout << "t = " << stepClock << endl;
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

void spawnPlayers() {
	srand(time(0));
	robot = (rand() % 16) + 1;
	bomb1 = (rand() % 16) + 1;
	bomb2 = (rand() % 16) + 1;
	gold1 = (rand() % 16) + 1;
	gold2 = (rand() % 16) + 1;

	if (robot == bomb1 || robot == bomb2 || robot == gold1 || robot == gold2) {
		do {
			robot = (rand() % 16) + 1;
		} while (robot != bomb1 && robot != bomb2 && robot != gold1 && robot != gold2);
	}

	if (bomb1 == robot || bomb1 == bomb2 || bomb1 == gold1 || bomb1 == gold2) {
		do {
			bomb1 = (rand() % 16) + 1;
		} while (bomb1 != robot && bomb1 != bomb2 && bomb1 != gold1 && bomb1 != gold2);
	}

	if (bomb2 == robot || bomb2 == bomb1 || bomb2 == gold1 || bomb2 == gold2) {
		do {
			bomb2 = (rand() % 16) + 1;
		} while (bomb2 != robot && bomb2 != bomb1 && bomb2 != gold1 && bomb2 != gold2);
	}

	if (gold1 == robot || gold1 == bomb1 || gold1 == bomb2 || gold1 == gold2) {
		do {
			gold1 = (rand() % 16) + 1;
		} while (gold1 != robot && gold1 != bomb1 && gold1 != bomb2 && gold1 != gold2);
	}

	if (gold2 == robot || gold2 == bomb1 || gold2 == bomb2 || gold2 == gold1) {
		do {
			gold2 = (rand() % 16) + 1;
		} while (gold2 != robot && gold2 != bomb1 && gold2 != bomb2 && gold2 != gold1);
	}

	space[robot] = 'R';
	space[bomb1] = 'B';
	space[bomb2] = 'B';
	space[gold1] = 'G';
	space[gold2] = 'G';

	board();

}

int endGame(int robot, int bomb1, int bomb2) {
	if (robot == gold1 || robot == gold2) {
		goldCollected++;
		if(goldCollected >= 2){
			gameWon = 1;
			gameOver = 1;
		}
	}
	if (robot == bomb1 || robot == bomb2) {
		gameOver = 1;
		return 1;
	}
	return 0;
}

void MoveRobot() {
	srand(time(0));
	if (stepClock == 1) {
		if (space[1] == 'R' || space[13] == 'R') {
			if (space[1] == 'R') {
				space[robot] = '-';
				robot = robot + 5;
				space[robot] = 'R';
			}
			else {
				space[robot] = '-';
				robot = robot - 3;
				space[robot] = 'R';
			}
		}
		else if (space[4] == 'R' || space[16] == 'R') {
			if (space[4] == 'R') {
				space[robot] = '-';
				robot = robot + 3;
				space[robot] = 'R';
			}
			else {
				space[robot] = '-';
				robot = robot - 5;
				space[robot] = 'R';
			}
		}
		else if (space[5] == 'R' || space[9] == 'R') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[robot] = '-';
				robot = robot - 3;
				space[robot] = 'R';
			}
			else {
				space[robot] = '-';
				robot = robot + 5;
				space[robot] = 'R';
			}
		}
		else if (space[8] == 'R' || space[12] == 'R') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[robot] = '-';
				robot = robot - 5;
				space[robot] = 'R';
			}
			else {
				space[robot] = '-';
				robot = robot + 3;
				space[robot] = 'R';
			}
		}
		else if (space[2] == 'R' || space[3] == 'R') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[robot] = '-';
				robot = robot + 3;
				space[robot] = 'R';
			}
			else {
				space[robot] = '-';
				robot = robot + 5;
				space[robot] = 'R';
			}
		}
		else if (space[14] == 'R' || space[15] == 'R') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[robot] = '-';
				robot = robot - 3;
				space[robot] = 'R';
			}
			else {
				space[robot] = '-';
				robot = robot - 5;
				space[robot] = 'R';
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[robot] = '-';
				robot = robot - 5;
				space[robot] = 'R';
			}
			else if (choice == 2) {
				space[robot] = '-';
				robot = robot - 3;
				space[robot] = 'R';
			}
			else if (choice == 3) {
				space[robot] = '-';
				robot = robot + 3;
				space[robot] = 'R';
			}
			else if (choice == 4) {
				space[robot] = '-';
				robot = robot + 5;
				space[robot] = 'R';
			}
		}
		stepClock++;
	}
	else {
		if (space[1] == 'R' || space[13] == 'R' || space[4] == 'R' || space[16] == 'R') {
			if (space[1] == 'R') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot + 1;
					space[robot] = 'R';
				}
				else {
					space[robot] = '-';
					robot = robot + 4;
					space[robot] = 'R';
				}
			}
			else if (space[13] == 'R') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot + 1;
					space[robot] = 'R';
				}
				else {
					space[robot] = '-';
					robot = robot - 4;
					space[robot] = 'R';
				}
			}
			else if (space[4] == 'R') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot - 1;
					space[robot] = 'R';
				}
				else {
					space[robot] = '-';
					robot = robot + 4;
					space[robot] = 'R';
				}
			}
			else if (space[16] == 'R') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot - 1;
					space[robot] = 'R';
				}
				else {
					space[robot] = '-';
					robot = robot - 4;
					space[robot] = 'R';
				}
			}
		}
		else if (space[2] == 'R' || space[3] == 'R' || space[14] == 'R' || space[15] == 'R') {
			if (space[2] == 'R' || space[3] == 'R') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot - 1;
					space[robot] = 'R';
				}
				else if (choice == 2) {
					space[robot] = '-';
					robot = robot + 1;
					space[robot] = 'R';
				}
				else {
					space[robot] = '-';
					robot = robot + 4;
					space[robot] = 'R';
				}
			}
			else {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot - 1;
					space[robot] = 'R';
				}
				else if (choice == 2) {
					space[robot] = '-';
					robot = robot + 1;
					space[robot] = 'R';
				}
				else {
					space[robot] = '-';
					robot = robot - 4;
					space[robot] = 'R';
				}
			}
		}
		else if (space[5] == 'R' || space[9] == 'R' || space[8] == 'R' || space[12] == 'R') {
			if (space[5] == 'R' || space[9] == 'R') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot + 1;
					space[robot] = 'R';
				}
				else if (choice == 2) {
					space[robot] = '-';
					robot = robot + 4;
					space[robot] = 'R';
				}
				else if (choice == 2) {
					space[robot] = '-';
					robot = robot - 4;
					space[robot] = 'R';
				}
			}
			else if (space[8] == 'R' || space[12] == 'R') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[robot] = '-';
					robot = robot - 1;
					space[robot] = 'R';
				}
				else if (choice == 2) {
					space[robot] = '-';
					robot = robot + 4;
					space[robot] = 'R';
				}
				else if (choice == 2) {
					space[robot] = '-';
					robot = robot - 4;
					space[robot] = 'R';
				}
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[robot] = '-';
				robot = robot - 1;
				space[robot] = 'R';
			}
			else if (choice == 2) {
				space[robot] = '-';
				robot = robot + 1;
				space[robot] = 'R';
			}
			else if (choice == 3) {
				space[robot] = '-';
				robot = robot - 4;
				space[robot] = 'R';
			}
			else if (choice == 4) {
				space[robot] = '-';
				robot = robot + 4;
				space[robot] = 'R';
			}
		}
		stepClock--;
	}
	bombClock++;
	board();
	wizard++;
	endGame(robot, bomb1, bomb2);
}

void MoveBomb1() {
	srand(time(0));
	if (stepClock == 1) {
		if (space[1] == 'B' || space[13] == 'B') {
			if (space[1] == 'B') {
				space[bomb1] = '-';
				bomb1 = bomb1 + 5;
				space[bomb1] = 'B';
			}
			else {
				space[bomb1] = '-';
				bomb1 = bomb1 - 3;
				space[bomb1] = 'B';
			}
		}
		else if (space[4] == 'B' || space[16] == 'B') {
			if (space[4] == 'B') {
				space[bomb1] = '-';
				bomb1 = bomb1 + 3;
				space[bomb1] = 'B';
			}
			else {
				space[bomb1] = '-';
				bomb1 = bomb1 - 5;
				space[bomb1] = 'B';
			}
		}
		else if (space[5] == 'B' || space[9] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb1] = '-';
				bomb1 = bomb1 - 3;
				space[bomb1] = 'B';
			}
			else {
				space[bomb1] = '-';
				bomb1 = bomb1 + 5;
				space[bomb1] = 'B';
			}
		}
		else if (space[8] == 'B' || space[12] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb1] = '-';
				bomb1 = bomb1 - 5;
				space[bomb1] = 'B';
			}
			else {
				space[bomb1] = '-';
				bomb1 = bomb1 + 3;
				space[bomb1] = 'B';
			}
		}
		else if (space[2] == 'B' || space[3] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb1] = '-';
				bomb1 = bomb1 + 3;
				space[bomb1] = 'B';
			}
			else {
				space[bomb1] = '-';
				bomb1 = bomb1 + 5;
				space[bomb1] = 'B';
			}
		}
		else if (space[14] == 'B' || space[15] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb1] = '-';
				bomb1 = bomb1 - 3;
				space[bomb1] = 'B';
			}
			else {
				space[bomb1] = '-';
				bomb1 = bomb1 - 5;
				space[bomb1] = 'B';
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[bomb1] = '-';
				bomb1 = bomb1 - 5;
				space[bomb1] = 'B';
			}
			else if (choice == 2) {
				space[bomb1] = '-';
				bomb1 = bomb1 - 3;
				space[bomb1] = 'B';
			}
			else if (choice == 3) {
				space[bomb1] = '-';
				bomb1 = bomb1 + 3;
				space[bomb1] = 'B';
			}
			else if (choice == 4) {
				space[bomb1] = '-';
				bomb1 = bomb1 + 5;
				space[bomb1] = 'B';
			}
		}
	}
	else {
		if (space[1] == 'B' || space[13] == 'B' || space[4] == 'B' || space[16] == 'B') {
			if (space[1] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 + 1;
					space[bomb1] = 'B';
				}
				else {
					space[bomb1] = '-';
					bomb1 = bomb1 + 4;
					space[bomb1] = 'B';
				}
			}
			else if (space[13] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 + 1;
					space[bomb1] = 'B';
				}
				else {
					space[bomb1] = '-';
					bomb1 = bomb1 - 4;
					space[bomb1] = 'B';
				}
			}
			else if (space[4] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 - 1;
					space[bomb1] = 'B';
				}
				else {
					space[bomb1] = '-';
					bomb1 = bomb1 + 4;
					space[bomb1] = 'B';
				}
			}
			else if (space[16] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 - 1;
					space[bomb1] = 'B';
				}
				else {
					space[bomb1] = '-';
					bomb1 = bomb1 - 4;
					space[bomb1] = 'B';
				}
			}
		}
		else if (space[2] == 'B' || space[3] == 'B' || space[14] == 'B' || space[15] == 'B') {
			if (space[2] == 'B' || space[3] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 - 1;
					space[bomb1] = 'B';
				}
				else if (choice == 2) {
					space[bomb1] = '-';
					bomb1 = bomb1 + 1;
					space[bomb1] = 'B';
				}
				else {
					space[bomb1] = '-';
					bomb1 = bomb1 + 4;
					space[bomb1] = 'B';
				}
			}
			else {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 - 1;
					space[bomb1] = 'B';
				}
				else if (choice == 2) {
					space[bomb1] = '-';
					bomb1 = bomb1 + 1;
					space[bomb1] = 'B';
				}
				else {
					space[bomb1] = '-';
					bomb1 = bomb1 - 4;
					space[bomb1] = 'B';
				}
			}
		}
		else if (space[5] == 'B' || space[9] == 'B' || space[8] == 'B' || space[12] == 'B') {
			if (space[5] == 'B' || space[9] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 + 1;
					space[bomb1] = 'B';
				}
				else if (choice == 2) {
					space[bomb1] = '-';
					bomb1 = bomb1 + 4;
					space[bomb1] = 'B';
				}
				else if (choice == 2) {
					space[bomb1] = '-';
					bomb1 = bomb1 - 4;
					space[bomb1] = 'B';
				}
			}
			else if (space[8] == 'B' || space[12] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb1] = '-';
					bomb1 = bomb1 - 1;
					space[bomb1] = 'B';
				}
				else if (choice == 2) {
					space[bomb1] = '-';
					bomb1 = bomb1 + 4;
					space[bomb1] = 'B';
				}
				else if (choice == 2) {
					space[bomb1] = '-';
					bomb1 = bomb1 - 4;
					space[bomb1] = 'B';
				}
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[bomb1] = '-';
				bomb1 = bomb1 - 1;
				space[bomb1] = 'B';
			}
			else if (choice == 2) {
				space[bomb1] = '-';
				bomb1 = bomb1 + 1;
				space[bomb1] = 'B';
			}
			else if (choice == 3) {
				space[bomb1] = '-';
				bomb1 = bomb1 - 4;
				space[bomb1] = 'B';
			}
			else if (choice == 4) {
				space[bomb1] = '-';
				bomb1 = bomb1 + 4;
				space[bomb1] = 'B';
			}
		}
	}
}

void Movebomb2() {
	srand(time(0));
	if (stepClock == 1) {
		if (space[1] == 'B' || space[13] == 'B') {
			if (space[1] == 'B') {
				space[bomb2] = '-';
				bomb2 = bomb2 + 5;
				space[bomb2] = 'B';
			}
			else {
				space[bomb2] = '-';
				bomb2 = bomb2 - 3;
				space[bomb2] = 'B';
			}
		}
		else if (space[4] == 'B' || space[16] == 'B') {
			if (space[4] == 'B') {
				space[bomb2] = '-';
				bomb2 = bomb2 + 3;
				space[bomb2] = 'B';
			}
			else {
				space[bomb2] = '-';
				bomb2 = bomb2 - 5;
				space[bomb2] = 'B';
			}
		}
		else if (space[5] == 'B' || space[9] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb2] = '-';
				bomb2 = bomb2 - 3;
				space[bomb2] = 'B';
			}
			else {
				space[bomb2] = '-';
				bomb2 = bomb2 + 5;
				space[bomb2] = 'B';
			}
		}
		else if (space[8] == 'B' || space[12] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb2] = '-';
				bomb2 = bomb2 - 5;
				space[bomb2] = 'B';
			}
			else {
				space[bomb2] = '-';
				bomb2 = bomb2 + 3;
				space[bomb2] = 'B';
			}
		}
		else if (space[2] == 'B' || space[3] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb2] = '-';
				bomb2 = bomb2 + 3;
				space[bomb2] = 'B';
			}
			else {
				space[bomb2] = '-';
				bomb2 = bomb2 + 5;
				space[bomb2] = 'B';
			}
		}
		else if (space[14] == 'B' || space[15] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[bomb2] = '-';
				bomb2 = bomb2 - 3;
				space[bomb2] = 'B';
			}
			else {
				space[bomb2] = '-';
				bomb2 = bomb2 - 5;
				space[bomb2] = 'B';
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[bomb2] = '-';
				bomb2 = bomb2 - 5;
				space[bomb2] = 'B';
			}
			else if (choice == 2) {
				space[bomb2] = '-';
				bomb2 = bomb2 - 3;
				space[bomb2] = 'B';
			}
			else if (choice == 3) {
				space[bomb2] = '-';
				bomb2 = bomb2 + 3;
				space[bomb2] = 'B';
			}
			else if (choice == 4) {
				space[bomb2] = '-';
				bomb2 = bomb2 + 5;
				space[bomb2] = 'B';
			}
		}
	}
	else {
		if (space[1] == 'B' || space[13] == 'B' || space[4] == 'B' || space[16] == 'B') {
			if (space[1] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 + 1;
					space[bomb2] = 'B';
				}
				else {
					space[bomb2] = '-';
					bomb2 = bomb2 + 4;
					space[bomb2] = 'B';
				}
			}
			else if (space[13] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 + 1;
					space[bomb2] = 'B';
				}
				else {
					space[bomb2] = '-';
					bomb2 = bomb2 - 4;
					space[bomb2] = 'B';
				}
			}
			else if (space[4] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 - 1;
					space[bomb2] = 'B';
				}
				else {
					space[bomb2] = '-';
					bomb2 = bomb2 + 4;
					space[bomb2] = 'B';
				}
			}
			else if (space[16] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 - 1;
					space[bomb2] = 'B';
				}
				else {
					space[bomb2] = '-';
					bomb2 = bomb2 - 4;
					space[bomb2] = 'B';
				}
			}
		}
		else if (space[2] == 'B' || space[3] == 'B' || space[14] == 'B' || space[15] == 'B') {
			if (space[2] == 'B' || space[3] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 - 1;
					space[bomb2] = 'B';
				}
				else if (choice == 2) {
					space[bomb2] = '-';
					bomb2 = bomb2 + 1;
					space[bomb2] = 'B';
				}
				else {
					space[bomb2] = '-';
					bomb2 = bomb2 + 4;
					space[bomb2] = 'B';
				}
			}
			else {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 - 1;
					space[bomb2] = 'B';
				}
				else if (choice == 2) {
					space[bomb2] = '-';
					bomb2 = bomb2 + 1;
					space[bomb2] = 'B';
				}
				else {
					space[bomb2] = '-';
					bomb2 = bomb2 - 4;
					space[bomb2] = 'B';
				}
			}
		}
		else if (space[5] == 'B' || space[9] == 'B' || space[8] == 'B' || space[12] == 'B') {
			if (space[5] == 'B' || space[9] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 + 1;
					space[bomb2] = 'B';
				}
				else if (choice == 2) {
					space[bomb2] = '-';
					bomb2 = bomb2 + 4;
					space[bomb2] = 'B';
				}
				else if (choice == 2) {
					space[bomb2] = '-';
					bomb2 = bomb2 - 4;
					space[bomb2] = 'B';
				}
			}
			else if (space[8] == 'B' || space[12] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[bomb2] = '-';
					bomb2 = bomb2 - 1;
					space[bomb2] = 'B';
				}
				else if (choice == 2) {
					space[bomb2] = '-';
					bomb2 = bomb2 + 4;
					space[bomb2] = 'B';
				}
				else if (choice == 2) {
					space[bomb2] = '-';
					bomb2 = bomb2 - 4;
					space[bomb2] = 'B';
				}
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[bomb2] = '-';
				bomb2 = bomb2 - 1;
				space[bomb2] = 'B';
			}
			else if (choice == 2) {
				space[bomb2] = '-';
				bomb2 = bomb2 + 1;
				space[bomb2] = 'B';
			}
			else if (choice == 3) {
				space[bomb2] = '-';
				bomb2 = bomb2 - 4;
				space[bomb2] = 'B';
			}
			else if (choice == 4) {
				space[bomb2] = '-';
				bomb2 = bomb2 + 4;
				space[bomb2] = 'B';
			}
		}
	}
}


int main() {
	spawnPlayers();
	while (gameOver != 1) {
		if (wizard == 5) {
			thread t4(spawnPlayers);
			wizard = 0;
			cout << "Wizard has changed the board!" << endl;
			t4.join();
		}
		thread t1(MoveRobot);
		if (bombClock == 2) {
			if (moveb1 == 0) {
				thread t2(MoveBomb1);
				moveb1 = 1;
				t2.join();
			}
			else {
				thread t3(Movebomb2);
				moveb1 = 0;
				t3.join();
			}
			bombClock = 0;
		}
		t1.join();
	}


	cout << "Gold Collected: " << goldCollected << endl;

	if (gameOver == 1) {
		cout << "Game Over!" << endl;
	}
	if (gameWon == 1) {
		cout << "Congratulations!!!" << endl;
	}

	return 0;
}