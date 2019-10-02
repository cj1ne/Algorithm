#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

const int LEFT = 0;
const int RIGHT = 1;

int h, w, n;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

vector<vector<int>> d;
vector<string> a;

void printCave() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}

void bfs(int x, int y, int num) {
	d[x][y] = num;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int ex = q.front().first;
		int ey = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ex + dx[i];
			int ny = ey + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (d[nx][ny] != 0) continue;
			if (a[nx][ny] == '.') continue;

			q.push(make_pair(nx, ny));
			d[nx][ny] = num;
		}
	}
}

void init() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			d[i][j] = 0;
		}
	}

	int num = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (d[i][j] == 0 && a[i][j] == 'x') {
				bfs(i, j, num);
				num++;
			}
		}
	}
}

bool isCluster(int x, int y) {
	init();
	int num = -1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if (a[nx][ny] == '.') continue;

		if (num == -1) num = d[nx][ny];
		else {
			if (d[nx][ny] != num) return false;
		}
	}
	return true;
}

void moveColumn(int x, int y, int gap, int num) {
	for (int i = x; i >= 0; i--) {
		if (d[i][y] == num) {
			a[i + gap][y] = a[i][y];
			a[i][y] = '.';
		}
	}
}

void dropCluster(int num) {
	int min = 100;

	for (int j = 0; j < w; j++) {
		int base = h;
		for (int i = h - 1; i >= 0; i--) {
			if (d[i][j] == num) {
				if (base - i - 1 < min) {
					min = base - i - 1;
				}
			}

			if (a[i][j] == 'x' && d[i][j] != num) base = i;
		}
	}

	if (min > 0) {
		for (int j = 0; j < w; j++) {
			for (int i = h - 1; i >= 0; i--) {
				if (d[i][j] == num) {
					moveColumn(i, j, min, num);
					break;
				}
			}
		}
	}
}

void breakMineral(int x, int y) {
	a[x][y] = '.';

	if (!isCluster(x, y)) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (a[nx][ny] == '.') continue;

			dropCluster(d[nx][ny]);
		}
	}
}

void throwing(int height, int direction) {
	if (direction == LEFT) {
		for (int i = 0; i < w; i++) {
			if (a[height][i] != 'x') continue;

			breakMineral(height, i);
			return;
		}
	}
	else {
		for (int i = w - 1; i >= 0; i--) {
			if (a[height][i] != 'x') continue;

			breakMineral(height, i);
			return;
		}
	}
}

int main() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		a.push_back(str);
	}

	d.assign(h, vector<int>(w));
	init();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		throwing(h - height, i % 2);
	}
	printCave();

	return 0;
}