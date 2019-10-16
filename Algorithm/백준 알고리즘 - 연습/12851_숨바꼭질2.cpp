#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int d[100001];
int cnt[100001];

int main() {
	int n, k;
	cin >> n >> k;
	memset(d, -1, sizeof(d));
	memset(cnt, 0, sizeof(cnt));

	queue<int> q;
	q.push(n);

	d[n] = 0;
	cnt[n] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : {now - 1, now + 1, now * 2 }) {
			if (next < 0 || next > 100000) continue;

			if (d[next] == -1) {
				d[next] = d[now] + 1;
				q.push(next);
				cnt[next] = cnt[now];
			}
			else if (d[next] == d[now] + 1) {
				cnt[next] += cnt[now];
			}
		}
	}

	cout << d[k] << "\n";
	cout << cnt[k] << "\n";
	return 0;
}