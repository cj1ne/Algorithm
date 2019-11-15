#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<int> judge;

long long getPeopleCount(long long time) {
	long long count = 0;

	for (int i = 0; i < n; i++) {
		count += (time / judge[i]);
	}

	return count;
}

long long solution() {
	long long max = 0;

	for (int i = 0; i < n; i++) {
		if (judge[i] > max) {
			max = judge[i];
		}
	}

	long long start = 1;
	long long end = max * m;
	long long result = max * m;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long count = getPeopleCount(mid);

		if (count >= m) {
			if (mid < result) {
				result = mid;
			}
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		
		if (judge.size() > 0) {
			judge.clear();
		}
	
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			judge.push_back(input);
		}

		cout << "#" << test_case << " " << solution() << "\n";
	}
	return 0;
}