#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

vector<vector<bool>> a;
queue<pair<int, char>> command;
int n;

void move(int &x, int &y, int direction) {
	switch (direction) {
	case NORTH:
		x--; break;
	case EAST:
		y++; break;
	case SOUTH:
		x++;  break;
	case WEST:
		y--; break;
	}
}

int startGame() {
	vector<vector<bool>> d(n, vector<bool>(n, false));
	deque<pair<int, int>> snake;

	int x = 0, y = 0;
	int direction = EAST, time = 0;

	int commandTime = command.front().first;
	char commandDirection = command.front().second;
	command.pop();

	d[x][y] = true;
	snake.push_front(make_pair(x, y));

	while (true) {
		time++;
		move(x, y, direction);

		if (x < 0 || x >= n || y < 0 || y >= n || d[x][y] == true) return time;

		d[x][y] = true;
		snake.push_front(make_pair(x, y));

		if (a[x][y] == true) {
			a[x][y] = false;
		}
		else {
			int hx = snake.back().first;
			int hy = snake.back().second;
			d[hx][hy] = false;

			snake.pop_back();
		}

		if (time == commandTime) {
			if (commandDirection == 'L') {
				direction = (direction + 3) % 4;
			}
			else {
				direction = (direction + 1) % 4;
			}

			if (command.empty()) {
				commandTime = -1;
				commandDirection = '\0';
			}
			else {
				commandTime = command.front().first;
				commandDirection = command.front().second;
				command.pop();
			}
		}
	}
}

int main() {

	int k, l;
	cin >> n >> k;

	a.assign(n, vector<bool>(n, false));

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = true;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int when;
		char direction;
		cin >> when >> direction;
		command.push(make_pair(when, direction));
	}

	cout << startGame() << "\n";

	return 0;
}