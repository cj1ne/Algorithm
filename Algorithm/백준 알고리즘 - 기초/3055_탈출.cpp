#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	vector<pair<int, int>> water;
	vector<string> a;
	int sx, sy, fx, fy;
	int h, w;

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		a.push_back(str);

		for (int j = 0; j < w; j++) {
			if (str[j] == 'D') {
				fx = i;
				fy = j;
			}
			else if (str[j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (str[j] == '*') {
				water.push_back(make_pair(i, j));
			}
		}
	}

	vector<vector<int>> dist(h, vector<int>(w, -1));
	vector<vector<int>> water_dist(h, vector<int>(w, -1));
	queue<pair<int, int>>q;

	for (int i = 0; i < water.size(); i++) {
		int x = water[i].first;
		int y = water[i].second;

		water_dist[x][y] = 0;
		q.push(make_pair(x, y));
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (a[nx][ny] == 'D' || a[nx][ny] =='X') continue;
			if (water_dist[nx][ny] != -1) continue;

			water_dist[nx][ny] = water_dist[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	dist[sx][sy] = 0;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (a[nx][ny] == 'X') continue;
			if (water_dist[nx][ny] != -1 && dist[x][y] + 1 >= water_dist[nx][ny]) continue;
			if (dist[nx][ny] != -1) continue;

			dist[nx][ny] = dist[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	if (dist[fx][fy] == -1) {
		cout << "KAKTUS\n";
	}
	else {
		cout << dist[fx][fy] << "\n";
	}
	return 0;
}