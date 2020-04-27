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
			// map�� ��ġ�� ���ڰ� ���� ���
			subString[inputString[i]] = i;
		}
		else {
			// ��ġ�� ���ڰ� ���� ���
			if (subString[inputString[i]] >= first) { // ���� substring �ȿ� ���ԵǴ� ��������
				maximum = max(i - first, maximum); // ���� �� substring ���� ����
				first = subString[inputString[i]] + 1;
			}

			subString[inputString[i]] = i; // ���� �ֱ� �ε����� ����
		}
	}

	maximum = max((int)inputString.size() - first, maximum); // ���� �� substring ���� ����

	cout << "Output: " << maximum << endl;

	system("pause");
	return 0;
}