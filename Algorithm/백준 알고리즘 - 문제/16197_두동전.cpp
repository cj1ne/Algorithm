#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int h, w;
int result = -1;
vector<string> a;

bool isExit(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w) {
		return true;
	}
	else {
		return false;
	}
}

void go(int count, int x1, int y1, int x2, int y2) {
	if (count > 10) return;

	bool check1 = isExit(x1, y1);
	bool check2 = isExit(x2, y2);

	if (check1 && check2) return;
	if ((check1 && !check2) || (!check1 && check2)) {
		if (result == -1 || count < result) result = count;
		return;
	}

	int n1, n2;
	n1 = x1 + 1; n2 = x2 + 1;

	if (n1 < h && a[n1][y1] == '#') n1 = x1;
	if (n2 < h && a[n2][y2] == '#') n2 = x2;
	if (n1 != x1 || n2 != x2) {
		go(count + 1, n1, y1, n2, y2);
	}

	n1 = x1 - 1; n2 = x2 - 1;
	if (n1 >= 0 && a[n1][y1] == '#') n1 = x1;
	if (n2 >= 0 && a[n2][y2] == '#') n2 = x2;
	if (n1 != x1 || n2 != x2) {
		go(count + 1, n1, y1, n2, y2);
	}

	n1 = y1 + 1; n2 = y2 + 1;
	if (n1 < w && a[x1][n1] == '#') n1 = y1;
	if (n2 < w && a[x2][n2] == '#') n2 = y2;
	if (n1 != y1 || n2 != y2) {
		go(count + 1, x1, n1, x2, n2);
	}

	n1 = y1 - 1; n2 = y2 - 1;
	if (n1 >= 0 && a[x1][n1] == '#') n1 = y1;
	if (n2 >= 0 && a[x2][n2] == '#') n2 = y2;
	if (n1 != y1 || n2 != y2) {
		go(count + 1, x1, n1, x2, n2);
	}
}

int main() {
	vector<pair<int, int>> coin;
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		a.push_back(str);

		for (int j = 0; j < w; j++) {
			if (str[j] == 'o') {
				coin.push_back(make_pair(i, j));
			}
		}
	}

	go(0, coin[0].first, coin[0].second, coin[1].first, coin[1].second);
	cout << result << "\n";
	return 0;
}