#include <iostream>
#include <vector>
using namespace std;

int result = -1;

void go(vector<int> &a, int sum) {
	int size = a.size();

	if (size == 2) {
		if (result == -1 || sum > result) {
			result = sum;
		}
		return;
	}

	for (int i = 1; i < size - 1; i++) {
		vector<int> next(a);
		next.erase(next.begin() + i);
		go(next, sum + a[i - 1] * a[i + 1]);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	go(a, 0);
	cout << result << "\n";
	return 0;
}