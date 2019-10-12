#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> a;
vector<pair<int, int>> cleaner;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int h, w;

void cleanUp() {
	int x = cleaner[0].first;

	for (int i = x - 1; i >= 1; i--) {
		a[i][0] = a[i - 1][0];
	}

	for (int j = 0; j < w - 1; j++) {
		a[0][j] = a[0][j + 1];
	}

	for (int i = 0; i < x; i++) {
		a[i][w - 1] = a[i + 1][w - 1];
	}

	for (int j = w - 1; j > 1; j--) {
		a[x][j] = a[x][j - 1];
	}
	a[x][1] = 0;
}

void cleanDown() {
	int x = cleaner[1].first;

	for (int i = x + 1; i < h - 1; i++) {
		a[i][0] = a[i + 1][0];
	}

	for (int j = 0; j < w - 1; j++) {
		a[h - 1][j] = a[h - 1][j + 1];
	}

	for (int i = h - 1; i > x; i--) {
		a[i][w - 1] = a[i - 1][w - 1];
	}

	for (int j = w - 1; j > 1; j--) {
		a[x][j] = a[x][j - 1];
	}
	a[x][1] = 0;
}

void spreadDust() {
	queue<pair<int, int>> q;
	vector<vector<int>> d(h, vector<int>(w, 0));
	vector<vector<int>> spread(h, vector<int>(w, 0));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0 || a[i][j] == -1) continue;
			q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int cntSpread = 0;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (a[nx][ny] == -1) continue;

			d[nx][ny] += a[x][y] / 5;
			cntSpread++;
		}
		spread[x][y] = cntSpread;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			a[i][j] = a[i][j] - ((a[i][j] / 5) * spread[i][j]) + d[i][j];
		}
	}
}

int getDust() {
	int result = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0 || a[i][j] == -1) continue;
			result += a[i][j];
		}
	}
	return result;
}

int main() {
	int t;
	cin >> h >> w >> t;
	
	a.assign(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) cleaner.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < t; i++) {
		spreadDust();
		cleanUp();
		cleanDown();
	}

	cout << getDust() << "\n";
	return 0;
}