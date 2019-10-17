#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
const int NONE = -1;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int n;
vector<vector<bool>> a;
queue<pair<int, char>> route;

int rotate_head(int snake_direction, char direction) {
	if (direction == 'L') {
		return (snake_direction + 3) % 4;
	}
	else {
		return (snake_direction + 1) % 4;
	}
}

int play() {
	int result = 0;
	int snake_direction = RIGHT;
	int time = NONE;
	char direction = '\0';

	vector<vector<bool>> check(n, vector<bool>(n, false));
	deque<pair<int, int>> snake;
	snake.push_back(make_pair(0, 0));
	check[0][0] = true;

	if (!route.empty()) {
		time = route.front().first;
		direction = route.front().second;
		route.pop();
	}

	while (true) {
		int nx = snake.back().first;
		int ny = snake.back().second;
		result++;
	
		switch (snake_direction) {
			case UP:
				nx--; break;
			case RIGHT:
				ny++; break;
			case DOWN:
				nx++; break;
			case LEFT:
				ny--; break;
		}

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || check[nx][ny]) break;
		snake.push_back(make_pair(nx, ny));
		check[nx][ny] = true;

		if (a[nx][ny]) {
			a[nx][ny] = false;
		}
		else {
			check[snake.front().first][snake.front().second] = false;
			snake.pop_front();
		}

		if (result == time) {
			snake_direction = rotate_head(snake_direction, direction);

			if(!route.empty()) {
				time = route.front().first;
				direction = route.front().second;
				route.pop();
			}
		}
	}
	return result;
}

int main() {
	char direction;
	int k, l, time;

	cin >> n >> k;
	a.assign(n, vector<bool>(n, false));

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = true;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> time >> direction;
		route.push(make_pair(time, direction));
	}

	cout << play() << "\n";
	return 0;
}