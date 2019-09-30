#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> d;

int main() {

	int n, start, max;
	cin >> n >> start >> max;

	d.assign(n + 1, vector<bool>(max + 1, false));
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	d[0][start] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= max; j++) {
			if (d[i][j] == false) continue;
			if (j + v[i] <= max) d[i + 1][j + v[i]] = true;
			if (j - v[i] >= 0) d[i + 1][j - v[i]] = true;
		}
	}

	int result = -1;

	for (int i = 0; i <= max; i++) {
		if (d[n][i] == true) {
			result = i;
		}
	}

	cout << result;

	return 0;
}