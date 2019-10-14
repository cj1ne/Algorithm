#include <iostream>
#include <vector>
using namespace std;

int h, w;
vector<vector<bool>> a;

bool play() {
	for (int k = 0; k <= w; k++) {
		int j = k;

		for (int i = 0; i < h; i++) {
			if (j - 1 >= 0 && a[i][j - 1] == true) {
				j = j - 1;
			} else if (j < w && a[i][j] == true) {
				j = j + 1;
			}
		}
		if (j != k) return false;
	}
	return true;
}

bool checkLine(int k) {
	int x = k / w;
	int y = k % w;

	if (y - 1 >= 0 && a[x][y - 1] == true) {
		return false;
	}
	
	if (y + 1 < w && a[x][y + 1] == true) {
		return false;
	}
	return true;
}

bool addLine(int count) {
	if (count == 1) {
		for (int i = 0; i < h * w; i++) {
			if (a[i / w][i % w] == true) continue;
			if (checkLine(i) == false) continue;

			a[i / w][i % w] = true;
			
			if (play()) {
				return true;
			}
			else {
				a[i / w][i % w] = false;
			}
		}
	}
	else if (count == 2) {
		for (int i = 0; i < (h * w) - 1; i++) {
			for (int j = i + 1; j < h * w; j++) {
				if (a[i / w][i % w] == true || a[j / w][j % w] == true) continue;
				if (checkLine(i) == false || checkLine(j) == false) continue;

				a[i / w][i % w] = true;
				a[j / w][j % w] = true;

				if (play()) {
					return true;
				}
				else {
					a[i / w][i % w] = false;
					a[j / w][j % w] = false;
				}
			}
		}
	}
	else {
		for (int i = 0; i < (h * w) - 2; i++) {
			for (int j = i + 1; j < (h * w) - 1; j++) {
				for (int k = j + 1; k < h * w; k++) {
					if (a[i / w][i % w] || a[j / w][j % w] || a[k / w][k % w]) continue;
					if (checkLine(i) == false || checkLine(j) == false || checkLine(k) == false) continue;

					a[i / w][i % w] = true;
					a[j / w][j % w] = true;
					a[k / w][k % w] = true;

					if (play()) {
						return true;
					}
					else {
						a[i / w][i % w] = false;
						a[j / w][j % w] = false;
						a[k / w][k % w] = false;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	int n, m, b, c, result = -1;
	cin >> n >> m >> h;

	w = n - 1;
	a.assign(h, vector<bool>(w, false));

	for (int i = 0; i < m; i++) {
		cin >> b >> c;
		a[b - 1][c - 1] = true;
	}

	if (play()) {
		cout << 0 << "\n";
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (addLine(i)) {
				result = i;
				break;
			}
		}
		cout << result << "\n";
	}
	return 0;
}