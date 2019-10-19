#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v;
vector<vector<bool>> a;
int n;

bool is_possible(vector<int> team) {
	int size = team.size();
	if (size > 1) {
		vector<bool> d(n, false);
		queue<int> q;

		d[team[0]] = true;
		q.push(team[0]);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < size; i++) {
				int next = team[i];
				if (a[now][next] == true && d[next] == false) {
					d[next] = true;
					q.push(next);
				}
			}
		}

		for (int i = 0; i < size; i++) {
			int now = team[i];
			if (d[now] == false) return false;
		}
	}
	return true;
}

int get_sum(vector<int> team) {
	int sum = 0;

	for (int i = 0; i < team.size(); i++) {
		int now = team[i];
		sum += v[now];
	}
	return sum;
}

void print(vector<int> team) {
	cout << "\n";
	for (int i = 0; i < team.size(); i++) {
		cout << team[i] << " ";
	}
	cout << "\n";
}

int main() {
	int count, to, result = -1;
	cin >> n;

	a.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		cin >> count;
		v.push_back(count);
	}

	for (int i = 0; i < n; i++) {
		cin >> count;
		for (int j = 0; j < count; j++) {
			cin >> to;
			a[i][to - 1] = true;
		}
	}

	for (int i = 1; i <= n / 2; i++) {
		vector<int> order(n, 0);
		for (int j = 1; j <= i; j++) {
			order[n - j] = 1;
		}

		do {
			vector<int> t0, t1;

			for (int i = 0; i < n; i++) {
				if (order[i] == 0) {
					t0.push_back(i);
				}
				else {
					t1.push_back(i);
				}
			}

			if (is_possible(t0) && is_possible(t1)) {
				int diff = get_sum(t0) - get_sum(t1);
				if (diff < 0) diff = -diff;

				if (result == -1 || diff < result) {
					result = diff;
				}
			}
		} while (next_permutation(order.begin(), order.end()));
	}
	cout << result << "\n";
	return 0;
}