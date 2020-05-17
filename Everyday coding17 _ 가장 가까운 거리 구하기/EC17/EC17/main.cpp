#include <iostream>
#include <ctime>
#include <stack>
using namespace std;

float fnDistance(int sx, int sy, int fx, int fy);

int main() {
	// ���� ���� ũ�� �Է¹޾Ƽ� ���� �� �����ϱ�
	int rowN, colN;
	cout << "Input row number: ";
	cin >> rowN;
	cout << "Input col number: ";
	cin >> colN;

	srand(time(NULL));
	int** arrMap = new int*[rowN]; // �� ����
	int** arrTemp = new int*[rowN]; // ������ �� Ȯ�ο�
	for (int i = 0; i < rowN; i++) {
		arrMap[i] = new int[colN];
		arrTemp[i] = new int[colN];
		for (int j = 0; j < colN; j++) {
			arrMap[i][j] = rand() % 2;
			arrTemp[i][j] = 0;
		}
	}

	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			cout << arrMap[i][j] << " ";
		}
		cout << endl;
	}

	int startX, startY;
	int finishX, finishY;
	while (true) {
		cout << "Start row col number: ";
		cin >> startY >> startX;
		if (arrMap[startY][startX] != 1) {
			cout << "You can choose only 1 position." << endl;
		}
		else
			break;
	}
	while (true) {
		cout << "Finish row col number: ";
		cin >> finishY >> finishX;
		if (arrMap[finishY][finishX] != 1) {
			cout << "You can choose only 1 position.: " << endl;
		}
		else
			break;
	}
 	
	stack<int*> pastRoad;
	int start[2] = { startX, startY };
	pastRoad.push(start);
	arrTemp[startY][startX] = 1;

	while (pastRoad.size() > 0) {
		int* current = pastRoad.top(); // ���� ��ǥ

		if (current[0] == finishX && current[1] == finishY) // ���� ã�� ���
			break;

		float distance[4] = { -1, -1, -1, -1 };
		if (current[1] != 0 && arrMap[current[1]-1][current[0]] == 1) { // �� ���� Ȯ��
			distance[0] = fnDistance(current[0], current[1] - 1, finishX, finishY);

			if (arrTemp[current[1] - 1][current[0]] == 1) // �ٷ� ���� ������ ���̸�
				distance[0] = -1;
		}

		if (current[0] != colN - 1 && arrMap[current[1]][current[0] + 1] == 1) { // ������ ���� Ȯ��
			distance[1] = fnDistance(current[0] + 1, current[1], finishX, finishY);

			if (arrTemp[current[1]][current[0] + 1] == 1) // �ٷ� ���� ������ ���̸�
				distance[1] = -1;
		}

		if (current[1] != rowN - 1 && arrMap[current[1] + 1][current[0]] == 1) { // ���� ���� Ȯ��
			distance[2] = fnDistance(current[0], current[1] + 1, finishX, finishY);

			if (arrTemp[current[1] + 1][current[0]] == 1) // �ٷ� ���� ������ ���̸�
				distance[2] = -1;
		}

		if (current[0] != 0 && arrMap[current[1]][current[0] - 1] == 1) { // �Ʒ��� ���� Ȯ��
			distance[3] = fnDistance(current[0] - 1, current[1], finishX, finishY);

			if (arrTemp[current[1]][current[0] - 1] == 1) // �ٷ� ���� ������ ���̸�
				distance[3] = -1;
		}

		int minIndex = -1;
		for (int i = 0; i < 4; i++) {
			if (distance[i] != -1) {
				if (minIndex == -1) {
					minIndex = i;
				}
				else {
					if (distance[minIndex] > distance[i]) {
						minIndex = i;
					}
				}
			}
		}

		if (minIndex == -1) { // ���� ����
			pastRoad.pop();
			continue;
		}

		int newRoad[2];
		switch (minIndex) {
		case 0: 
			newRoad[0] = current[0]; newRoad[1] = current[1] - 1;
			break;
		case 1: 
			newRoad[0] = current[0] + 1; newRoad[1] = current[1];
			break;
		case 2: 
			newRoad[0] = current[0]; newRoad[1] = current[1] + 1;
			break;
		case 3: 
			newRoad[0] = current[0] - 1; newRoad[1] = current[1];
			break;
		default: 
			break;
		}
		arrTemp[newRoad[1]][newRoad[0]] = 1; // ������ �� ǥ��
		pastRoad.push(newRoad);
	}

	if (pastRoad.size() == 0)
		cout << endl << "Output: No road connected" << endl; // �� ����
	else
		cout << endl << "Output: " << pastRoad.size() - 1 << endl;

	system("pause");
	return 0;
}

float fnDistance(int sx, int sy, int fx, int fy) {
	return sqrt(pow(fy-sy, 2) + pow(fx-sx, 2));
}
