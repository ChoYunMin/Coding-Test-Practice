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

	if (input1.size() != input2.size()) { // ���̰� �ٸ� ���ڿ��̸� ����
		cout << "They have different lengths. Please try again." << endl;
		system("pause");
		return 0;
	}

	map<char, char> code;
	bool isItPossible = true;
	for (int i = 0; i < input1.size(); i++) {
		if (code.find(input1[i]) == code.end()) { // ã�� ���ڰ� ������ �߰�
			code[input1[i]] = input2[i];
		}
		else {
			if (code.find(input1[i])->second != input2[i]) { // ã�� ���ڴ� ������ ��ȣȭ ���ڰ� �ٸ� ���
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