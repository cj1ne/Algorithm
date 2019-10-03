#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int h, w;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

vector<vector<int>> a;
vector<pair<int, int>> virus;

int spreadVirus() {
	int area = 0;
	vector<vector<bool>> d(h, vector<bool>(w, false));
	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;

		d[x][y] = true;
		q.push(make_pair(x, y));
	}

	while (!q.empty()) {
		int ex = q.front().first;
		int ey = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ex + dx[i];
			int ny = ey + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (a[nx][ny] == 1) continue;
			if (d[nx][ny] == true) continue;

			d[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (d[i][j] == true) continue;
			if (a[i][j] == 0) {
				area++;
			}
		}
	}
	return area;
}

void setMap(int i, int j, int k, int value) {
	a[i / w][i % w] = value;
	a[j / w][j % w] = value;
	a[k / w][k % w] = value;
}

int solution() {
	int result = 0;

	for (int i = 0; i < (h * w) - 2; i++) {
		for (int j = i + 1; j < (h * w) -1; j++) {
			for (int k = j + 1; k < (h * w); k++) {
				if (a[i / w][i % w] != 0 || a[j / w][j % w] != 0 || a[k / w][k % w] != 0) continue;
				setMap(i, j, k, 1);

				int safeArea = spreadVirus();
				if (safeArea > result) {
					result = safeArea;
				}
				setMap(i, j, k, 0);
			}
		}
	}
	return result;
}

int main() {
	cin >> h >> w;
	a.assign(h, vector<int>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];

			if (a[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	
	cout << solution() << "\n";
	return 0;
}