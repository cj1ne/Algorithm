#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int PLUS = 0;
const int MINUS = 1;
const int MUL = 2;
const int DIV = 3;

vector<int> a;
vector<int> operate;
int n;

int get_operation() {
	int result = a[0];

	for (int i = 0; i < n - 1; i++) {
		switch (operate[i]) {
		case PLUS:
			result += a[i + 1];
			break;
		case MINUS:
			result -= a[i + 1];
			break;
		case MUL:
			result *= a[i + 1];
			break;
		case DIV:
			result /= a[i + 1];
			break;
		}
	}
	return result;
}

int main() {
	int minResult = 1000000000, maxResult = -1000000000;
	int input;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}

	for (int i = 0; i < 4; i++) {
		cin >> input;

		for (int j = 0; j < input; j++) {
			operate.push_back(i);
		}
	}

	do {
		int result = get_operation();

		if (result < minResult) {
			minResult = result;
		}

		if (result > maxResult) {
			maxResult = result;
		}
	} while (next_permutation(operate.begin(), operate.end()));

	cout << maxResult << "\n" << minResult << "\n";
	return 0;
}