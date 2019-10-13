#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> a;
map<int, int> d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long result = 0;
	int n, b, c, input;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}

	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		if (d.count(a[i]) == 0) {
			int remain = a[i] - b;
			if (remain <= 0) {
				d.insert(make_pair(a[i], 1));
				result += 1;
			}
			else {
				int sub = remain / c;
				if (sub * c < remain) sub++;

				d.insert(make_pair(a[i], sub + 1));
				result += sub + 1;
			}
		}
		else {
			result += d.find(a[i])->second;
		}
	}

	cout << result << "\n";
	return 0;
}