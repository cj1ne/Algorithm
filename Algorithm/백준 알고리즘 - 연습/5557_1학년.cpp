#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<vector<long long>> d(n - 1, vector <long long>(21, 0));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d[0][a[0]] = 1;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			if (d[i][j] == 0) continue;

			if (j + a[i + 1] <= 20) {
				d[i + 1][j + a[i + 1]] += d[i][j];
			}

			if (j - a[i + 1] >= 0) {
				d[i + 1][j - a[i + 1]] += d[i][j];
			}
		}
	}

	cout << d[n - 2][a[n - 1]] << "\n";


	return 0;
}