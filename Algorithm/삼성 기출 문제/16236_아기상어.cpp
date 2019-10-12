#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, sx, sy;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

vector<vector<int>> a;
pair<int, int> shark;

int moveShark() {
	int result = 0;

	while (true) {
		vector<vector<int>> d(n, vector<int>(n, -1));
		queue<pair<int, int>> q;

		d[sx][sy] = 0;
		q.push(make_pair(sx, sy));

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (a[nx][ny] > shark.first) continue;
				if (d[nx][ny] != -1) continue;

				d[nx][ny] = d[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}

		int nearest = -1;
		int nx, ny;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == -1) continue;
				if (a[i][j] == 0 || a[i][j] == 9) continue;
				if (a[i][j] >= shark.first) continue;

				if (nearest == -1 || d[i][j] < nearest) {
					nearest = d[i][j];
					nx = i;
					ny = j;
				}
			}
		}

		if (nearest == -1) {
			break;
		}
		else {
			a[sx][sy] = 0;
			a[nx][ny] = 9;
			sx = nx;
			sy = ny;

			shark.second++;
			if (shark.first == shark.second) {
				shark.first++;
				shark.second = 0;
			}
			result += nearest;
		}
	}
	return result;
}

int main() {
	cin >> n;
	a.assign(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				sx = i;
				sy = j;
				shark = make_pair(2, 0);
			}
		}
	}

	cout << moveShark() << "\n";
	return 0;
}