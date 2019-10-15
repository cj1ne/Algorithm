#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;
const int NONE = -1;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

typedef struct Line {
	int x1;
	int x2;
	int y1;
	int y2;
}line;

vector<line> lines;
int hx, hy, hd, l;

int get_dead_time(int nx, int ny) {
	int result = NONE;

	for (int i = 0; i < lines.size(); i++) {
		if ((hx <= lines[i].x1 && nx < lines[i].x1) || (hx >= lines[i].x2 && nx > lines[i].x2)
			|| (hy <= lines[i].y1 && ny < lines[i].y1) || (hy >= lines[i].y2 && ny > lines[i].y2)) continue;
		else {
			int time;
			if (hd == RIGHT) {
				time = lines[i].y1 - hy;
			}
			else if (hd == LEFT) {
				time = hy - lines[i].y2;
			}
			else if (hd == UP) {
				time = hx - lines[i].x2;
			}
			else {
				time = lines[i].x1 - hx;
			}

			if (result == NONE || time < result) {
				result = time;
			}
		}
	}
	return result;
}

void set_new_point(int &nx, int &ny, int time, bool isEmpty) {
	switch (hd) {
		case RIGHT:
			nx = hx;
			if (isEmpty) ny = (2 * l) + 1;
			else  ny = hy + time;
			break;
		case LEFT:
			nx = hx;
			if (isEmpty) ny = -1;
			else ny = hy - time;
			break;
		case UP:
			if (isEmpty) nx = -1;
			else nx = hx - time;
			ny = hy;
			break;
		case DOWN:
			if (isEmpty) nx = (2 * l) + 1;
			else nx = hx + time;
			ny = hy;
			break;
	}
}

void rotate_direction(char rotate, int &nd) {
	if (rotate == 'L') {
		nd = (hd + 3) % 4;
	}
	else {
		nd = (hd + 1) % 4;
	}
}

void add_line(int nx, int ny) {
	int x1, x2, y1, y2;
	
	if (nx > hx) {
		x1 = hx; x2 = nx;
	}
	else {
		x1 = nx; x2 = hx;
	}

	if (ny > hy) {
		y1 = hy; y2 = ny;
	}
	else {
		y1 = ny; y2 = hy;
	}

	line l = { x1, x2, y1, y2 };
	lines.push_back(l);
}

int main() {
	queue<pair<int, char>> t;
	long long result = 0;
	char rotate;
	int n, time = 0;

	cin >> l >> n;
	hx = l, hy = l, hd = RIGHT;

	for (int i = 0; i < n; i++) {
		cin >> time >> rotate;
		t.push(make_pair(time, rotate));
	}

	while (true) {
		int nx, ny, nd;

		if (t.empty()) {
			set_new_point(nx, ny, time, true);
		}
		else {
			time = t.front().first;
			rotate = t.front().second;
			t.pop();

			rotate_direction(rotate, nd);
			set_new_point(nx, ny, time, false);
		}

		int dead = get_dead_time(nx, ny);
		if (dead == NONE) {
			if (nx < 0) {
				result += hx + 1;
				break;
			}
			else if (nx >= (2 * l) + 1) {
				result += (2 * l) - hx + 1;
				break;
			}
			else if (ny < 0) {
				result += hy + 1;
				break;
			}
			else if (ny >= (2 * l) + 1) {
				result += (2 * l) - hy + 1;
				break;
			}
			else {
				add_line(nx, ny);
				hx = nx; hy = ny; hd = nd;
				result += time;
			}
		}
		else {
			result += dead;
			break;
		}
	}

	cout << result << "\n";
	return 0;
}