#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int h, w, result = 100;
vector<tuple<int, int, int>> camera;

int getBlindSpot(vector<vector<int>> a) {
	int blindSpot = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0) blindSpot++;
		}
	}
	return blindSpot;
}

void mornitoring(int x, int y, vector<vector<int>> &a, int direction) {
	if (direction == RIGHT) {
		for (int i = y + 1; i < w; i++) {
			if (a[x][i] == 0) a[x][i] = '#';
			if (a[x][i] == 6) break;
		}
	}
	else if (direction == LEFT) {
		for (int i = y - 1; i >= 0; i--) {
			if (a[x][i] == 0) a[x][i] = '#';
			if (a[x][i] == 6) break;
		}
	}
	else if (direction == UP) {
		for (int i = x - 1; i >= 0; i--) {
			if (a[i][y] == 0) a[i][y] = '#';
			if (a[i][y] == 6) break;
		}
	}
	else {
		for (int i = x + 1; i < h; i++) {
			if (a[i][y] == 0) a[i][y] = '#';
			if (a[i][y] == 6) break;
		}
	}
}

void solution(int index, vector<vector<int>> a) {
	if (index == camera.size()) {
		int blindSpot = getBlindSpot(a);
		if (blindSpot < result) result = blindSpot;
		return;
	}

	int x, y, type;
	tie(x, y, type) = camera[index];

	if (type == 1) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> result = a;
			mornitoring(x, y, result, i);
			solution(index + 1, result);
		}
	}
	else if (type == 2) {
		for (int i = 0; i <= 1; i++) {
			vector<vector<int>> result = a;
			mornitoring(x, y, result, i);
			mornitoring(x, y, result, i + 2);
			solution(index + 1, result);
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> result = a;
			mornitoring(x, y, result, i);
			mornitoring(x, y, result, (i + 1) % 4);
			solution(index + 1, result);
		}
	}
	else if (type == 4) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> result = a;
			mornitoring(x, y, result, i);
			mornitoring(x, y, result, (i + 1) % 4);
			mornitoring(x, y, result, (i + 2) % 4);
			solution(index + 1, result);
		}
	}
	else {
		mornitoring(x, y, a, UP);
		mornitoring(x, y, a, DOWN);
		mornitoring(x, y, a, LEFT);
		mornitoring(x, y, a, RIGHT);
		solution(index + 1, a);
	}
}

int main() {
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];

			if (a[i][j] != 0 && a[i][j] != 6) {
				camera.push_back(make_tuple(i, j, a[i][j]));
			}
		}
	}
	solution(0, a);
	cout << result << "\n";
	return 0;
}