#include <iostream>
using namespace std;

int main() {
	// ���� ���� ũ�� �Է¹޾Ƽ� ���� �� �����ϱ�
	int rowN, colN;
	cout << "Input row number: ";
	cin >> rowN;
	cout << "Input col number: ";
	cin >> colN;

	int** arrMap = new int*[rowN];
	for (int i = 0; i < rowN; i++) {
		arrMap[i] = new int[colN];
	}

	system("pause");
	return 0;
}