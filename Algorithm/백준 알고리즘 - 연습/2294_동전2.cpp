#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	vector<int> d(k + 1, -1);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[a[i]] = 1;
	}

	for (int i = 2; i <= k; i++) {
		if (d[i] != -1) continue;

		int min = -1;

		for (int j = 1; j <= i / 2; j++) {
			if (d[j] == -1 || d[i - j] == -1) continue;

			int temp = d[j] + d[i - j];
			
			if (min == -1 || temp < min) min = temp;
		}

		d[i] = min;
	}

	cout << d[k] << "\n";
	
	

	return 0;
}