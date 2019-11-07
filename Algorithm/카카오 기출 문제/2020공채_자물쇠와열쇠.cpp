#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isAnswer(vector<vector<int>> &key, vector<vector<int>> &lock) {
	int n = lock.size();
	int m = key.size();

	vector<vector<int>> a(n + 2 * (m - 1), vector<int>(n + 2 * (m - 1), 0));

	int cnt_down = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lock[i][j] == 0) {
				cnt_down++;
			}
			else {
				a[m - 1 + i][m - 1 + j] = lock[i][j];
			}
		}
	}

	for (int i = 0; i <= n + m - 2; i++) {
		for (int j = 0; j <= n + m - 2; j++) {
			int cnt = 0;
			bool check = true;

			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (i + k < m - 1 || i + k > n + m - 2 || j + l < m - 1 || j + l > n + m - 2) continue;
					if (key[k][l] == 0) continue;

					if (a[i + k][j + l] == key[k][l]) {
						check = false;
						break;
					}
					else {
						cnt++;
					}
				}
			}

			if (cnt == cnt_down && check) {
				return true;
			}
		}
	}
	return false;
}

void rotate_key(vector<vector<int>> &key) {
	int size = key.size();
	vector<vector<int>> a(key);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			key[j][size - 1 - i] = a[i][j];
		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;

	for (int i = 0; i < 4; i++) {
		rotate_key(key);
		if (isAnswer(key, lock)) {
			answer = true;
			break;
		}
	}

	return answer;
}

int main() {
	cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}) << "\n";
	return 0;
}