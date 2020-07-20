#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> indexArray;
	cout << "Input array: ";
	do {
		int temp;
		cin >> temp;
		indexArray.push_back(temp);
	} while (getc(stdin) == ' ');

	int* check = new int[indexArray.size()];
	for (int i = 0; i < indexArray.size(); i++) {
		check[i] = 0;
	}

	int curIndex = 0;
	check[curIndex] = 1;
	while (true) {
		if (check[indexArray[curIndex]] == 0) { // �̵��Ϸ��� ��ġ�� 0���� ǥ��������� ���� �湮 ���Ѱ�!
			curIndex = indexArray[curIndex];
			check[curIndex] = 1;
		}
		else { // �̹� �湮�ߴٰ� ǥ��� ���
			break;
		}
	}

	int j;
	for (j = 0; j < indexArray.size(); j++) {
		if (check[j] == 0) {
			cout << "Output: False" << endl;
			break;
		}
	}
	if (j == indexArray.size()) { // ��� �湮 �� ���
		cout << "Output: True" << endl;
	}

	system("pause");
	return 0;
}