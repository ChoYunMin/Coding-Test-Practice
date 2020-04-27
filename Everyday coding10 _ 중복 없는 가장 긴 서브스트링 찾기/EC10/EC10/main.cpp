#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	cout << "Input: ";
	string inputString;
	cin >> inputString;

	int first = 0;
	int last = 0;
	int maximum = 1;
	map<char, int> subString;
	for (int i = 0; i < inputString.size(); i++) {
		if (subString.find(inputString[i]) == subString.end()) { 
			// map에 겹치는 문자가 없을 경우
			subString[inputString[i]] = i;
		}
		else {
			// 겹치는 문자가 있을 경우
			if (subString[inputString[i]] >= first) { // 현재 substring 안에 포함되는 문자인지
				maximum = max(i - first, maximum); // 가장 긴 substring 길이 갱신
				first = subString[inputString[i]] + 1;
			}

			subString[inputString[i]] = i; // 가장 최근 인덱스로 변경
		}
	}

	maximum = max((int)inputString.size() - first, maximum); // 가장 긴 substring 길이 갱신

	cout << "Output: " << maximum << endl;

	system("pause");
	return 0;
}