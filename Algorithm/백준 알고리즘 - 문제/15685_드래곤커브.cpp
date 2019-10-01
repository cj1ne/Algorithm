#include <iostream>
#include <vector>
using namespace std;

const int EAST = 0;
const int NORTH = 1;
const int WEST = 2;
const int SOUTH = 3;

vector<vector<bool>> d(101, vector<bool>(101, false));

vector<pair<int, int>> rotateDragon(vector<pair<int, int>> road) {
	int size = road.size();
	int x = road[size - 1].first;
	int y = road[size - 1].second;

	for (int i = size - 2; i >= 0; i--) {
		int nx = road[i].first;
		int ny = road[i].second;

		road.push_back(make_pair(x + y - ny, y -x + nx));
	}
	return road;
}

vector<pair<int, int>> makeDragon(int x, int y, int d, int g, vector<pair<int, int>> road) {

	if (g == 0) {
		road.push_back(make_pair(x, y));

		switch (d) {
		case EAST: road.push_back(make_pair(x + 1, y));
			break;
		case NORTH: road.push_back(make_pair(x, y - 1));
			break;
		case WEST : road.push_back(make_pair(x - 1, y));
			break;
		case SOUTH : road.push_back(make_pair(x, y + 1));
			break;
		}
		return road;
	}

	road = makeDragon(x, y, d, g - 1, road);
	return rotateDragon(road);
}

void addDragon(vector<pair<int, int>> road) {
	for(int i = 0; i < road.size(); i++) {
		d[road[i].first][road[i].second] = true;
	}
}

int getSquare() {
	int count = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (d[i][j] && d[i][j + 1] && d[i + 1][j] && d[i + 1][j + 1]) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y, direction, generation;
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> road;
 		cin >> x >> y >> direction >> generation;
		road = makeDragon(x, y, direction, generation, road);
		addDragon(road);
	}

	cout << getSquare() << "\n";
	return 0;
}