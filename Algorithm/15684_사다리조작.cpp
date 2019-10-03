#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
vector<vector<bool>> a;

bool play() {
	for (int i = 0; i < w; i++) {
		int index = i;

		for (int j = 0; j < h; j++) {
			if (index - 1 >= 0) {
				if (a[j][index - 1] == true) {
					index = index - 1;
					continue;
				}
			}

			if (index < w - 1) {
				if (a[j][index] == true) {
					index = index + 1;
				}
			}
		}
		if (index != i) return false;
	}
	return true;
}

void addStick(int index, int num, vector<int> selected) {
	if (selected.size() == num) {
		for (int i = 0; i < selected.size(); i++) {
			int nx = selected[i] / (w - 1);
			int ny = selected[i] % (w - 1);

			a[nx][ny] = true;
		}
		
		if (play()) {
			cout << num << "\n";
			exit(0);
		}

		for (int i = 0; i < selected.size(); i++) {
			int nx = selected[i] / (w - 1);
			int ny = selected[i] % (w - 1);

			a[nx][ny] = false;
		}
		return;
	}

	if (index >= h * (w - 1)) return;

	int x = index / (w - 1);
	int y = index % (w - 1);
	bool check = true;

	if (a[x][y]) check = false;
	if (y + 1 < w - 1 && a[x][y + 1]) check = false;
	if (y - 1 >= 0 && a[x][y - 1]) check = false;

	if (check) {
		selected.push_back(index);
		addStick(index + 1, num, selected);
		selected.pop_back();
	}

	addStick(index + 1, num, selected);
}


int main() {
	int n, from, height;
	vector<int> selected;
	cin >> w >> n >> h;

	a.assign(h, vector<bool>(w - 1, false));
	for (int i = 0; i < n; i++) {
		cin >> height >> from;
		a[height - 1][from - 1] = true;
	}

	if (play()) {
		cout << 0 << "\n";
	}
	else {
		for (int i = 1; i <= 3; i++) {
			addStick(0, i, selected);
		}
		cout << -1 << "\n";
	}

	return 0;
}