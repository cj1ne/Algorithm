#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long d[5001];

long long getRightStr(int n) {
	if (n == 0) {
		return 1;
	}
	else if (d[n] >= 0) {
		return d[n];
	}

	d[n] = 0;
	for (int i = 2; i <= n; i += 2) {
		d[n] = (getRightStr(i - 2) * getRightStr(n - i)) % 1000000007;
		d[n] = d[n] % 1000000007;
	}

	return d[n];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, l;
	cin >> t;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < t; i++) {
		cin >> l;

		if (l % 2 == 0) {
			cout << getRightStr(l) << "\n";
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}