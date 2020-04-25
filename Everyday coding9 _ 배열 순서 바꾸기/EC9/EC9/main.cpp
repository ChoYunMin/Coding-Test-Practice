#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "Input arry: ";
	vector<int> inputArr;
	do { // 몇 개의 원소가 입력될 지 모르기 때문에
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
	for (int i = 0; i < arrSize; i++) { // 0이 나오면 바로 지우고 맨 뒤에 다시 삽입 / 인덱스 하나씩 줄여주기
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