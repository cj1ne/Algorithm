#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100][100];
int w = 3, h = 3;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return false;
	}
}

void sortR() {
	for (int i = 0; i < h; i++) {
		int cntNum[101];
		vector<pair<int, int>> numSet;
		memset(cntNum, 0, sizeof(cntNum));

		for (int j = 0; j < w; j++) {
			if (a[i][j] != 0) {
				cntNum[a[i][j]] += 1;
			}
		}

		for (int j = 1; j <= 100; j++) {
			if (cntNum[j] != 0) {
				numSet.push_back(make_pair(j, cntNum[j]));
			}
		}

		if ((numSet.size() * 2) > w) {
			w = numSet.size() * 2;
		}

		sort(numSet.begin(), numSet.end(), compare);

		for (int j = 0; j < numSet.size(); j++) {
			a[i][j * 2] = numSet[j].first;
			a[i][(j * 2) + 1] = numSet[j].second;
		}

		for (int j = 2 * numSet.size(); j < w; j++) {
			a[i][j] = 0;
		}
	}
}

void sortC() {
	for (int i = 0; i < w; i++) {
		int cntNum[101];
		vector<pair<int, int>> numSet;
		memset(cntNum, 0, sizeof(cntNum));

		for (int j = 0; j < h; j++) {
			if (a[j][i] != 0) {
				cntNum[a[j][i]] += 1;
			}
		}

		for (int j = 1; j <= 100; j++) {
			if (cntNum[j] != 0) {
				numSet.push_back(make_pair(j, cntNum[j]));
			}
		}

		sort(numSet.begin(), numSet.end(), compare);

		if ((numSet.size() * 2) > h) {
			h = numSet.size() * 2;
		}

		for (int j = 0; j < numSet.size(); j++) {
			a[j * 2][i] = numSet[j].first;
			a[(j * 2) + 1][i] = numSet[j].second;
		}

		for (int j = 2 * numSet.size(); j < h; j++) {
			a[j][i] = 0;
		}
	}
}

int main() {
	int r, c, k, sec = 0;
	cin >> r >> c >> k;

	memset(a, 0, sizeof(a));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) { 
			cin >> a[i][j];
		}
	}

	while (a[r - 1][c - 1] != k) {
		if (h >= w) {
			sortR();
		}
		else {
			sortC();
		}
		sec++;

		if (sec > 100) {
			sec = -1;
			break;
		}
	}

	cout << sec << "\n";
	return 0;
}