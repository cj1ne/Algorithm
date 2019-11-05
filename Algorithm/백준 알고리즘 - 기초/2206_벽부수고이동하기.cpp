#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int h, w, result;
vector<vector<bool>> a;

void bfs() {
	vector<vector<vector<int>>> d(h, vector<vector<int>>(w, vector<int>(2, -1)));
	queue<tuple<int, int, int>> q;

	d[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z;

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (a[nx][ny] == true) {
				if (nz == 0) {
					nz += 1;
				}
				else {
					continue;
				}
			}
			if (d[nx][ny][nz] != -1) continue;

			d[nx][ny][nz] = d[x][y][z] + 1;
			q.push(make_tuple(nx, ny, nz));
		}
	}

	if (d[h - 1][w - 1][0] == -1 && d[h - 1][w - 1][1] == -1) {
		result = -1;
	}
	else if (d[h - 1][w - 1][0] != -1 && d[h - 1][w - 1][1] == -1) {
		result = d[h - 1][w - 1][0];
	}
	else if (d[h - 1][w - 1][0] == -1 && d[h - 1][w - 1][1] != -1) {
		result = d[h - 1][w - 1][1];
	}
	else {
		if (d[h - 1][w - 1][0] < d[h - 1][w - 1][1]) {
			result = d[h - 1][w - 1][0];
		}
		else {
			result = d[h - 1][w - 1][1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	cin >> h >> w;
	a.assign(h, vector<bool>(w));

	for (int i = 0; i < h; i++) {
		cin >> str;
		for (int j = 0; j < w; j++) {
			if (str[j] == '0') {
				a[i][j] = false;
			}
			else {
				a[i][j] = true;
			}
		}
	}

	bfs();
	cout << result << "\n";
	return 0;
}