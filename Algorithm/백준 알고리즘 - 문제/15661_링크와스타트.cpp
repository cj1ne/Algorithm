#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> a;

int getDiff(vector<int> selected) {
	int diff;
	int sumZero = 0;
	int sumOne = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (selected[i] != selected[j]) continue;
			if (selected[i] == 1) {
				sumOne += a[i][j];
			}
			else {
				sumZero += a[i][j];
			}
		}
	}

	diff = sumOne - sumZero;
	if (diff < 0) diff = -diff;

	return diff;
}

int main() {
	int result = -1;
	vector<int> selected;
	cin >> n;

	a.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i < n / 2) {
			selected.push_back(0);
		}
		else {
			selected.push_back(1);
		}
	}

	do {
		int diff = getDiff(selected);

		if (result == -1 || diff < result) {
			result = diff;
		}
	} while (next_permutation(selected.begin(), selected.end()));
	
	cout << result << "\n";
	return 0;
}