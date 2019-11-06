#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int h, w;
int sheep_result = 0;
int wolf_result = 0;

vector<string> a;
vector<vector<bool>> d;

void bfs(int x, int y) {
	int cnt_sheep = 0;
	int cnt_wolf = 0;
	queue<pair<int, int>> q;

	d[x][y] = true;
	q.push(make_pair(x, y));

	if (a[x][y] == 'o') {
		cnt_sheep++;
	}
	else if (a[x][y] == 'v') {
		cnt_wolf++;
	}

	while (!q.empty()) {
		int ex = q.front().first;
		int ey = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ex + dx[i];
			int ny = ey + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (a[nx][ny] == '#') continue;
			if (d[nx][ny] != false) continue;

			if (a[nx][ny] == 'o') cnt_sheep++;
			else if (a[nx][ny] == 'v') cnt_wolf++;

			d[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}

	if (cnt_sheep > cnt_wolf) {
		sheep_result += cnt_sheep;
	}
	else {
		wolf_result += cnt_wolf;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	d.assign(h, vector<bool>(w, false));

	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		a.push_back(str);
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] != '#' && d[i][j] == false) {
				bfs(i, j);
			}
		}
	}
	cout << sheep_result << " " << wolf_result << "\n";
	return 0;
}