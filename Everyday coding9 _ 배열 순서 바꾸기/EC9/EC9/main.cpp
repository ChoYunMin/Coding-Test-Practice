#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "Input arry: ";
	vector<int> inputArr;
	do { // �� ���� ���Ұ� �Էµ� �� �𸣱� ������
		int temp;
		cin >> temp;
		inputArr.push_back(temp);
	} while (getc(stdin) == ' ');

	cout << "Original: ";
	for (int i = 0; i < inputArr.size(); i++) {
		cout << inputArr[i] << " ";
	}
	cout << endl;

	int arrSize = inputArr.size();
	for (int i = 0; i < arrSize; i++) { // 0�� ������ �ٷ� ����� �� �ڿ� �ٽ� ���� / �ε��� �ϳ��� �ٿ��ֱ�
		if (inputArr[i] == 0) {
			inputArr.erase(inputArr.begin() + i);
			inputArr.push_back(0);
			i--;
			arrSize--;
		}
	}

	cout << "Output: ";
	for (int i = 0; i < inputArr.size(); i++) {
		cout << inputArr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}