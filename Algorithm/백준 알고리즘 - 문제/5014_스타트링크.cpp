#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f, s, g, u, d;
vector<int> dist;

void bfs() {
	queue<int> q;

	dist[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int next = now + u;
		if (next <= f && dist[next] == -1) {
			dist[next] = dist[now] + 1;
			q.push(next);
		}

		next = now - d;
		if (next >= 1 && dist[next] == -1) {
			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;
	dist.assign(f + 1, -1);
	
	bfs();

	if (dist[g] != -1) {
		cout << dist[g] << "\n";
	}
	else {
		cout << "use the stairs\n";
	}
	return 0;
}