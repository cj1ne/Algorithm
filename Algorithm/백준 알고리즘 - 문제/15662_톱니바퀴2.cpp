#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

vector<string> gear;

const int CONNECT_RIGHT = 2;
const int CONNECT_LEFT = 6;
const int ROTATE_RIGHT = 1;
const int ROTATE_LEFT = -1;

void rotateLeft(int index) {
	char temp = gear[index][0];
	gear[index].erase(0, 1);
	gear[index] += temp;
}

void rotateRight(int index) {
	char temp = gear[index][7];
	gear[index].erase(7);
	gear[index] = temp + gear[index];
}

vector<pair<int, int>> getRotateGear(int index, int direction) {
	vector<pair<int, int>> result;
	result.push_back(make_pair(index, direction));

	for (int i = index; i > 0; i--) {
		if (gear[i][CONNECT_LEFT] == gear[i - 1][CONNECT_RIGHT]) break;

		if ((index - (i - 1)) % 2 == 1) {
			result.push_back(make_pair(i - 1, direction * -1));
		}
		else {
			result.push_back(make_pair(i - 1, direction));
		}
	}

	for (int i = index; i < gear.size() - 1; i++) {
		if (gear[i][CONNECT_RIGHT] == gear[i + 1][CONNECT_LEFT]) break;

		if ((i + 1 - index) % 2 == 1) {
			result.push_back(make_pair(i + 1, direction * -1));
		}
		else {
			result.push_back(make_pair(i + 1, direction));
		}
	}
	return result;
}

void rotateGear(int index, int direction) {
	vector<pair<int, int>> rotateList = getRotateGear(index, direction);
	
	for (int i = 0; i < rotateList.size(); i++) {
		if (rotateList[i].second == ROTATE_RIGHT) {
			rotateRight(rotateList[i].first);
		}
		else {
			rotateLeft(rotateList[i].first);
		}
	}
}

int getCount() {
	int count = 0;
	for (int i = 0; i < gear.size(); i++) {
		if (gear[i][0] == '1') {
			count++;
		}
	}
	return count;
}

int main() {
	int t, k, index, direction;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		gear.push_back(str);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> index >> direction;
		rotateGear(index - 1, direction);
	}

	cout << getCount() << "\n";
	return 0;
}