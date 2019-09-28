#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> w(n + 1, 0);
	vector<int> v(n + 1);
	vector<vector<int>> d(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			d[i][j] = d[i - 1][j];

			if (j - w[i] >= 0) {
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << d[n][k] << "\n";

	return 0;
}