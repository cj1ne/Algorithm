#include <iostream>
#include <vector>
using namespace std;

vector<int> a[2000];
bool isExist = false;

void dfs(int now, int cnt, vector<bool> d) {
	if (cnt == 5) {
		isExist = true;
		return;
	}

	if (isExist == false) {
		d[now] = true;

		for (int i = 0; i < a[now].size(); i++) {
			int next = a[now][i];

			if (isExist) break;
			if (d[next] == true) continue;
			dfs(next, cnt + 1, d);
		}
	}
}

int main() {
	int n, m, from, to;
	cin >> n >> m;

	vector<bool> d(n, false);
	
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	for (int i = 0; i < n; i++) {
		if (isExist == false) {
			dfs(i, 1, d);
		}
		else break;
	}

	cout << isExist << "\n";

	return 0;
}