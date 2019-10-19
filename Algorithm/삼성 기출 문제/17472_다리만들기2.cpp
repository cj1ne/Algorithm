#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <utility>
using namespace std;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int h, w;
int cnt_vertex;
int cnt_edge;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> a;
vector<vector<int>> d;
vector<tuple<int, int, int>> edge_list;

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
			if (a[nx][ny] == 1 && d[nx][ny] == -1) {
				d[nx][ny] = num;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

pair<int, int> get_edge(int x, int y, int direction) {
	int length = 0;
	int end_point = -1;

	if (direction == RIGHT) {
		for (int j = y + 1; j < w; j++) {
			if (a[x][j] == 1) {
				end_point = d[x][j];
				break;
			}
			else {
				length++;
			}
		}
	}
	else if (direction == LEFT) {
		for (int j = y - 1; j >= 0; j--) {
			if (a[x][j] == 1) {
				end_point = d[x][j];
				break;
			}
			else {
				length++;
			}
		}
	}
	else if (direction == UP) {
		for (int i = x - 1; i >= 0; i--) {
			if (a[i][y] == 1) {
				end_point = d[i][y];
				break;
			}
			else {
				length++;
			}
		}
	}
	else {
		for (int i = x + 1; i < h; i++) {
			if (a[i][y] == 1) {
				end_point = d[i][y];
				break;
			}
			else {
				length++;
			}
		}
	}
	return make_pair(length, end_point);
}

vector<tuple<int, int, int>> get_edge_list(vector<vector<int>> edge) {
	vector<tuple<int, int, int>> list;
	int size = edge.size();

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (edge[i][j] == 0) continue;
			list.push_back(make_tuple(i, j, edge[i][j]));
		}
	}
	return list;
}

int get_min(vector<int> order) {
	int sum = 0;
	vector<vector<int>> e(cnt_vertex, vector<int>(cnt_vertex, 0));
	vector<bool> d(cnt_vertex, false);

	for (int i = 0; i < cnt_edge; i++) {
		if (order[i] == 0) {
			int from, to, size;
			tie(from, to, size) = edge_list[i];

			e[from][to] = size;
			e[to][from] = size;

			sum += size;
		}
	}

	d[0] = true;
	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < cnt_vertex; i++) {
			if (e[now][i] == 0) continue;
			if (d[i] == true) continue;

			d[i] = true;
			q.push(i);
		}
	}

	for (int i = 0; i < cnt_vertex; i++) {
		if (d[i] == false) return -1;
	}
	return sum;
}

int main() {
	cnt_vertex = 0;
	cin >> h >> w;
	a.assign(h, vector<int>(w));
	d.assign(h, vector<int>(w, -1));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 1 && d[i][j] == -1) {
				bfs(i, j, cnt_vertex);
				cnt_vertex++;
			}
		}
	}

	vector<vector<int>> edge(cnt_vertex, vector<int>(cnt_vertex, 0));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (d[i][j] == -1) continue;
			
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (a[nx][ny] == 1) continue;

				pair<int, int> result = get_edge(i, j, k);
				if (result.first < 2 || result.second == -1) continue;

				int from = d[i][j];
				int to = result.second;

				if (edge[from][to] == 0 || result.first < edge[from][to]) {
					edge[from][to] = result.first;
					edge[to][from] = result.first;
				}
			}
		}
	}

	edge_list = get_edge_list(edge);
	cnt_edge = edge_list.size();

	if (cnt_edge < cnt_vertex - 1) {
		cout << -1 << "\n";
	}
	else {	
		int minResult = -1;
		for (int i = cnt_vertex - 1; i <= cnt_edge; i++) {
			vector<int> order(cnt_edge, 0);

			for (int j = i; j < cnt_edge; j++) {
				order[j] = 1;
			}

			do {
				int result = get_min(order);
				if (result != -1 && (minResult == -1 || result < minResult)) {
					minResult = result;
				}
			} while (next_permutation(order.begin(), order.end()));
		}
		cout << minResult << "\n";
	}
	return 0;
}