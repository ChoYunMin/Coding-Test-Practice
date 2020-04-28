#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> inputArr; // ����
	cout << "Input array: ";
	do { // ���ϴ� ��ŭ�� ���� vector�� �־��ֱ�
		int temp;
		cin >> temp;
		inputArr.push_back(temp);
	} while (getc(stdin) == ' ');
	// ex) input: a b c d

	int* preArr = new int[inputArr.size()];
	int* afterArr = new int[inputArr.size()];

	preArr[0] = 1; 
	for (int i = 1; i < inputArr.size(); i++) {
		preArr[i] = preArr[i - 1] * inputArr[i - 1];
	} // preArr: 1 a ab abc

	afterArr[inputArr.size() - 1] = 1;
	for (int i = inputArr.size() - 2; i >= 0; i--) {
		afterArr[i] = afterArr[i + 1] * inputArr[i + 1];
	} // afterArr: bcd cd d 1

	// �� �迭�� ���ϱ�
	cout << "Output: ";
	for (int i = 0; i < inputArr.size(); i++) {
		cout << preArr[i] * afterArr[i] << " ";
	} // Output: bcd acd abd abc
	cout << endl;

	system("pause");
	return 0;
}