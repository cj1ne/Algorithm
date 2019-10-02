#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LEFT = 0;
const int RIGHT = 1;
const int BOTH = 2;
int s, h, w;
string n;
vector<vector<char>> a;

void print() {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}

void displayRow(int i, int index) {
	for (int j = index + 1; j <= index + s; j++) {
		a[i][j] = '-';
	}
}

void displayCol(int i, int index, int where) {
	switch (where) {
	case LEFT:
		a[i][index] = '|';
		break;
	case RIGHT:
		a[i][index + s + 1] = '|';
		break;
	case BOTH:
		a[i][index] = '|';
		a[i][index + s + 1] = '|';
		break;
	}
}

void display(int index, char num) {
	if (num == '0') {
		for (int i = 0; i < h; i++) {
			if (i == 0 || i == h - 1) displayRow(i, index);

			if (i != 0 && i != h - 1 && i != h / 2) {
				displayCol(i, index, BOTH);
			}
		}
	}
	else if (num == '1') {
		for (int i = 0; i < h; i++) {
			if (i != 0 && i != h - 1 && i != h / 2) {
				displayCol(i, index, RIGHT);
			}
		}
	}
	else if (num == '2') {
		for (int i = 0; i < h; i++) {
			if (i > 0 && i < h / 2) {
				displayCol(i, index, RIGHT);
			}
			else if (i > h / 2 && i < h - 1) {
				displayCol(i, index, LEFT);
			}
			else {
				displayRow(i, index);
			}
		}
	}
	else if (num == '3') {
		for (int i = 0; i < h; i++) {
			if (i == 0 || i == h - 1 || i == h / 2) {
				displayRow(i, index);
			}
			else {
				displayCol(i, index, RIGHT);
			}
		}
	}
	else if (num == '4') {
		for (int i = 0; i < h; i++) {
			if (i > 0 && i < h / 2) {
				displayCol(i, index, BOTH);
			}
			else if (i > h / 2 && i < h - 1) {
				displayCol(i, index, RIGHT);
			} 
			else if (i == h / 2) {
				displayRow(i, index);
			}
		}
	}
	else if (num == '5') {
		for (int i = 0; i < h; i++) {
			if (i > 0 && i < h / 2) {
				displayCol(i, index, LEFT);
			}
			else if (i > h / 2 && i < h - 1) {
				displayCol(i, index, RIGHT);
			}
			else {
				displayRow(i, index);
			}
		}
	}
	else if (num == '6') {
		for (int i = 0; i < h; i++) {
			if (i > 0 && i < h / 2) {
				displayCol(i, index, LEFT);
			}
			else if (i > h / 2 && i < h - 1) {
				displayCol(i, index, BOTH);
			}
			else {
				displayRow(i, index);
			}
		}
	}
	else if (num == '7') {
		for (int i = 0; i < h; i++) {
			if (i == 0) {
				displayRow(i, index);
			}
			else if ((i > 0 && i < h / 2) || (i > h / 2 && i < h - 1)) {
				displayCol(i, index, RIGHT);
			}
		}
	}
	else if (num == '8') {
		for (int i = 0; i < h; i++) {
			if (i != 0 && i != h - 1 && i != h / 2) {
				displayCol(i, index, BOTH);
			} 
			else {
				displayRow(i, index);
			}
		}
	}
	else {
		for (int i = 0; i < h; i++) {
			if (i > 0 && i < h / 2) {
				displayCol(i, index, BOTH);
			}
			else if (i > h / 2 && i < h - 1) {
				displayCol(i, index, RIGHT);
			}
			else {
				displayRow(i, index);
			}
		}
	}
}

int main() {
	cin >> s >> n;
	h = (2 * s) + 3;
	w = s + 2;
	a.assign(h, vector<char>(((s + 3) * n.length()) - 1, ' '));

	int index = 0;
	for (int i = 0; i < n.length(); i++) {
		display(index, n[i]);

		index += w;
		if (i != n.length() - 1) {
			index++;
		}
	}
	print();

	return 0;
}