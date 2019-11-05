#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int n, k, input;
	bool d[360];

	memset(d, false, sizeof(d));
	d[0] = true;

	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 360; j++) {
			for (int k = 0; k < 360; k++) {
				if (d[k] == false) continue;
				d[(k + a[i]) % 360] = true;
				d[(k - a[i] + 360) % 360] = true;
			}
		}
	}


	for (int j = 0; j < k; j++) {
		cin >> input;
		if (d[input] == true) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}