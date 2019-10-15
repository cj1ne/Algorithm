#include <iostream>
#include <vector>
using namespace std;

int n, l;

bool checkRoad(vector<int> road) {
	vector<bool> slope(n, false);

	for (int i = 0; i < n - 1; i++) {
		if (road[i] == road[i + 1]) {
			continue;
		}
		else if (road[i] - road[i + 1] == -1) {
			for (int k = i; k >= i - l + 1; k--) {
				if (k < 0 || slope[k] == true) {
					return false;
				}
				slope[k] = true;
			}
		}
		else if (road[i] - road[i + 1] == 1) {
			for (int k = i + 1; k <= i + l; k++) {
				if (k >= n || slope[k] == true) {
					return false;
				}
				slope[k] = true;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	int result = 0;
	cin >> n >> l;
	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		vector<int> road(n);
		for (int j = 0; j < n; j++) {
			road[j] = a[j][i];
		}

		if (checkRoad(road)) result++;
		if (checkRoad(a[i])) result++;
	}
	cout << result << "\n";
	return 0;
}