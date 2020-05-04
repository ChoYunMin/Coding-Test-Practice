#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> inputString;

	cout << "Input an array of strings: ";
	do { // 원하는 만큼 입력받기
		string temp;
		cin >> temp;
		inputString.push_back(temp);
	} while (getc(stdin) == ' ');

	int prefix = inputString[0].size(); // 첫 번째 string을 기준으로 비교
	for (int i = 1; i < inputString.size(); i++) {
		for (int j = 0; j < min(inputString[0].size(), inputString[i].size()); j++) {
			if (inputString[0][j] != inputString[i][j]) {
				prefix = min(prefix, j);
			}
		}
	}

	cout << "Output: " << prefix << endl;

	system("pause");
	return 0;
}