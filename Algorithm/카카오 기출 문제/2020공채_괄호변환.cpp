#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isCorrect(string s) {
	int cnt_open = 0;
	int cnt_close = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') cnt_open++;
		else cnt_close++;

		if (cnt_close > cnt_open) {
			return false;
		}
	}
	return true;
}

void divide(string &u, string &v, string s) {
	int cnt_open = 0;
	int cnt_close = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') cnt_open++;
		else cnt_close++;

		if (cnt_close == cnt_open) {
			u = s.substr(0, i + 1);
			v = s.substr(i + 1, s.length() - (i + 1));
			break;
		}
	}
}

string solution(string p) {
	string answer = "";

	if (p.length() == 0) {
		return answer;
	}

	string u, v;
	divide(u, v, p);

	if (isCorrect(u)) {
		return u + solution(v);
	}
	else {
		answer += "(";
		answer += solution(v);
		answer += ")";

		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == '(') {
				answer += ")";
			}
			else {
				answer += "(";
			}
		}
		return answer;
	}
}

int main() {
	string s = "()))((()";
	cout << solution(s) << "\n";
	return 0;
}