#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string input1, input2;
	cout << "Input String 1: ";
	cin >> input1;
	cout << "Input String 2: ";
	cin >> input2;

	if (input1.size() != input2.size()) { // 길이가 다른 문자열이면 종료
		cout << "They have different lengths. Please try again." << endl;
		system("pause");
		return 0;
	}

	map<char, char> code;
	bool isItPossible = true;
	for (int i = 0; i < input1.size(); i++) {
		if (code.find(input1[i]) == code.end()) { // 찾는 문자가 없으면 추가
			code[input1[i]] = input2[i];
		}
		else {
			if (code.find(input1[i])->second != input2[i]) { // 찾는 문자는 있지만 암호화 문자가 다를 경우
				isItPossible = false;
				break;
			}
		}
	}

	if (isItPossible)
		cout << "Output: True" << endl;
	else
		cout << "Output: False" << endl;

	system("pause");
	return 0;
}