#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, from, to, result = 0;
	cin >> n >> m;

	vector<vector<bool>> d(n + 1, vector<bool>(n + 1, false));

	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		d[from][to] = true;
		d[to][from] = true;
	}

	vector<int> order(n, 0);
	order[n - 1] = 1;
	order[n - 2] = 1;
	order[n - 3] = 1;

	do {
		int a = -1, b = -1, c = -1;

		for (int i = 0; i < n; i++) {
			if (order[i] == 1) {
				if (a == -1) {
					a = i + 1;
				}
				else {
					if (b == -1) {
						b = i + 1;
					}
					else {
						if (c == -1) {
							c = i + 1;
							break;
						}
					}
				}
			}
		}

		if (d[a][b] == false && d[a][c] == false && d[b][c] == false) {
			result++;
		}
	} while (next_permutation(order.begin(), order.end()));

	cout << result << "\n";
	return 0;
}