#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;

vector<vector<int>> a;
vector<vector<bool>> d;

int h, w;
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

pair<int, int> checkBack(int x, int y, int direction) {
	int nx, ny;

	switch (direction) {
	case NORTH:
		nx = x + 1; ny = y;
		break;
	case SOUTH:
		nx = x - 1; ny = y;
		break;
	case EAST:
		nx = x; ny = y - 1;
		break;
	case WEST:
		nx = x; ny = y + 1;
		break;
	}

	if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
		return make_pair(-1, -1);
	}

	if (a[nx][ny] == 0) {
		return make_pair(nx, ny);
	}
	else {
		return make_pair(-1, -1);
	}
}

tuple<int, int, int> checkLeft(int x, int y, int direction) {
	int nd = (direction + 3) % 4;
	int nx, ny;

	switch (nd) {
	case NORTH:
		nx = x - 1; ny = y;
		break;
	case SOUTH:
		nx = x + 1; ny = y;
		break;
	case EAST:
		nx = x; ny = y + 1;
		break;
	case WEST:
		nx = x; ny = y - 1;
		break;
	}

	if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
		return make_tuple(-1, -1, -1);
	}

	if (d[nx][ny] == false && a[nx][ny] == 0) {
		return make_tuple(nx, ny, nd);
	}
	else {
		return make_tuple(-1, -1, -1);
	}
}

int getArea() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (d[i][j] == true) cnt++;
		}
	}
	return cnt;
}

int bfs(int startX, int startY, int direction) {

	int result = 0;

	d.assign(h, vector<bool>(w, false));
	d[startX][startY] = true;

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(startX, startY, direction));

	while (!q.empty()) {
		int ex, ey, ed;
		int nx, ny, nd;

		tie(ex, ey, ed) = q.front();
		q.pop();

		while (true) {
			for (int i = 0; i < 4; i++) {
				tie(nx, ny, nd) = checkLeft(ex, ey, (ed - i + 4) % 4);

				if (nd != -1) {
					d[nx][ny] = true;
					q.push(make_tuple(nx, ny, nd));
					break;
				}
			}

			if (nd != -1) break;

			pair<int, int> now = checkBack(ex, ey, ed);
			if (now.first == -1 || now.second == -1) {
				return getArea();
			}
			else {
				ex = now.first;
				ey = now.second;
			}
		}
	}

	return result;
}

int main() {
	int startX, startY, direction;

	cin >> h >> w;
	cin >> startX >> startY >> direction;

	a.assign(h, vector<int>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	cout << bfs(startX, startY, direction) << "\n";

	return 0;
}