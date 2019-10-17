#include <iostream>
#include <vector>
using namespace std;
const int START = 0;
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

int n;
int result;

void shift_up(vector<vector<int>> &a) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 0) continue;

			int index = -1;
			for (int k = i - 1; k >= 0; k--) {
				if (a[k][j] == 0) {
					index = k;
				}
			}

			if (index != -1) {
				a[index][j] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
}

void shift_down(vector<vector<int>> &a) {
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j] == 0) continue;

			int index = -1;
			for (int k = i + 1; k < n; k++) {
				if (a[k][j] == 0) {
					index = k;
				}
			}

			if (index != -1) {
				a[index][j] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
}

void shift_left(vector<vector<int>> &a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) continue;

			int index = -1;
			for (int k = j - 1; k >= 0; k--) {
				if (a[i][k] == 0) {
					index = k;
				}
			}

			if (index != -1) {
				a[i][index] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
}

void shift_right(vector<vector<int>> &a) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] == 0) continue;

			int index = -1;
			for (int k = j + 1; k < n; k++) {
				if (a[i][k] == 0) {
					index = k;
				}
			}

			if (index != -1) {
				a[i][index] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
}

void merge_up(vector<vector<int>> &a) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i][j] == a[i + 1][j]) {
				a[i][j] *= 2;
				a[i + 1][j] = 0;
			}
		}
	}
}

void merge_down(vector<vector<int>> &a) {
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i > 0; i--) {
			if (a[i][j] == a[i - 1][j]) {
				a[i][j] *= 2;
				a[i - 1][j] = 0;
			}
		}
	}
}

void merge_left(vector<vector<int>> &a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] == a[i][j + 1]) {
				a[i][j] *= 2;
				a[i][j + 1] = 0;
			}
		}
	}
}

void merge_right(vector<vector<int>> &a) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (a[i][j] == a[i][j - 1]) {
				a[i][j] *= 2;
				a[i][j - 1] = 0;
			}
		}
	}
}

vector<vector<int>> up(vector<vector<int>> a) {
	shift_up(a);
	merge_up(a);
	shift_up(a);
	return a;
}

vector<vector<int>> down(vector<vector<int>> a) {
	shift_down(a);
	merge_down(a);
	shift_down(a);
	return a;
}

vector<vector<int>> left(vector<vector<int>> a) {
	shift_left(a);
	merge_left(a);
	shift_left(a);
	return a;
}

vector<vector<int>> right(vector<vector<int>> a) {
	shift_right(a);
	merge_right(a);
	shift_right(a);
	return a;
}

int get_max(vector<vector<int>> a) {
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}

void go(int selected, int before, vector<vector<int>> a) {
	if (selected == 5) {
		int max = get_max(a);
		if (max > result) {
			result = max;
		}
		return;
	}

	if (before != UP) go(selected + 1, UP, up(a));
	if (before != DOWN) go(selected + 1, DOWN,down(a));
	if (before != RIGHT) go(selected + 1, RIGHT,right(a));
	if (before != LEFT) go(selected + 1, LEFT,left(a));
}

int main() {
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	result = get_max(a);
	go(0, START, a);

	cout << result;
	return 0;
}