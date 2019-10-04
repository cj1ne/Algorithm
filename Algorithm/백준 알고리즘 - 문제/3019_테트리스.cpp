#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> a;
int w;

bool isCorrect(int index, string s) {
	if (index + s.length() > w) return false;

	int standard = a[index] - (s[0] -'0');

	for (int i = 1; i < s.length(); i++) {
		if (standard != a[index + i] - (s[i] - '0')) return false;
	}
	return true;
}

int main() {
	int index, result = 0;
	cin >> w >> index;

	for (int i = 0; i < w; i++) {
		int height;
		cin >> height;
		a.push_back(height);
	}

	for (int i = 0; i < w; i++) {
		if (index == 1) {
			if (isCorrect(i, "0")) result++;
			if (isCorrect(i, "0000")) result++;
		}
		else if (index == 2) {
			if (isCorrect(i, "00")) result++;
		}
		else if (index == 3) {
			if (isCorrect(i, "001")) result++;
			if (isCorrect(i, "10")) result++;
		}
		else if (index == 4) {
			if (isCorrect(i, "100")) result++;
			if (isCorrect(i, "01")) result++;
		}
		else if (index == 5) {
			if (isCorrect(i, "000")) result++;
			if (isCorrect(i, "101")) result++;
			if (isCorrect(i, "01")) result++;
			if (isCorrect(i, "10")) result++;
		}
		else if (index == 6) {
			if (isCorrect(i, "000")) result++;
			if (isCorrect(i, "011")) result++;
			if (isCorrect(i, "00")) result++;
			if (isCorrect(i, "20")) result++;
		}
		else {
			if (isCorrect(i, "000")) result++;
			if (isCorrect(i, "110")) result++;
			if (isCorrect(i, "00")) result++;
			if (isCorrect(i, "02")) result++;
		}
	}

	cout << result << "\n";
	return 0;
}