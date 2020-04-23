#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "Input array: ";
	vector<int> vectorArr;

	do { // 몇 개 입력받을 지 모르는 상태이므로 ' '를 만날때까지 읽기
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
		if (vectorArr[i] >= first) { // 가장 큰 수 발견하면 제일 큰 수->두번째 큰 수 변경 후 제일 큰 수 갱신
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