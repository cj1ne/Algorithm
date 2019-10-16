#include <iostream>
#include <vector>
using namespace std;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int h, w;
vector<vector<int>> a;
vector<vector<bool>> d;

bool move_left(int &x, int &y, int direction) {
	int move_x = x, move_y = y;

	switch (direction) {
	case UP:
		move_y--;
		break;
	case DOWN:
		move_y++;
		break;
	case LEFT:
		move_x++;
		break;
	case RIGHT:
		move_x--;
		break;
	}

	if (move_x < 0 || move_x >= h || move_y < 0 || move_y >= w) return false;
	if (a[move_x][move_y] == 1 || d[move_x][move_y] == true) return false;

	x = move_x;
	y = move_y;
	return true;
}

bool move_back(int &x, int &y, int direction) {
	int move_x = x, move_y = y;
	switch (direction) {
		case UP:
			move_x++;
			break;
		case DOWN:
			move_x--;
			break;
		case LEFT:
			move_y++;
			break;
		case RIGHT:
			move_y--;
			break;
	}

	if (move_x < 0 || move_x >= h || move_y < 0 || move_y >= w) return false;
	if (a[move_x][move_y] == 1) return false;

	x = move_x;
	y = move_y;
	return true;
}

int main() {
	int x, y, direction;
	int result = 0;

	cin >> h >> w;
	cin >> x >> y >> direction;
	a.assign(h, vector<int>(w));
	d.assign(h, vector<bool>(w, false));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	d[x][y] = true;
	result++;

	while (true) {
		bool check = false;

		for (int i = 0; i < 4; i++) {
			if (move_left(x, y, direction)) {
				direction = (direction + 3) % 4;
				d[x][y] = true;
				result++;
				check = true;
				break;
			}
			else {
				direction = (direction + 3) % 4;
			}
		}

		if (check == false) {
			if (move_back(x, y, direction) == false) break;
		}
	}

	cout << result << "\n";
	return 0;
}