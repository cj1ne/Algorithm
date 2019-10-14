#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int h, w;
int result = -1;
vector<tuple<int, int, int>> cctv;

int get_blind_spot(vector<vector<int>> &a) {
	int count = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}

void monitoring(int x, int y, int direction, vector<vector<int>> &a) {
	if (direction == UP) {
		for (int i = x - 1; i >= 0; i--) {
			if (a[i][y] == 6) return;
			if (a[i][y] == 0) {
				a[i][y] = '9';
			}
		}
	}
	else if (direction == DOWN) {
		for (int i = x + 1; i < h; i++) {
			if (a[i][y] == 6) return;
			if (a[i][y] == 0) {
				a[i][y] = '9';
			}
		}
	}
	else if (direction == RIGHT) {
		for (int j = y + 1; j < w; j++) {
			if (a[x][j] == 6) return;
			if (a[x][j] == 0) {
				a[x][j] = '9';
			}
		}
	}
	else {
		for (int j = y - 1; j >= 0; j--) {
			if (a[x][j] == 6) return;
			if (a[x][j] == 0) {
				a[x][j] = '9';
			}
		}
	}
}

void cctv_monitoring(int index, vector<vector<int>> a) {
	if (index == cctv.size()) {
		int blind_spot = get_blind_spot(a);
		if (result == -1 || blind_spot < result) {
			result = blind_spot;
		}
		return;
	}

	int x, y, type;
	tie(x, y, type) = cctv[index];

	switch (type) {
	case 1:
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> copy = a;
			monitoring(x, y, (RIGHT + i) % 4, copy);
			cctv_monitoring(index + 1, copy);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			vector<vector<int>> copy = a;
			monitoring(x, y, (RIGHT + i) % 4, copy);
			monitoring(x, y, (LEFT + i) % 4, copy);
			cctv_monitoring(index + 1, copy);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> copy = a;
			monitoring(x, y, (UP + i) % 4, copy);
			monitoring(x, y, (RIGHT + i) % 4, copy);
			cctv_monitoring(index + 1, copy);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> copy = a;
			monitoring(x, y, (LEFT + i) % 4, copy);
			monitoring(x, y, (UP + i) % 4, copy);
			monitoring(x, y, (RIGHT + i) % 4, copy);
			cctv_monitoring(index + 1, copy);
		}
		break;
	case 5:
		monitoring(x, y, UP, a);
		monitoring(x, y, DOWN, a);
		monitoring(x, y, LEFT, a);
		monitoring(x, y, RIGHT, a);
		cctv_monitoring(index + 1, a);
		break;
	}
}

int main() {
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];

			if (a[i][j] != 0 && a[i][j] != 6) {
				cctv.push_back(make_tuple(i, j, a[i][j]));
			}
		}
	}
	cctv_monitoring(0, a);
	cout << result << "\n";
	return 0;
}