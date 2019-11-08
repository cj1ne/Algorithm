#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool isOnly(deque<int> &selected, vector<vector<string>> &relation) {
	int h = relation.size();

	for (int i = 0; i < h - 1; i++) {
		for (int j = i + 1; j < h; j++) {
			int cnt = 0;

			for (int k = 0; k < selected.size(); k++) {
				int index = selected[k];
				if (relation[i][index].compare(relation[j][index]) == 0) {
					cnt++;
				}
			}

			if (cnt == selected.size()) return false;
		}
	}
	return true;
}

int solution(vector<vector<string>> a) {
	int answer = 0;
	int h = a.size();
	int w = a[0].size();

	for (int i = 1; i <= w; i++) {
		vector<int> order(w, 0);

		for (int j = 0; j < i; j++) {
			order[order.size() - 1 - j] = 1;
		}

		do {
			deque<int> now;
			for (int j = 0; j < order.size(); j++) {
				if (order[j] == 1) {
					now.push_back(j);
				}
			}

			if (isOnly(now, a)) {
				bool check = true;
				int size = now.size();

				for (int j = 0; j < size; j++) {
					int back = now.back();
					now.pop_back();

					if (isOnly(now, a)) {
						check = false;
						break;
					}
					now.push_front(back);
				}

				if (check == true) {
					answer++;
				}
			}
		} while (next_permutation(order.begin(), order.end()));
	}
	return answer;
}

int main() {
	vector<vector<string>> relation = { { "100", "ryan", "music", "2" },{ "200", "apeach", "math", "2" },{ "300", "tube", "computer", "3" },{ "400", "con", "computer", "4" },{ "500", "muzi", "music", "3" },{ "600", "apeach", "music", "2" } };
	cout << solution(relation) << "\n";
	return 0;
}