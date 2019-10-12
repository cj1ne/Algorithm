#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<vector<int>> a;
vector<vector<int>> nutriment;
deque<int> tree[11][11];
deque<int> dead_tree[11][11];

int n;
int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };

void spring() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int size = tree[i][j].size();
			if (size == 0) continue;

			sort(tree[i][j].begin(), tree[i][j].end());

			for (int k = 0; k < size; k++) {
				int age = tree[i][j].front();
				tree[i][j].pop_front();

				if (age > a[i][j]) {
					dead_tree[i][j].push_back(age);
				} else {
					a[i][j] -= age;
					age++;
					tree[i][j].push_back(age);
				}
			}
		}
	}
}

void summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int size = dead_tree[i][j].size();
			if (size == 0) continue;

			for (int k = 0; k < size; k++) {
				a[i][j] += dead_tree[i][j].front() / 2;
				dead_tree[i][j].pop_front();
			}
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int size = tree[i][j].size();
			if (size == 0) continue;

			for (int k = 0; k < size; k++) {
				if (tree[i][j][k] % 5 != 0) continue;
				
				for (int l = 0; l < 8; l++) {
					int nx = i + dx[l];
					int ny = j + dy[l];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					tree[nx][ny].push_back(1);
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] += nutriment[i][j];
		}
	}
}

int get_tree_count() {
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			count += tree[i][j].size();
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, k;
	cin >> n >> m >> k;
	a.assign(n, vector<int>(n, 5));
	nutriment.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nutriment[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		tree[x - 1][y - 1].push_back(age);
	}

	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << get_tree_count() << "\n";
	return 0;
}