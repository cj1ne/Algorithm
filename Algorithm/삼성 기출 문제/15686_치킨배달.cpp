#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<int>> a;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int get_city_chicken(vector<int> &order) {
	int result = 0;

	for (int i = 0; i < home.size(); i++) {
		int distance = -1;

		for (int j = 0; j < order.size(); j++) {
			if (order[j] == 0) continue;
			
			int dx = home[i].first - chicken[j].first;
			int dy = home[i].second - chicken[j].second;

			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;

			if (distance == -1 || dx + dy < distance) {
				distance = dx + dy;
			}
		}
		result += distance;
	}
	return result;
}

int main() {
	int result = -1;
	int n, m;

	cin >> n >> m;
	a.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
			else if (a[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
		}
	}

	int size = chicken.size();
	vector<int> order(size, 0);
	for (int i = 1; i <= m; i++) {
		order[size - i] = 1;
	}

	do {
		int distance = get_city_chicken(order);

		if (result == -1 || distance < result) {
			result = distance;
		}
	} while (next_permutation(order.begin(), order.end()));

	cout << result << "\n";
}