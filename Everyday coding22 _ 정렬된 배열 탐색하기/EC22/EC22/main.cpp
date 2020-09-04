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

	// 정렬된 배열의 탐색 알고리즘 - 이분검색
	cout << "Input key number you want to find: ";
	int key;
	cin >> key;

	int mid = inputArray.size() / 2;
	int low = 0; int high = inputArray.size() - 1;
	int resultIndex = -1; // key값이 담긴 index를 저장할 변수 -> 끝까지 찾지 못하면 -1
	while (low <= high)
	{
		if (key > inputArray[mid]) { // key가 중간보다 크면
			low = mid + 1;
		}
		else if (key < inputArray[mid]) { // key가 중간보다 작으면
			high = mid - 1;
		}
		else { // 중간이 key값이면
			resultIndex = mid;
			break;
		}
		mid = (low + high) / 2;
	}

	if (resultIndex == -1) { // 배열에서 찾지 못한경우
		cout << "Output: false" << endl;
	}
	else {
		cout << "Output: true" << endl;
		cout << "Index: " << resultIndex << endl;
	}

	system("pause");
	return 0;
}