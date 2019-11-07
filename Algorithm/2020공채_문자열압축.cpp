#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
	int length = s.length();
	int answer = length;

	for (int i = 1; i <= length / 2; i++) {
		int count = 1;
		int temp_length = 0;
	
		string now = s.substr(0, i);
		int j = i;

		while (true) {
			string next = s.substr(j, i);

			if (now == next) {
				count++;
			}
			else {
				if (count == 1) {
					temp_length += i;
				}
				else {
					temp_length += i + to_string(count).length();
				}

				now = next;
				count = 1;
			}

			j += i;

			if (j == length) {
				if (count == 1) {
					temp_length += i;
				}
				else {
					temp_length += i + to_string(count).length();
				}
				break;
			}
			else if (j > length) {
				temp_length += next.length();
				break;
			}
		}

		if (temp_length < answer) {
			answer = temp_length;
		}
	}
	return answer;
}

int main() {
	string s = "aabbaccc";
	cout << solution(s) << "\n";
}