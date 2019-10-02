#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	int index; 

	vector<string> variable;
	string common;
	string str;

	getline(cin,  str);
	
	index = str.find(' ');
	common = str.substr(0, index);
	str.erase(0, index + 1);

	while (str.find_first_of(',') < str.length()) {
		index = str.find_first_of(',');
		variable.push_back(str.substr(0, index));
		str.erase(0, index + 2);
	}

	index = str.find_first_of(';');
	variable.push_back(str.substr(0, index));

	for (int i = 0; i < variable.size(); i++) {
		string result = common;	
		
		for (int j = variable[i].length() - 1; j >= 0; j--) {
			if ((variable[i][j] >= 'a' && variable[i][j] <= 'z') || (variable[i][j] >= 'A' && variable[i][j] <= 'Z')) {
				index = j;
				result += " " + variable[i].substr(0, index + 1) + ";";
				break;
			}
			else if (variable[i][j] == ']') {
				result += '[';
			}
			else if (variable[i][j] == '[') {
				result += ']';
			}
			else {
				result += variable[i][j];
			}
		}
		cout << result << "\n";
	}
	return 0;
}