#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

typedef struct Info {
	int x;
	int y;
	int memory;
	int direction;
}info;

int t, h, w;

void move(int &x, int &y, int direction) {
	switch (direction) {
		case UP:
			x = (x + h - 1) % h;
			break;
		case DOWN:
			x = (x + 1) % h;
			break;
		case RIGHT:
			y = (y + 1) % w;
			break;
		case LEFT:
			y = (y + w - 1) % w;
			break;
	}
}

bool isPossible(vector<string> &a) {
	bool d[20][20][16][4];
	queue<info> q;

	memset(d, false, sizeof(d));
	d[0][0][0][RIGHT] = true;
	q.push({0, 0, 0, RIGHT});

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		char command = a[now.x][now.y];
	
		if (command == '?') {
			int x, y;

			for (int i = 0; i < 4; i++) {
				x = now.x;
				y = now.y;

				move(x, y, i);

				if (d[x][y][now.memory][i] == false) {
					d[x][y][now.memory][i] = true;
					q.push({ x, y, now.memory, i });
				}
			}
		}
		else {
			if (command >= '0' && command <= '9') {
				now.memory = command - '0';
			}
			else {
				switch (command) {
					case '<':
						now.direction = LEFT;
						break;
					case '>':
						now.direction = RIGHT;
						break;
					case '^':
						now.direction = UP;
						break;
					case 'v':
						now.direction = DOWN;
						break;
					case '_':
						if (now.memory == 0) now.direction = RIGHT;
						else now.direction = LEFT;
						break;
					case '|':
						if (now.memory == 0) now.direction = DOWN;
						else now.direction = UP;
						break;
					case '.':
						break;
					case '@':
						return true;
						break;
					case '+':
						now.memory += 1;
						if (now.memory == 16) now.memory = 0;
						break;
					case '-':
						now.memory -= 1;
						if (now.memory == -1) now.memory = 15;
						break;
				}
			}

			move(now.x, now.y, now.direction);

			if (d[now.x][now.y][now.memory][now.direction] == false) {
				d[now.x][now.y][now.memory][now.direction] = true;
				q.push(now);
			}
		}
	}
	return false;
}

int main() {
	bool result;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> h >> w;
		vector<string> a(h);

		for (int j = 0; j < h; j++) {
			cin >> a[j];
		}

		result = isPossible(a);

		if (result) {
			cout << "#" << i << " YES\n";
		}
		else {
			cout << "#" << i << " NO\n";
		}
	}
	return 0;
}