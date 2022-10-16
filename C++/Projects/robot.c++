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
int Bomb1, Bomb2;
int GoldBar1, GoldBar2;
int TotalGold = 0;
int gameOver, gameWon = 0;
int wizard = 0;


void Workspace() {

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

void startGame() {
	srand(time(0));
	robot = (rand() % 16) + 1;
	Bomb1 = (rand() % 16) + 1;
	Bomb2 = (rand() % 16) + 1;
	GoldBar1 = (rand() % 16) + 1;
	GoldBar2 = (rand() % 16) + 1;

	if (robot == Bomb1 || robot == Bomb2 || robot == GoldBar1 || robot == GoldBar2) {
		do {
			robot = (rand() % 16) + 1;
		} while (robot != Bomb1 && robot != Bomb2 && robot != GoldBar1 && robot != GoldBar2);
	}

	if (Bomb1 == robot || Bomb1 == Bomb2 || Bomb1 == GoldBar1 || Bomb1 == GoldBar2) {
		do {
			Bomb1 = (rand() % 16) + 1;
		} while (Bomb1 != robot && Bomb1 != Bomb2 && Bomb1 != GoldBar1 && Bomb1 != GoldBar2);
	}

	if (Bomb2 == robot || Bomb2 == Bomb1 || Bomb2 == GoldBar1 || Bomb2 == GoldBar2) {
		do {
			Bomb2 = (rand() % 16) + 1;
		} while (Bomb2 != robot && Bomb2 != Bomb1 && Bomb2 != GoldBar1 && Bomb2 != GoldBar2);
	}

	if (GoldBar1 == robot || GoldBar1 == Bomb1 || GoldBar1 == Bomb2 || GoldBar1 == GoldBar2) {
		do {
			GoldBar1 = (rand() % 16) + 1;
		} while (GoldBar1 != robot && GoldBar1 != Bomb1 && GoldBar1 != Bomb2 && GoldBar1 != GoldBar2);
	}

	if (GoldBar2 == robot || GoldBar2 == Bomb1 || GoldBar2 == Bomb2 || GoldBar2 == GoldBar1) {
		do {
			GoldBar2 = (rand() % 16) + 1;
		} while (GoldBar2 != robot && GoldBar2 != Bomb1 && GoldBar2 != Bomb2 && GoldBar2 != GoldBar1);
	}

	space[robot] = 'R';
	space[Bomb1] = 'B';
	space[Bomb2] = 'B';
	space[GoldBar1] = 'G';
	space[GoldBar2] = 'G';

	Workspace();

}

int gameEnd(int robot, int Bomb1, int Bomb2) {
	if (robot == GoldBar1 || robot == GoldBar2) {
		TotalGold++;
		if(TotalGold >= 2){
			gameWon = 1;
			gameOver = 1;
		}
	}
	if (robot == Bomb1 || robot == Bomb2) {
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
	Workspace();
	wizard++;
	gameEnd(robot, Bomb1, Bomb2);
}

void MoveBomb1() {
	srand(time(0));
	if (stepClock == 1) {
		if (space[1] == 'B' || space[13] == 'B') {
			if (space[1] == 'B') {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 5;
				space[Bomb1] = 'B';
			}
			else {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 3;
				space[Bomb1] = 'B';
			}
		}
		else if (space[4] == 'B' || space[16] == 'B') {
			if (space[4] == 'B') {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 3;
				space[Bomb1] = 'B';
			}
			else {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 5;
				space[Bomb1] = 'B';
			}
		}
		else if (space[5] == 'B' || space[9] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 3;
				space[Bomb1] = 'B';
			}
			else {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 5;
				space[Bomb1] = 'B';
			}
		}
		else if (space[8] == 'B' || space[12] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 5;
				space[Bomb1] = 'B';
			}
			else {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 3;
				space[Bomb1] = 'B';
			}
		}
		else if (space[2] == 'B' || space[3] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 3;
				space[Bomb1] = 'B';
			}
			else {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 5;
				space[Bomb1] = 'B';
			}
		}
		else if (space[14] == 'B' || space[15] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 3;
				space[Bomb1] = 'B';
			}
			else {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 5;
				space[Bomb1] = 'B';
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 5;
				space[Bomb1] = 'B';
			}
			else if (choice == 2) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 3;
				space[Bomb1] = 'B';
			}
			else if (choice == 3) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 3;
				space[Bomb1] = 'B';
			}
			else if (choice == 4) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 5;
				space[Bomb1] = 'B';
			}
		}
	}
	else {
		if (space[1] == 'B' || space[13] == 'B' || space[4] == 'B' || space[16] == 'B') {
			if (space[1] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 1;
					space[Bomb1] = 'B';
				}
				else {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 4;
					space[Bomb1] = 'B';
				}
			}
			else if (space[13] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 1;
					space[Bomb1] = 'B';
				}
				else {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 4;
					space[Bomb1] = 'B';
				}
			}
			else if (space[4] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 1;
					space[Bomb1] = 'B';
				}
				else {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 4;
					space[Bomb1] = 'B';
				}
			}
			else if (space[16] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 1;
					space[Bomb1] = 'B';
				}
				else {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 4;
					space[Bomb1] = 'B';
				}
			}
		}
		else if (space[2] == 'B' || space[3] == 'B' || space[14] == 'B' || space[15] == 'B') {
			if (space[2] == 'B' || space[3] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 1;
					space[Bomb1] = 'B';
				}
				else if (choice == 2) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 1;
					space[Bomb1] = 'B';
				}
				else {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 4;
					space[Bomb1] = 'B';
				}
			}
			else {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 1;
					space[Bomb1] = 'B';
				}
				else if (choice == 2) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 1;
					space[Bomb1] = 'B';
				}
				else {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 4;
					space[Bomb1] = 'B';
				}
			}
		}
		else if (space[5] == 'B' || space[9] == 'B' || space[8] == 'B' || space[12] == 'B') {
			if (space[5] == 'B' || space[9] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 1;
					space[Bomb1] = 'B';
				}
				else if (choice == 2) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 4;
					space[Bomb1] = 'B';
				}
				else if (choice == 2) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 4;
					space[Bomb1] = 'B';
				}
			}
			else if (space[8] == 'B' || space[12] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 1;
					space[Bomb1] = 'B';
				}
				else if (choice == 2) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 + 4;
					space[Bomb1] = 'B';
				}
				else if (choice == 2) {
					space[Bomb1] = '-';
					Bomb1 = Bomb1 - 4;
					space[Bomb1] = 'B';
				}
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 1;
				space[Bomb1] = 'B';
			}
			else if (choice == 2) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 1;
				space[Bomb1] = 'B';
			}
			else if (choice == 3) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 - 4;
				space[Bomb1] = 'B';
			}
			else if (choice == 4) {
				space[Bomb1] = '-';
				Bomb1 = Bomb1 + 4;
				space[Bomb1] = 'B';
			}
		}
	}
}

void MoveBomb2() {
	srand(time(0));
	if (stepClock == 1) {
		if (space[1] == 'B' || space[13] == 'B') {
			if (space[1] == 'B') {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 5;
				space[Bomb2] = 'B';
			}
			else {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 3;
				space[Bomb2] = 'B';
			}
		}
		else if (space[4] == 'B' || space[16] == 'B') {
			if (space[4] == 'B') {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 3;
				space[Bomb2] = 'B';
			}
			else {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 5;
				space[Bomb2] = 'B';
			}
		}
		else if (space[5] == 'B' || space[9] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 3;
				space[Bomb2] = 'B';
			}
			else {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 5;
				space[Bomb2] = 'B';
			}
		}
		else if (space[8] == 'B' || space[12] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 5;
				space[Bomb2] = 'B';
			}
			else {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 3;
				space[Bomb2] = 'B';
			}
		}
		else if (space[2] == 'B' || space[3] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 3;
				space[Bomb2] = 'B';
			}
			else {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 5;
				space[Bomb2] = 'B';
			}
		}
		else if (space[14] == 'B' || space[15] == 'B') {
			int choice = (rand() % 2) + 1;
			if (choice == 1) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 3;
				space[Bomb2] = 'B';
			}
			else {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 5;
				space[Bomb2] = 'B';
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 5;
				space[Bomb2] = 'B';
			}
			else if (choice == 2) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 3;
				space[Bomb2] = 'B';
			}
			else if (choice == 3) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 3;
				space[Bomb2] = 'B';
			}
			else if (choice == 4) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 5;
				space[Bomb2] = 'B';
			}
		}
	}
	else {
		if (space[1] == 'B' || space[13] == 'B' || space[4] == 'B' || space[16] == 'B') {
			if (space[1] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 1;
					space[Bomb2] = 'B';
				}
				else {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 4;
					space[Bomb2] = 'B';
				}
			}
			else if (space[13] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 1;
					space[Bomb2] = 'B';
				}
				else {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 4;
					space[Bomb2] = 'B';
				}
			}
			else if (space[4] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 1;
					space[Bomb2] = 'B';
				}
				else {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 4;
					space[Bomb2] = 'B';
				}
			}
			else if (space[16] == 'B') {
				int choice = (rand() % 2) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 1;
					space[Bomb2] = 'B';
				}
				else {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 4;
					space[Bomb2] = 'B';
				}
			}
		}
		else if (space[2] == 'B' || space[3] == 'B' || space[14] == 'B' || space[15] == 'B') {
			if (space[2] == 'B' || space[3] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 1;
					space[Bomb2] = 'B';
				}
				else if (choice == 2) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 1;
					space[Bomb2] = 'B';
				}
				else {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 4;
					space[Bomb2] = 'B';
				}
			}
			else {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 1;
					space[Bomb2] = 'B';
				}
				else if (choice == 2) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 1;
					space[Bomb2] = 'B';
				}
				else {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 4;
					space[Bomb2] = 'B';
				}
			}
		}
		else if (space[5] == 'B' || space[9] == 'B' || space[8] == 'B' || space[12] == 'B') {
			if (space[5] == 'B' || space[9] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 1;
					space[Bomb2] = 'B';
				}
				else if (choice == 2) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 4;
					space[Bomb2] = 'B';
				}
				else if (choice == 2) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 4;
					space[Bomb2] = 'B';
				}
			}
			else if (space[8] == 'B' || space[12] == 'B') {
				int choice = (rand() % 3) + 1;
				if (choice == 1) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 1;
					space[Bomb2] = 'B';
				}
				else if (choice == 2) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 + 4;
					space[Bomb2] = 'B';
				}
				else if (choice == 2) {
					space[Bomb2] = '-';
					Bomb2 = Bomb2 - 4;
					space[Bomb2] = 'B';
				}
			}
		}
		else {
			int choice = (rand() % 4) + 1;
			if (choice == 1) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 1;
				space[Bomb2] = 'B';
			}
			else if (choice == 2) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 1;
				space[Bomb2] = 'B';
			}
			else if (choice == 3) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 - 4;
				space[Bomb2] = 'B';
			}
			else if (choice == 4) {
				space[Bomb2] = '-';
				Bomb2 = Bomb2 + 4;
				space[Bomb2] = 'B';
			}
		}
	}
}


int main() {
	startGame();
	while (gameOver != 1) {
		if (wizard == 5) {
			thread t4(startGame);
			wizard = 0;
			cout << "Wizard has changed the Workspace!" << endl;
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
				thread t3(MoveBomb2);
				moveb1 = 0;
				t3.join();
			}
			bombClock = 0;
		}
		t1.join();
	}

	if (gameOver == 1) {
		cout << "Gold Collected: " << TotalGold << endl;
		cout << "Game Over! The Robot has hit a bomb."  << endl;
	}
	if (gameWon == 1) {
		cout << "Congratulations! The Robot has collected " << TotalGold << endl;
	}

	return 0;
}