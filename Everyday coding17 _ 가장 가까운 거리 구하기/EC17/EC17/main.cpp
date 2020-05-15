#include <iostream>
#include <ctime>
using namespace std;

int main() {
	// 가로 세로 크기 입력받아서 랜덤 맵 생성하기
	int rowN, colN;
	cout << "Input row number: ";
	cin >> rowN;
	cout << "Input col number: ";
	cin >> colN;

	srand(time(NULL));
	int** arrMap = new int*[rowN];
	for (int i = 0; i < rowN; i++) {
		arrMap[i] = new int[colN];
		for (int j = 0; j < colN; j++) {
			arrMap[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			cout << arrMap[i][j] << " ";
		}
		cout << endl;
	}

	while (true) {
		cout << "Start row col number: ";
		int startX, startY;
		cin >> startY >> startX;
		if (arrMap[startY][startX] != 1) {
			cout << "You can choose only 1 position." << endl;
		}
		else
			break;
	}
	while (true) {
		cout << "Finish row col number: ";
		int finishX, finishY;
		cin >> finishY >> finishX;
		if (arrMap[finishY][finishX] != 1) {
			cout << "You can choose only 1 position.: " << endl;
		}
		else
			break;
	}
 	


	system("pause");
	return 0;
}