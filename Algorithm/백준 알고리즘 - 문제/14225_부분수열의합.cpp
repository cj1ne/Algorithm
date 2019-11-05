#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool d[2000001];

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[a[i]] = true;
	}

	for (int i = 2; i <= n; i++) {
		vector<int> order(n, 0);
		for (int j = 1; j <= i; j++) {
			order[n - j] = 1;
		}

		do {
			int sum = 0;

			for (int k = 0; k < n; k++) {
				if (order[k] == 1) {
					sum += a[k];
				}
			}

			d[sum] = true;
		} while (next_permutation(order.begin(), order.end()));
	}

	for (int i = 1; i < 2000001; i++) {
		if (d[i] == false) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}