#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> inputArr;
	cout << "Input an integer array: ";

	do { // 원하는 만큼 배열 입력받기
		int temp;
		cin >> temp;
		inputArr.push_back(temp);
	} while (getc(stdin) == ' ');

	int N;
	cout << "Input an integer N: "; 
	cin >> N;
	if (N > inputArr.size()) {
		cout << "You wrote a wrong number. Please try again." << endl;
		system("pause");
		return 0;
	}

	sort(inputArr.begin(), inputArr.end()); // 정렬 (오름차순 기본)
	cout << "Output: " << inputArr[inputArr.size() - N] << endl;

	system("pause");
	return 0;
}