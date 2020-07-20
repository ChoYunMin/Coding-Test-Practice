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
		if (check[indexArray[curIndex]] == 0) { // 이동하려는 위치가 0으로 표기되있으면 아직 방문 안한것!
			curIndex = indexArray[curIndex];
			check[curIndex] = 1;
		}
		else { // 이미 방문했다고 표기된 경우
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
	if (j == indexArray.size()) { // 모두 방문 한 경우
		cout << "Output: True" << endl;
	}

	system("pause");
	return 0;
}