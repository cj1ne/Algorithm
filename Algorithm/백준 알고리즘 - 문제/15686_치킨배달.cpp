#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<int>> a;
vector<pair<int, int>> chicken;
vector<pair<int, int>> client;

int getCityChicken(vector<int> &order) {
	int cityChicken = 0;

	for (int i = 0; i < client.size(); i++) {
		int chickenDist = -1;

		for (int j = 0; j < order.size(); j++) {
			if (order[j] == 0) continue;
				
			int distX = client[i].first - chicken[j].first;
			if (distX < 0) distX = -distX;

			int distY = client[i].second - chicken[j].second;
			if (distY < 0) distY = -distY;

			if (chickenDist == -1 || distX + distY < chickenDist) {
				chickenDist = distX + distY;
			}
 		}
		cityChicken += chickenDist;
	}
	return cityChicken;
}

int main() {
	int n, m, cntChicken = 0, result = -1;
	cin >> n >> m;

	a.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
				cntChicken++;
			}
			else if (a[i][j] == 1) {
				client.push_back(make_pair(i, j));
			}
		}
	}

	vector<int> order(cntChicken, 0);
	for (int i = 0; i < m; i++) {
		order[cntChicken - 1 - i] = 1;
	}

	do {
		int dist = getCityChicken(order);
		if (result == -1 || dist < result) {
			result = dist;
		}

	} while (next_permutation(order.begin(), order.end()));

	cout << result << "\n";
	return 0;
}