#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	vector<int> d(k + 1, 0);
	d[0] = 1;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 1; j <= k; j++) {
			if (j - a[i] >= 0) {
				d[j] += d[j - a[i]];
			}
		}
	}

	cout << d[k] << "\n";

	return 0;
}