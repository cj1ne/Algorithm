#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int EAST = 0;
const int NORTH = 1;
const int WEST = 2;
const int SOUTH = 3;

bool a[101][101];

void dragonCurve(int x, int y, int direction, int generation) {
	vector<pair<int, int>> dragon;
	dragon.push_back(make_pair(y, x));
	a[y][x] = true;

	switch (direction) {
		case EAST:
			a[y][x + 1] = true;
			dragon.push_back(make_pair(y, x + 1));
			break;
		case NORTH:
			a[y - 1][x] = true;
			dragon.push_back(make_pair(y - 1, x));
			break;
		case WEST:
			a[y][x - 1] = true;
			dragon.push_back(make_pair(y, x - 1));
			break;
		case SOUTH:
			a[y + 1][x] = true;
			dragon.push_back(make_pair(y + 1, x));
			break;
	}

	for (int i = 1; i <= generation; i++) {
		int size = dragon.size();

		int y = dragon[size - 1].first;
		int x = dragon[size - 1].second;

		for (int j = size - 2; j >= 0; j--) {
			int ey = dragon[j].first;
			int ex = dragon[j].second;

			int ny = y + (ex - x);
			int nx = x + (y - ey);

			a[ny][nx] = 1;
			dragon.push_back(make_pair(ny, nx));
		}
	}
}

int get_square() {
	int count = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	int n, x, y, d, g;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		dragonCurve(x, y, d, g);
	}

	cout << get_square() << "\n";
	return 0;
}