#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> a;
vector<pair<int, int>> virus;
vector<int> order;

int result = -1;
int n, m;
int dx[4] = { 0 ,0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int getTime(vector<vector<int>> &d) {
	int time = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 || a[i][j] == 2) continue;
			if (d[i][j] == -1) return -1;

			if (d[i][j] > time) {
				time = d[i][j];
			}
		}
	}
	return time;
}

void spreadVirus() {
	vector<vector<int>> d(n, vector<int>(n, -1));
	queue<pair<int, int>> q;

	for (int i = 0; i < order.size(); i++) {
		if (order[i] == 1) {
			d[virus[i].first][virus[i].second] = 0;
			q.push(virus[i]);
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (a[nx][ny] == 1) continue;
			if (d[nx][ny] != -1) continue;

			d[nx][ny] = d[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	int time = getTime(d);
	if (time != -1 && (result == -1 || time < result)) {
		result = time;
	}
}

int main() {
	cin >> n >> m;
	a.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	int size = virus.size();
	order.assign(size, 0);
	for (int i = 1; i <= m; i++) {
		order[size - i] = 1;
	}

	do {
		spreadVirus();
	} while (next_permutation(order.begin(), order.end()));

	cout << result << "\n";
}