#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;

void rotateLeft(int base, vector<vector<string>> &cube) {
	string copy[3] = { cube[base][0], cube[base][1], cube[base][2] };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[base][2 - j][i] = copy[i][j];
		}
	}

	if (base == UP) {
		string save = cube[LEFT][0];

		cube[LEFT][0] = cube[BACK][0];
		cube[BACK][0] = cube[RIGHT][0];
		cube[RIGHT][0] = cube[FRONT][0];
		cube[FRONT][0] = save;
	}
	else if (base == DOWN) {
		string save = cube[LEFT][2];

		cube[LEFT][2] = cube[FRONT][2];
		cube[FRONT][2] = cube[RIGHT][2];
		cube[RIGHT][2] = cube[BACK][2];
		cube[BACK][2] = save;
	}
	else if (base == FRONT) {
		string save = cube[UP][2];

		for (int i = 0; i < 3; i++) {
			cube[UP][2][i] = cube[RIGHT][i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[RIGHT][i][0] = cube[DOWN][0][2 - i];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][0][i] = cube[LEFT][i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[LEFT][i][2] = save[2 - i];
		}
	}
	else if (base == BACK) {
		string save = cube[UP][0];

		for (int i = 0; i < 3; i++) {
			cube[UP][0][2 - i] = cube[LEFT][i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[LEFT][i][0] = cube[DOWN][2][i];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][2][i] = cube[RIGHT][2 - i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[RIGHT][i][2] = save[i];
		}
	}
	else if (base == LEFT) {
		string save = { cube[UP][0][0], cube[UP][1][0], cube[UP][2][0] };

		for (int i = 0; i < 3; i++) {
			cube[UP][i][0] = cube[FRONT][i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[FRONT][i][0] = cube[DOWN][i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][i][0] = cube[BACK][2 - i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[BACK][i][2] = save[2 - i];
		}
	}
	else {
		string save = { cube[UP][0][2], cube[UP][1][2], cube[UP][2][2] };

		for (int i = 0; i < 3; i++) {
			cube[UP][2 - i][2] = cube[BACK][i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[BACK][i][0] = cube[DOWN][2 - i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][i][2] = cube[FRONT][i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[FRONT][i][2] = save[i];
		}
	}
}

void rotateRight(int base, vector<vector<string>> &cube) {
	string copy[3] = { cube[base][0], cube[base][1], cube[base][2] };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[base][j][2 - i] = copy[i][j];
		}
	}

	if (base == UP) {
		string save = cube[LEFT][0];

		cube[LEFT][0] = cube[FRONT][0];
		cube[FRONT][0] = cube[RIGHT][0];
		cube[RIGHT][0] = cube[BACK][0];
		cube[BACK][0] = save;
	}
	else if (base == DOWN) {
		string save = cube[LEFT][2];

		cube[LEFT][2] = cube[BACK][2];
		cube[BACK][2] = cube[RIGHT][2];
		cube[RIGHT][2] = cube[FRONT][2];
		cube[FRONT][2] = save;
	}
	else if (base == FRONT) {
		string save = cube[UP][2];

		for (int i = 0; i < 3; i++) {
			cube[UP][2][2 - i] = cube[LEFT][i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[LEFT][i][2] = cube[DOWN][0][i];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][0][i] = cube[RIGHT][2 - i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[RIGHT][i][0] = save[i];
		}
	}
	else if (base == BACK) {
		string save = cube[UP][0];

		for (int i = 0; i < 3; i++) {
			cube[UP][0][i] = cube[RIGHT][i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][2][i] = cube[LEFT][i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[LEFT][i][0] = save[2 - i];
		}
	}
	else if (base == LEFT) {
		string save = { cube[UP][0][0], cube[UP][1][0], cube[UP][2][0] };

		for (int i = 0; i < 3; i++) {
			cube[UP][i][0] = cube[BACK][2 - i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[BACK][i][2] = cube[DOWN][2 - i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][i][0] = cube[FRONT][i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[FRONT][i][0] = save[i];
		}
	}
	else {
		string save = { cube[UP][0][2], cube[UP][1][2], cube[UP][2][2] };
	
		for (int i = 0; i < 3; i++) {
			cube[UP][i][2] = cube[FRONT][i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[FRONT][i][2] = cube[DOWN][i][2];
		}

		for (int i = 0; i < 3; i++) {
			cube[DOWN][i][2] = cube[BACK][2 - i][0];
		}

		for (int i = 0; i < 3; i++) {
			cube[BACK][i][0] = save[2 - i];
		}
	}
}

void play(vector<string> &s) {
	vector<vector<string>> cube(6, vector<string>(3));
	int position = UP;

	for (string color : {"www", "yyy", "rrr", "ooo", "ggg", "bbb"}) {
		for (int i = 0; i < 3; i++) {
			cube[position][i] = color;
		}
		position++;
	}

	for (int i = 0; i < s.size(); i++) {
		int base = 0;
		char direction = s[i][1];

		switch (s[i][0]) {
		case 'L': base = LEFT;
			break;
		case 'R': base = RIGHT;
			break;
		case 'U': base = UP;
			break;
		case 'D': base = DOWN;
			break;
		case 'F': base = FRONT;
			break;
		case 'B': base = BACK;
			break;
		}

		if (direction == '-') {
			rotateLeft(base, cube);
		}
		else {
			rotateRight(base, cube);
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << cube[UP][i] << "\n";
	}
}

int main() {
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<string> s(n);

		for (int j = 0; j < n; j++) {
			cin >> s[j];
		}
		play(s);
	}
	return 0;
}