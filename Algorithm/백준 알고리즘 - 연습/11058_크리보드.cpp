#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;

	vector<long long> d(n + 1, 0);

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		long max = d[i - 1] + 1;

		int j = 0;
		while ((i - 3) - j > 0) {
			if ((d[(i - 3) - j] * (j + 2)) > max) {
				max = d[(i - 3) - j] * (j + 2);
			}
			j++;
		}

		d[i] = max;
	}

	cout << d[n] << "\n";

	return 0;
}