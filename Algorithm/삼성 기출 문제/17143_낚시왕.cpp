#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
const int UP = 1;
const int DOWN = 2;
const int RIGHT = 3;
const int LEFT = 4;

int h, w;

vector<vector<bool>> d;
vector<vector<tuple<int, int, int>>> shark;

void printShark() {
	cout << "\n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}

void moveShark() {
	queue<pair<int, int>> q;
	vector<vector<bool>> selected(h, vector<bool>(w, false));
	vector<vector<tuple<int, int, int>>> movedShark(h, vector<tuple<int, int, int>>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (d[i][j] == false) continue;
			q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int speed, direction, size, nx, ny;
		tie(speed, direction, size) = shark[x][y];

		if (direction == UP || direction == DOWN) {
			if (direction == UP) {
				int remain = speed - x;

				if (remain > 0) {
					if (remain % ((h - 1) * 2) < h) {
						nx = remain % ((h - 1) * 2);
						direction = DOWN;
					}
					else {
						nx = ((h - 1) * 2) - (remain % ((h - 1) * 2));
					}
				}
				else {
					nx = x - speed;
				}
			}
			else {
				int remain = speed - (h - 1 - x);

				if (remain > 0) {
					if (remain % ((h - 1) * 2) < h) {
						nx = (h - 1) - (remain % ((h - 1) * 2));
						direction = UP;
					}
					else {
						nx = (remain % ((h - 1) * 2)) - (h - 1);
					}
				}
				else {
					nx = x + speed;
				}
			}


			if ((selected[nx][y] && size > get<2>(movedShark[nx][y]) || selected[nx][y] == false)) {
				selected[nx][y] = true;
				movedShark[nx][y] = make_tuple(speed, direction, size);
			}
		}
		else {
			if (direction == LEFT) {
				int remain = speed - y;

				if (remain > 0) {
					if (remain % ((w - 1) * 2) < w) {
						ny = remain % ((w - 1) * 2);
						direction = RIGHT;
					}
					else {
						ny = ((w - 1) * 2) - (remain % ((w - 1) * 2));
					}
				}
				else {
					ny = y - speed;
				}
			}
			else {
				int remain = speed - (w - 1 - y);

				if (remain > 0) {
					if (remain % ((w - 1) * 2) < w) {
						ny = (w - 1) - (remain % ((w - 1) * 2));
						direction = LEFT;
					}
					else {
						ny = (remain % ((w - 1) * 2)) - (w - 1);
					}
				}
				else {
					ny = y + speed;
				}
			}

			if ((selected[x][ny] && size > get<2>(movedShark[x][ny])) || selected[x][ny] == false) {
				selected[x][ny] = true;
				movedShark[x][ny] = make_tuple(speed, direction, size);
			}
		}
	}

	d = selected;
	shark = movedShark;
}

int getShark() {
	int result = 0;

	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (d[i][j] == true) {
				result += get<2>(shark[i][j]);
				d[i][j] = false;
				break;
			}
		}
		moveShark();
	}
	return result;
}

int main() {
	int m;
	cin >> h >> w >> m;
	d.assign(h, vector<bool>(w, false));
	shark.assign(h, vector<tuple<int, int, int>>(w));

	for (int i = 0; i < m; i++) {
		int x, y, speed, direction, size;
		cin >> x >> y >> speed >> direction >> size;

		d[x - 1][y - 1] = true;
		shark[x - 1][y - 1] = make_tuple(speed, direction, size);
	}
	cout << getShark() << "\n";
	return 0;
}

/*

1. 상어가 이동하는 규칙을 단순한 식으로 세우려고 하다가 간단하게 식도 찾지 못하고 시간을 오래 잡았다.
이쁘게 만드려는 것보다 알고리즘은 우선 풀어내는 것이 중요하다.

문제의 조건에 대해 파고 들지 않았다. 조금만 더 생각해봐도 예외를 잡을 수 있었는데 말이다.

항상 메모리를 많이 사용하지 않으려고 하다보니까, 오히려 주객전도 현상이 일어났다. 초과가 되지 않는 이상 문제 해결이 메모리 관리보다 우선 사항이다.


*/