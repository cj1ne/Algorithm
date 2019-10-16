#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> consult;
int result = -1;
int n;

void work(int index, int money) {
	if (index == n) {
		if (result == -1 || money > result) {
			result = money;
		}
		return;
	}
	
	if (index + consult[index].first <= n) {
		work(index + consult[index].first, money + consult[index].second);
	}
	work(index + 1, money);
}

int main() {
	int time, pay;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> time >> pay;
		consult.push_back(make_pair(time, pay));
	}

	work(0, 0);
	cout << result << "\n";
	return 0;
}