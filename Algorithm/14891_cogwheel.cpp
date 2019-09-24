#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

const int RIGHT_CONNECT = 2;
const int LEFT_CONNECT = 6;
const int ROTATE_RIGHT = 1;
const int ROTATE_LEFT = -1;

string gear[4];

void rotate(string &gear, int direction) {
	char temp;

	if (direction == ROTATE_RIGHT) {
		temp = gear[7];
		gear.erase(7);
		gear = temp + gear;
	}
	else {
		temp = gear[0];
		gear.erase(0, 1);
		gear = gear + temp;
	}
}

void addRotate(int num, int direction, vector<int> &rotateLeft, vector<int> &rotateRight) {
	if (direction == ROTATE_LEFT) {
		rotateLeft.push_back(num);
	}
	else {
		rotateRight.push_back(num);
	}
}

void rotateGear(int num, int direction) {

	vector<int> rotateLeft;
	vector<int> rotateRight;

	for (int i = num; i >= 1; i--) {
		if (gear[i][LEFT_CONNECT] != gear[i - 1][RIGHT_CONNECT]) {
			if ((num - (i - 1)) % 2 == 1) {
				addRotate(i - 1, direction * -1, rotateLeft, rotateRight);
			}
			else {
				addRotate(i - 1, direction, rotateLeft, rotateRight);
			}
		}
		else break;
	}

	for (int i = num; i < 3; i++) {
		if (gear[i][RIGHT_CONNECT] != gear[i + 1][LEFT_CONNECT]) {
			if (((i + 1) - num) % 2 == 1) {
				addRotate(i + 1, direction * -1, rotateLeft, rotateRight);
			}
			else {
				addRotate(i + 1, direction, rotateLeft, rotateRight);
			}
		}
		else break;
	}

	rotate(gear[num], direction);

	for (int i = 0; i < rotateLeft.size(); i++) {
		rotate(gear[rotateLeft[i]], ROTATE_LEFT);
	}

	for (int i = 0; i < rotateRight.size(); i++) {
		rotate(gear[rotateRight[i]], ROTATE_RIGHT);
	}
}

int getScore() {
	int score = 0;

	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == '1') {
			score += (int)pow(2, i);
		}
	}

	return score;
}

int main() {

	int k, num, direction;

	for (int i = 0; i < 4; i++) {
		cin >> gear[i];

	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> num >> direction;
		rotateGear(num - 1, direction);
	}

	cout << getScore() << "\n";

	return 0;
}