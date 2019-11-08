#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return false;
	}
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> ing(N + 2, 0);
	vector<int> reach(N + 2, 0);
	vector<pair<int, double>> order;

	for (int i = 0; i < stages.size(); i++) {
		int now = stages[i];

		for (int j = 1; j <= now; j++) {
			reach[j] += 1;
		}
		ing[now] += 1;
	}

	for (int i = 1; i < N + 1; i++) {
		if (reach[i] == 0) {
			order.push_back(make_pair(i, 0));
		}
		else {
			order.push_back(make_pair(i, double(ing[i]) / reach[i]));
		}
	}

	sort(order.begin(), order.end(), compare);

	for (int i = 0; i < N; i++) {
		answer.push_back(order[i].first);
	}
	return answer;
}

int main() {
	vector<int> result = solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}