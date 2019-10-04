#include <iostream>
#include <utility>
#include <string>
#include <set>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int a[5][5];
set<int> num;

void go(int x, int y, int n, int length) {
	if (length == 6) {
		num.insert(n);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		go(nx, ny, (n * 10) + a[nx][ny], length + 1);
	}
}

int main() {	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(i, j, a[i][j], 1);
		}
	}

	cout << num.size() << "\n";
	return 0;
}