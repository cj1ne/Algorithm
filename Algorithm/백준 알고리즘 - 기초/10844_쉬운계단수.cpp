#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, result = 0;
	cin >> n;

	vector<vector<int>> d(n + 1, vector<int>(10, 0));

	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				d[i][j] = (d[i][j] + d[i - 1][j - 1]) % 1000000000;
			}

			if (j + 1 < 10) {
				d[i][j] = (d[i][j] + d[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		result = (result + d[n][i]) % 1000000000;
	}

	cout << result << "\n";

	return 0;
}