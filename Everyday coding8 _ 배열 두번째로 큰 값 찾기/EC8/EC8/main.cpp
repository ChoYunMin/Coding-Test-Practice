#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "Input array: ";
	vector<int> vectorArr;

	do { // �� �� �Է¹��� �� �𸣴� �����̹Ƿ� ' '�� ���������� �б�
		int temp;
		cin >> temp;
		vectorArr.push_back(temp);

	} while (getc(stdin) == ' ');
	
	int first, second;
	if (vectorArr[0] > vectorArr[1]) {
		first = vectorArr[0];
		second = vectorArr[1];
	}
	else {
		first = vectorArr[1];
		second = vectorArr[0];
	}

	for (int i = 1; i < vectorArr.size(); i++) {
		if (vectorArr[i] >= first) { // ���� ū �� �߰��ϸ� ���� ū ��->�ι�° ū �� ���� �� ���� ū �� ����
			second = first;
			first = vectorArr[i];
		}
		else if (vectorArr[i] < first && vectorArr[i] >= second) {
			second = vectorArr[i];
		}
	}
	cout << "Output: " << second << endl;

	system("pause");
	return 0;
}