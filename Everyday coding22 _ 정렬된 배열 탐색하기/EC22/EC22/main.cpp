#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> inputArray;
	cout << "Input sorted array: ";
	do {
		int temp;
		cin >> temp;
		inputArray.push_back(temp);
	} while (getc(stdin) == ' ');

	// ���ĵ� �迭�� Ž�� �˰��� - �̺а˻�
	cout << "Input key number you want to find: ";
	int key;
	cin >> key;

	int mid = inputArray.size() / 2;
	int low = 0; int high = inputArray.size() - 1;
	int resultIndex = -1; // key���� ��� index�� ������ ���� -> ������ ã�� ���ϸ� -1
	while (low <= high)
	{
		if (key > inputArray[mid]) { // key�� �߰����� ũ��
			low = mid + 1;
		}
		else if (key < inputArray[mid]) { // key�� �߰����� ������
			high = mid - 1;
		}
		else { // �߰��� key���̸�
			resultIndex = mid;
			break;
		}
		mid = (low + high) / 2;
	}

	if (resultIndex == -1) { // �迭���� ã�� ���Ѱ��
		cout << "Output: false" << endl;
	}
	else {
		cout << "Output: true" << endl;
		cout << "Index: " << resultIndex << endl;
	}

	system("pause");
	return 0;
}