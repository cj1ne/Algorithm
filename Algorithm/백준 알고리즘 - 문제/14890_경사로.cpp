#include <iostream>
#include <vector>
using namespace std;

int n, l;

bool checkDiff(vector<pair<int, int>> cont) {
	for (int i = 0; i < cont.size() - 1; i++) {
		if (cont[i].first - cont[i + 1].first > 1 || cont[i].first - cont[i + 1].first < -1) {
			return false;
		}
	}
	return true;
}

bool isRoad(vector<pair<int, int>> cont) {
	int size = cont.size();

	if (size == 1) return true;
	else if (size == 2) {
		if (checkDiff(cont) == false) return false;
		if (cont[0].first > cont[1].first) {
			if (cont[1].second >= l) return true;
			else return false;
		}
		else {
			if (cont[0].second >= l) return true;
			else return false;
		}
	}
	else {
		if (checkDiff(cont) == false) return false;
		for (int i = 1; i < size - 1; i++) {
			if (cont[i - 1].first > cont[i].first) {
				if (cont[i].first < cont[i + 1].first) { // ÇÏ°­ »ó½Â
					if(cont[i].second < 2 * l) return false;
				}
				else {  // ÇÏ°­ ÇÏ°­
					if (cont[i].second < l || cont[i + 1].second < l) return false;
				}
			}
			else { 
				if (cont[i].first < cont[i + 1].first) { // »ó½Â »ó½Â
					if (cont[i - 1].second < l || cont[i].second < l) return false;
				}
				else { // »ó½Â ÇÏ°­
					if (cont[i - 1].second < l || cont[i + 1].second < l) return false;
				}
			}
		}
	}

	return true;
}

vector<pair<int, int>> makeCont(vector<int> line) {
	vector<pair<int, int>> result;
	int num = line[0];
	int cnt = 1;

	for (int i = 0; i < n - 1; i++) {
		if (line[i] == line[i + 1]) {
			cnt++;
		}
		else {
			result.push_back(make_pair(num, cnt));

			num = line[i + 1];
			cnt = 1;
		}

		if (i + 1 == n - 1) {
			result.push_back(make_pair(num, cnt));
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;
	cin >> n >> l;

	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (isRoad(makeCont(a[i]))) result++;
	}

	for (int i = 0; i < n; i++) {
		vector<int> d;
		for (int j = 0; j < n; j++) {
			d.push_back(a[j][i]);
		}
		if (isRoad(makeCont(d))) result++;
	}

	cout << result << "\n";
	return 0;
}