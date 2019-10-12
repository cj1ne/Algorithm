#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, l, r;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

vector<vector<int>> a;

void print(vector<vector<int>> d) {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}


int bfs(int x, int y, int num, vector<vector<int>> &d) {
	int cnt = 1;
	queue<pair<int, int>> q;
	d[x][y] = num;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (d[nx][ny] != -1) continue;

			int diff = a[nx][ny] - a[x][y];
			if (diff < 0) diff = -diff;

			if (diff >= l && diff <= r) {
				d[nx][ny] = num;
				q.push(make_pair(nx, ny));
				cnt++;
			}
		}
	}

	return cnt;
}

bool checkMove() {
	vector<pair<int, int>> merged;
	vector<vector<int>> d(n, vector<int>(n, -1));
	int num = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == -1) {
				int result = bfs(i, j, num, d);
				if (result > 1) {
					merged.push_back(make_pair(num, result));
				}
				num++;
			}
		}
	}

	if (merged.size() > 0) {
		for (int k = 0; k < merged.size(); k++) {
			int num = merged[k].first;
			int cnt = merged[k].second;
			
			int sum = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][j] == num) {
						sum += a[i][j];
					}
				}
			}

			int value = sum / cnt;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][j] == num) {
						a[i][j] = value;
					}
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int result = 0;
	cin >> n >> l >> r;
	a.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (checkMove()) {
		result++;
	}

	cout << result << "\n";
	return 0;
}