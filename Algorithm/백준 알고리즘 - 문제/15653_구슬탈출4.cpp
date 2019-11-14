#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <tuple>
#include <cstring>
using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int h, w;
vector<string> a;

bool isExit(int x, int y, int direction) {
	if (direction == UP) {
		for (int i = x - 1; i >= 0; i--) {
			if (a[i][y] == '#') {
				return false;
			}
			else if (a[i][y] == 'O') {
				return true;
			}
		}
	}
	else if (direction == DOWN) {
		for (int i = x + 1; i < h; i++) {
			if (a[i][y] == '#') {
				return false;
			}
			else if (a[i][y] == 'O') {
				return true;
			}
		}
	}
	else if (direction == LEFT) {
		for (int j = y - 1 ; j >= 0; j--) {
			if (a[x][j] == '#') {
				return false;
			}
			else if (a[x][j] == 'O') {
				return true;
			}
		}
	}
	else {
		for (int j = y + 1; j < w; j++) {
			if (a[x][j] == '#') {
				return false;
			}
			else if (a[x][j] == 'O') {
				return true;
			}
		}
	}
}

 pair<pair<int, int>, pair<int, int>> move(int bx, int by, int rx, int ry, int direction) {
	 if (direction == RIGHT) {
		 if (bx == rx) {
			 if (by > ry) {
				 for (int j = by + 1; j < w; j++) {
					 if (a[bx][j] == '#') break;
					 by = j;
				 }

				 for (int j = ry + 1; j < by; j++) {
					 if (a[rx][j] == '#') break;
					 ry = j;
				 }
			 }
			 else {
				 for (int j = ry + 1; j < w; j++) {
					 if (a[rx][j] == '#') break;
					 ry = j;
				 }

				 for (int j = by + 1; j < ry; j++) {
					 if (a[bx][j] == '#') break;
					 by = j;
				 }
			 }
		 }
		 else {
			 for (int j = by + 1; j < w; j++) {
				 if (a[bx][j] == '#') break;
				 by = j;
			 }

			 for (int j = ry + 1; j < w; j++) {
				 if (a[rx][j] == '#') break;
				 ry = j;
			 }
		 }
	 }
	 else if (direction == LEFT) {
		 if (bx == rx) {
			 if (ry < by) {
				 for (int j = ry - 1; j >= 0; j--) {
					 if (a[rx][j] == '#') break;
					 ry = j;
				 }

				 for (int j = by - 1; j > ry; j--) {
					 if (a[bx][j] == '#') break;
					 by = j;
				 }
			 }
			 else {
				 for (int j = by - 1; j >= 0; j--) {
					 if (a[bx][j] == '#') break;
					 by = j;
				 }

				 for (int j = ry - 1; j > by; j--) {
					 if (a[rx][j] == '#') break;
					 ry = j;
				 }
			 }
		 }
		 else {
			 for (int j = by - 1; j >= 0; j--) {
				 if (a[bx][j] == '#') break;
				 by = j;
			 }

			 for (int j = ry - 1; j >= 0; j--) {
				 if (a[rx][j] == '#') break;
				 ry = j;
			 }
		 }
	 }
	 else if (direction == UP) {
		 if (by == ry) {
			 if (rx < bx) {
				 for (int i = rx - 1; i >= 0; i--) {
					 if (a[i][ry] == '#') break;
					 rx = i;
				 }

				 for (int i = bx - 1; i > rx; i--) {
					 if (a[i][by] == '#') break;
					 bx = i;
				 }
			 }
			 else {
				 for (int i = bx - 1; i >= 0; i--) {
					 if (a[i][by] == '#') break;
					 bx = i;
				 }

				 for (int i = rx - 1; i > bx; i--) {
					 if (a[i][ry] == '#') break;
					 rx = i;
				 }
			 }
		 }
		 else {
			 for (int i = bx - 1; i >= 0; i--) {
				 if (a[i][by] == '#') break;
				 bx = i;
			 }

			 for (int i = rx - 1; i >= 0; i--) {
				 if (a[i][ry] == '#') break;
				 rx = i;
			 }
		 }
	 }
	 else {
		 if (by == ry) {
			 if (rx < bx) {
				 for (int i = bx + 1; i < h; i++) {
					 if (a[i][by] == '#') break;
					 bx = i;
				 }

				 for (int i = rx + 1; i < bx; i++) {
					 if (a[i][ry] == '#') break;
					 rx = i;
				 }
			 }
			 else {
				 for (int i = rx + 1; i < h; i++) {
					 if (a[i][ry] == '#') break;
					 rx = i;
				 }

				 for (int i = bx + 1; i < rx; i++) {
					 if (a[i][by] == '#') break;
					 bx = i;
				 }
			 }
		 }
		 else {
			 for (int i = bx + 1; i < h; i++) {
				 if (a[i][by] == '#') break;
				 bx = i;
			 }

			 for (int i = rx + 1; i < h; i++) {
				 if (a[i][ry] == '#') break;
				 rx = i;
			 }
		 }
	 }
	 return make_pair(make_pair(bx, by), make_pair(rx, ry));
}

void bfs(pair<int, int> blue, pair<int, int> red) {
	int d[10][10][10][10];
	memset(d, -1, sizeof(d));

	queue<tuple<pair<int, int>, pair<int, int>, int>> q;

	d[blue.first][blue.second][red.first][red.second] = 0;
	q.push(make_tuple(make_pair(blue.first, blue.second), make_pair(red.first, red.second), 0));

	while (!q.empty()) {
		pair<int, int> b, r;
		int time;

		tie(b, r, time) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			bool blue_exit = isExit(b.first, b.second, i);
			bool red_exit = isExit(r.first, r.second, i);

			if (blue_exit || red_exit) {
				if (!blue_exit && red_exit) {
					cout << time + 1 << "\n";
					return;
				}
			}
			else {
				pair<pair<int, int>, pair<int, int>> result = move(b.first, b.second, r.first, r.second, i);

				if (d[result.first.first][result.first.second][result.second.first][result.second.second] == -1) {
					d[result.first.first][result.first.second][result.second.first][result.second.second] = time + 1;
					q.push(make_tuple(result.first, result.second, time + 1));
				}
			}
		}
	}
	cout << "-1\n";
}

int main() {
	pair<int, int> blue, red;

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		a.push_back(str);

		for (int j = 0; j < w; j++) {
			if (str[j] == 'B') {
				blue = make_pair(i, j);
			}
			else if (str[j] == 'R') {
				red = make_pair(i, j);
			}
		}
	}

	bfs(blue, red);
	return 0;
}