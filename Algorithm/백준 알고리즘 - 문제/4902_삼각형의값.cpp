#include <iostream>
#include <cstring>
using namespace std;
const int INF = -100000;

int n;
int result = 0;
int a[401][801];
int s[401][801];

void calc(int row, int left, int right, int sum) {
	if (row < 1 || row > n) return;
	if (left < 1 || right >(2 * row) - 1) return;

	sum += s[row][right] - s[row][left - 1];
	if (sum > result) result = sum;

	if (left % 2 == 0) {
		calc(row - 1, left - 2, right, sum);
	}
	else {
		calc(row + 1, left, right + 2, sum);
	}
}

int main() {
	cin >> n;
	int index = 1;

	while (n != 0) {
		result = INF;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= (2 * i) - 1; j++) {
				cin >> a[i][j];
				s[i][j] = s[i][j - 1] + a[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= (2 * i) - 1; j++) {
				calc(i, j, j, 0);
			}
		}

		cout << index << ". " << result << "\n";
		index += 1;
		cin >> n;
	}
	return 0;
}