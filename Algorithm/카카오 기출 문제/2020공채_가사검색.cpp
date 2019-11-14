#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	map<string, int> result;
	int query_size = queries.size();
	int word_size = words.size();

	for (int i = 0; i < query_size; i++) {
		string query = queries[i];

		if (result.count(query) == 0) {
			int count = 0;
			int length = query.length();

			int start = query.find_first_of('?');
			int end = query.find_last_of('?');

			if (start > length  && end > length) {
				for (int j = 0; j < word_size; j++) {
					if (words[j].length() != length) continue;
					if (query.compare(words[j]) == 0) {
						count++;
					}
				}
				answer.push_back(count);
				result.insert(make_pair(query, count));
			}
			else {
				if (start > 0) {
					for (int j = 0; j < word_size; j++) {
						string word = words[j];

						if (length != word.length()) continue;
						bool check = true;

						for (int k = 0; k < start; k++) {
							if (query[k] != word[k]) {
								check = false;
								break;
							}
						}

						if (check) {
							count++;
						}
					}
				}
				else {
					for (int j = 0; j < word_size; j++) {
						string word = words[j];

						if (length != word.length()) continue;
						bool check = true;

						for (int k = end + 1; k < length; k++) {
							if (query[k] != word[k]) {
								check = false;
								break;
							}
						}

						if (check) {
							count++;
						}
					}
				}
				result.insert(make_pair(query, count));
				answer.push_back(count);
			}
		}
		else {
			answer.push_back(result.find(query)->second);
		}
	}
	return answer;
}

int main() {
	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
	
	vector<int> result = solution(words, queries);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}