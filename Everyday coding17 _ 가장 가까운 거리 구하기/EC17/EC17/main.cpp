#include <iostream>
using namespace std;

int main() {
	// 가로 세로 크기 입력받아서 랜덤 맵 생성하기
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