#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[501];
int d[501][501];
int cost[501];

int getMinFileMerge(int start, int end) {
	int min = -1;
	int temp;

	if (start >= end) return 0;
	if (d[start][end] != 0) return d[start][end];
	if (start + 1 == end) return a[start] + a[end];

	for (int i = start; i <= end - 1; i++) {
		d[start][i] = getMinFileMerge(start, i);
		d[i + 1][end] = getMinFileMerge(i + 1, end);

		temp = d[start][i] + d[i + 1][end] + cost[end] - cost[start - 1];

		if (temp < min || min == -1) {
			min = temp;
		}
	}

	d[start][end] = min;
	return d[start][end];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		memset(d, 0, sizeof(d));
		memset(cost, 0, sizeof(cost));

		for (int j = 1; j <= n; j++) {
			cin >> a[j];
			cost[j] = cost[j - 1] + a[j];
		}

		cout << getMinFileMerge(1, n) << "\n";
	}

	return 0;
}