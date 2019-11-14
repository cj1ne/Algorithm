#include <iostream>
using namespace std;

int main() {
	int n, sum;
	int result = 1;
	cin >> n;

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			sum = ((j + i) * (j - i + 1)) / 2;
			
			if (sum > n) break;
			else if (sum == n) {
				result++;
			}
		}
	}

	cout << result << "\n";
	cout << result << "\n";
	return 0;
}