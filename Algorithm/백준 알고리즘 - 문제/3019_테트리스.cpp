#include <iostream>
#include <vector>
using namespace std;

int w, h;
vector<vector<bool>> a;

bool check(int x, int y) {
	for (int i = h - 1; i > x; i--) {
		if (a[i][y] == false) return false;
	}
	return true;
}

int play1() {
	int result = w;

	for (int i = h - 1; i >= 0; i--) {
		for (int j = 0; j < w - 3; j++) {
			if (a[i][j] || a[i][j + 1] || a[i][j + 2] || a[i][j + 3]) continue;
			if (!check(i, j) || !check(i, j + 1) || !check(i, j + 2) || !check(i, j + 3)) continue;

			result++;
		}
	}
	return result;
}

int play2() {
	int result = 0;

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] || a[i][j + 1] || a[i + 1][j] || a[i + 1][j + 1]) continue;
			if (!check(i + 1, j) || !check(i + 1, j + 1)) continue;

			result++;
		}
	}
	return result;
}

int play3() {
	int result = 0;

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i][j + 1] || a[i][j + 2] || a[i + 1][j] || a[i + 1][j + 1]) continue;
			if (!check(i + 1, j) || !check(i + 1, j + 1) || !check(i, j + 2)) continue;

			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] || a[i + 1][j] || a[i + 1][j + 1] || a[i + 2][j + 1]) continue;
			if (!check(i + 1, j) || !check(i + 2, j + 1)) continue;

			result++;
		}
	}
	return result;
}

int play4() {
	int result = 0;

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i][j] || a[i][j + 1] || a[i + 1][j + 1] || a[i + 1][j + 2]) continue;
			if (!check(i, j) || !check(i + 1, j + 1) || !check(i + 1, j + 2)) continue;

			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i + 1][j] || a[i + 1][j] || a[i + 1][j + 1] || a[i + 2][j]) continue;
			if (!check(i + 1, j + 1) || !check(i + 2, j)) continue;

			result++;
		}
	}
	return result;
}

int play5() {
	int result = 0;

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i][j] || a[i][j + 1] || a[i][j + 2] || a[i + 1][j + 1]) continue;
			if (!check(i, j) || !check(i + 1, j + 1) || !check(i, j + 2)) continue;

			result++;
		}
	}

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i + 1][j] || a[i][j + 1] || a[i + 1][j + 1] || a[i + 1][j + 2]) continue;
			if (!check(i + 1, j) || !check(i + 1, j + 1) || !check(i + 1, j + 2)) continue;

			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] || a[i + 1][j] || a[i + 2][j] || a[i + 1][j + 1]) continue;
			if (!check(i + 2, j) || !check(i + 1, j + 1)) continue;

			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j + 1] || a[i + 1][j + 1] || a[i + 2][j + 1] || a[i + 1][j]) continue;
			if (!check(i + 1, j) || !check(i + 2, j + 1)) continue;

			result++;
		}
	}
	return result;
}

int play6() {
	int result = 0;

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i + 1][j] || a[i + 1][j + 1] || a[i + 1][j + 2] || a[i][j + 2]) continue;
			if (!check(i + 1, j) || !check(i + 1, j + 1) || !check(i + 1, j + 2)) continue;
			result++;
		}
	}

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i][j] || a[i][j + 1] || a[i][j + 2] || a[i + 1][j]) continue;
			if (!check(i + 1, j) || !check(i, j + 1) || !check(i, j + 2)) continue;
			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] || a[i + 1][j] || a[i + 2][j] || a[i + 2][j + 1]) continue;
			if (!check(i + 2, j) || !check(i + 2, j + 1)) continue;

			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] || a[i][j + 1] || a[i + 1][j + 1] || a[i + 2][j + 1]) continue;
			if (!check(i, j) || !check(i + 2, j + 1)) continue;

			result++;
		}
	}
	return result;
}

int play7() {
	int result = 0;

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i][j] || a[i + 1][j] || a[i + 1][j + 1] || a[i + 1][j + 2]) continue;
			if (!check(i + 1, j) || !check(i + 1, j + 1) || !check(i + 1, j + 2)) continue;
			result++;
		}
	}

	for (int i = h - 2; i >= 0; i--) {
		for (int j = 0; j < w - 2; j++) {
			if (a[i][j] || a[i][j + 1] || a[i][j + 2] || a[i + 1][j + 2]) continue;
			if (!check(i, j) || !check(i, j + 1) || !check(i + 1, j + 2)) continue;
			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] || a[i][j + 1] || a[i + 1][j] || a[i + 2][j]) continue;
			if (!check(i + 2, j) || !check(i, j + 1)) continue;

			result++;
		}
	}

	for (int i = h - 3; i >= 0; i--) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j + 1] || a[i + 1][j + 1] || a[i + 2][j + 1] || a[i + 2][j]) continue;
			if (!check(i + 2, j) || !check(i + 2, j + 1)) continue;

			result++;
		}
	}
	return result;
}

int playGame(int index) {
	switch (index) {
	case 1:
		return play1();
	case 2:
		return play2();
	case 3:
		return play3();
	case 4:
		return play4();
	case 5:
		return play5();
	case 6:
		return play6();
	case 7:
		return play7();
	}
}

int main() {
	int index, maxHeight = 0;
	cin >> w >> index;

	vector<int> height(w);

	for (int i = 0; i < w; i++) {
		cin >> height[i];
		if (height[i] > maxHeight) maxHeight = height[i];
	}
	h = maxHeight + 4;
	
	a.assign(h, vector<bool>(w, false));
	for (int j = 0; j < w; j++) {
		for (int i = 1; i <= height[j]; i++) {
			a[h - i][j] = true;
		}
	}

	cout << playGame(index) << "\n";
	return 0;
}