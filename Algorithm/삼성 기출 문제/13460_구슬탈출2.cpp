#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
const int START = 4;

int result = -1;
int h, w;

pair<int, int> moveRight(int x, int y, vector<string> &a) {
	int index = -1;
	for (int j = y + 1; j < w; j++) {
		if (a[x][j] == '.') {
			index = j;
		}
		else {
			break;
		}
	}

	if (index != -1) {
		a[x][index] = a[x][y];
		a[x][y] = '.';
		return make_pair(x, index);
	}
	return make_pair(x, y);
}

pair<int, int> moveLeft(int x, int y, vector<string> &a) {
	int index = -1;
	for (int j = y - 1; j >= 0; j--) {
		if (a[x][j] == '.') {
			index = j;
		}
		else {
			break;
		}
	}

	if (index != -1) {
		a[x][index] = a[x][y];
		a[x][y] = '.';
		return make_pair(x, index);
	}
	return make_pair(x, y);
}

pair<int, int> moveUp(int x, int y, vector<string> &a) {
	int index = -1;
	for (int i = x - 1; i >= 0; i--) {
		if (a[i][y] == '.') {
			index = i;
		}
		else {
			break;
		}
	}

	if (index != -1) {
		a[index][y] = a[x][y];
		a[x][y] = '.';
		return make_pair(index, y);
	}
	return make_pair(x, y);
}

pair<int, int> moveDown(int x, int y, vector<string> &a) {
	int index = -1;
	for (int i = x + 1; i < h; i++) {
		if (a[i][y] == '.') {
			index = i;
		}
		else {
			break;
		}
	}

	if (index != -1) {
		a[index][y] = a[x][y];
		a[x][y] = '.';
		return make_pair(index, y);
	}
	return make_pair(x, y);
}

bool isExit(int x, int y, int direction, vector<string> &a) {
	if (direction == RIGHT) {
		for (int j = y + 1; j < w; j++) {
			if (a[x][j] == '#') return false;
			if (a[x][j] == 'O') return true;
		}
	}
	else if (direction == LEFT) {
		for (int j = y - 1; j >= 0; j--) {
			if (a[x][j] == '#') return false;
			if (a[x][j] == 'O') return true;
		}
	}
	else if (direction == UP) {
		for (int i = x - 1; i >= 0; i--) {
			if (a[i][y] == '#') return false;
			if (a[i][y] == 'O') return true;
		}
	}
	else {
		for (int i = x + 1; i < h; i++) {
			if (a[i][y] == '#') return false;
			if (a[i][y] == 'O') return true;
		}
	}
}

void play(int index, pair<int, int> blue, pair<int, int> red, int before, vector<string> a) {

	if (index == 10) return;

	if (result == -1 || index < result) {
		vector<string> copy = a;
		pair<int, int> newBlue;
		pair<int, int> newRed;

		bool blueExit;
		bool redExit;

		blueExit = isExit(blue.first, blue.second, RIGHT, copy);
		redExit = isExit(red.first, red.second, RIGHT, copy);

		if (blueExit == false && redExit == false) {
			if (before != RIGHT) {
				if (blue.first == red.first && blue.second > red.second) {
					newBlue = moveRight(blue.first, blue.second, copy);
					newRed = moveRight(red.first, red.second, copy);
				}
				else {
					newRed = moveRight(red.first, red.second, copy);
					newBlue = moveRight(blue.first, blue.second, copy);
				}
				play(index + 1, newBlue, newRed, RIGHT, copy);
			}
		}
		else if (blueExit == false && redExit == true) {
			if (result == -1 || index + 1 < result) {
				result = index + 1;
			}
		}

		copy = a;
		blueExit = isExit(blue.first, blue.second, LEFT, copy);
		redExit = isExit(red.first, red.second, LEFT, copy);

		if (blueExit == false && redExit == false) {
			if (before != LEFT) {
				if (blue.first == red.first && blue.second < red.second) {
					newBlue = moveLeft(blue.first, blue.second, copy);
					newRed = moveLeft(red.first, red.second, copy);
				}
				else {
					newRed = moveLeft(red.first, red.second, copy);
					newBlue = moveLeft(blue.first, blue.second, copy);
				}
				play(index + 1, newBlue, newRed, LEFT, copy);
			}
		}
		else if (blueExit == false && redExit) {
			if (result == -1 || index + 1 < result) {
				result = index + 1;
			}
		}

		copy = a;
		blueExit = isExit(blue.first, blue.second, UP, copy);
		redExit = isExit(red.first, red.second, UP, copy);

		if (blueExit == false && redExit == false) {
			if (before != UP) {
				if (blue.second == red.second && blue.first < red.first) {
					newBlue = moveUp(blue.first, blue.second, copy);
					newRed = moveUp(red.first, red.second, copy);
				}
				else {
					newRed = moveUp(red.first, red.second, copy);
					newBlue = moveUp(blue.first, blue.second, copy);
				}
				play(index + 1, newBlue, newRed, UP, copy);
			}
		}
		else if (blueExit == false && redExit) {
			if (result == -1 || index + 1 < result) {
				result = index + 1;
			}

		}

		copy = a;
		blueExit = isExit(blue.first, blue.second, DOWN, copy);
		redExit = isExit(red.first, red.second, DOWN, copy);

		if (blueExit == false && redExit == false) {
			if (before != DOWN) {
				if (blue.second == red.second && blue.first > red.first) {
					newBlue = moveDown(blue.first, blue.second, copy);
					newRed = moveDown(red.first, red.second, copy);
				}
				else {
					newRed = moveDown(red.first, red.second, copy);
					newBlue = moveDown(blue.first, blue.second, copy);
				}
				play(index + 1, newBlue, newRed, DOWN, copy);
			}
		}
		else if (blueExit == false && redExit) {
			if (result == -1 || index + 1 < result) {
				result = index + 1;
			}
		}
	}
}

int main() {
	pair<int, int> blue;
	pair<int, int> red;

	cin >> h >> w;
	vector<string> a(h);

	for (int i = 0; i < h; i++) {
		cin >> a[i];

		for (int j = 0; j < w; j++) {
			if (a[i][j] == 'B') {
				blue = make_pair(i, j);
			}
			else if (a[i][j] == 'R') {
				red = make_pair(i, j);
			}
		}
	}

	play(0, blue, red, START, a);
	cout << result << "\n";
	return 0;
}