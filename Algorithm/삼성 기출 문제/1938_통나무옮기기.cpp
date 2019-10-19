#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
const int HORIZON = 0;
const int VERTICAL = 1;
const int UP = 2;
const int RIGHT = 3;
const int DOWN = 4;
const int LEFT = 5;
const int ROTATE = 6;

vector<string> a;
int n;

int dx[8] = { 0, 0, -1, 1, -1, - 1, 1, 1 };
int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };

bool check(int x, int y, int d, int direction) {
	if (direction == RIGHT) {
		if (d == HORIZON) {
			if (y + 2 >= n) return false;
			if (a[x][y + 2] == '1') return false;
		}
		else {
			if (y + 1 >= n) return false;
			if (a[x - 1][y + 1] == '1' || a[x][y + 1] == '1' || a[x + 1][y + 1] == '1') return false;
		}
		return true;
	}
	else if (direction == LEFT) {
		if (d == HORIZON) {
			if (y - 2 < 0) return false;
			if (a[x][y - 2] == '1') return false;
		}
		else {
			if (y - 1 < 0) return false;
			if (a[x - 1][y - 1] == '1' || a[x][y - 1] == '1' || a[x + 1][y - 1] == '1') return false;
		}
		return true;
	}
	else if (direction == UP) {
		if (d == HORIZON) {
			if (x - 1 < 0) return false;
			if (a[x - 1][y - 1] == '1' || a[x - 1][y] == '1' || a[x - 1][y + 1] == '1') return false;
		}
		else {
			if (x - 2 < 0) return false;
			if (a[x - 2][y] == '1') return false;
		}
		return true;
	}
	else if (direction == DOWN) {
		if (d == HORIZON) {
			if (x + 1 >= n) return false;
			if (a[x + 1][y - 1] == '1' || a[x + 1][y] == '1' || a[x + 1][y + 1] == '1') return false;
		}
		else {
			if (x + 2 >= n) return false;
			if (a[x + 2][y] == '1') return false;
		}
		return true;
	}
	else {
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
			if (a[nx][ny] == '1') return false;
		}
		return true;
	}
}

int play(tuple<int, int, int> start, tuple<int, int, int> finish) {
	vector<vector<vector<int>>> d(n, vector<vector<int>>(n, vector<int>(2, -1)));
	queue<tuple<int, int, int>> q;

	d[get<0>(start)][get<1>(start)][get<2>(start)] = 0;
	q.push(start);

	while (!q.empty()) {
		int x, y, shape;
		tie(x, y, shape) = q.front();
		q.pop();

		if (check(x, y, shape, RIGHT)) {
			if (d[x][y + 1][shape] == -1) {
				d[x][y + 1][shape] = d[x][y][shape] + 1;
				q.push(make_tuple(x, y + 1, shape));
			}
		}

		if (check(x, y, shape, LEFT)) {
			if (d[x][y - 1][shape] == -1) {
				d[x][y - 1][shape] = d[x][y][shape] + 1;
				q.push(make_tuple(x, y - 1, shape));
			}
		}

		if (check(x, y, shape, UP)) {
			if (d[x - 1][y][shape] == -1) {
				d[x - 1][y][shape] = d[x][y][shape] + 1;
				q.push(make_tuple(x - 1, y, shape));
			}
		}

		if (check(x, y, shape, DOWN)) {
			if (d[x + 1][y][shape] == -1) {
				d[x + 1][y][shape] = d[x][y][shape] + 1;
				q.push(make_tuple(x + 1, y, shape));
			}
		}
		
		if (check(x, y, shape, ROTATE)) {
			if (d[x][y][(shape + 1) % 2] == -1) {
				d[x][y][(shape + 1) % 2] = d[x][y][shape] + 1;
				q.push(make_tuple(x, y, (shape + 1) % 2));
			}
		}
	}

	if (d[get<0>(finish)][get<1>(finish)][get<2>(finish)] == -1) {
		return 0;
	}
	else {
		return d[get<0>(finish)][get<1>(finish)][get<2>(finish)];
	}
}

int main() {
	tuple<int, int, int> start;
	tuple<int, int, int> finish;

	vector<pair<int, int>> b;
	vector<pair<int, int>> e;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		a.push_back(str);

		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'B') {
				b.push_back(make_pair(i, j));
				a[i][j] = '0';
			}
			else if (a[i][j] == 'E') {
				e.push_back(make_pair(i, j));
				a[i][j] = '0';
			}
		}
	}

	if (b[0].first == b[1].first) {
		start = make_tuple(b[1].first, b[1].second, HORIZON);
	}
	else {
		start = make_tuple(b[1].first, b[1].second, VERTICAL);
	}

	if (e[0].first == e[1].first) {
		finish = make_tuple(e[1].first, e[1].second, HORIZON);
	}
	else {
		finish = make_tuple(e[1].first, e[1].second, VERTICAL);
	}

	cout << play(start, finish) << "\n";
	return 0;
}