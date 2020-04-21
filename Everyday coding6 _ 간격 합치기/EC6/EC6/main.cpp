#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int count;
	cout << "How many arrays you want to input: ";
	cin >> count;
	cin.clear();

	vector<int*> interval; // [count][2] 형태의 2차원 배열에 interval 배열 저장
	for (int i = 0; i < count; i++) {
		int* input_temp = new int[2];
		cout << "Input first, second number: ";
		cin >> input_temp[0] >> input_temp[1];
		if (input_temp[0] <= input_temp[1]) { // 시작 숫자는 끝 숫자보다 작거나 같아야 한다는 조건
			int insert;
			for (insert = 0; insert < interval.size(); insert++) {
				if (interval[insert][0] > input_temp[0]) {
					break;
				}
			}
			interval.insert(interval.begin() + insert, input_temp);
		}
		else {
			cout << "You have to type second number bigger than first number." << endl;
			i--;
		}
	}

	// (a, b), (c, d)에서 더 포괄적인 범위로 넓히기 - 정렬을 통해 이미 a<=c
	vector<int*> result_interval;
	result_interval.push_back(interval[0]); // 첫 번째 결과에 넣고 시작
	for (int i = 1; i < interval.size(); i++) {
		if (result_interval.back()[1] < interval[i][0]) { // b < c
			// 겹치는 부분 하나도 없음
			result_interval.push_back(interval[i]);
		}
		else if (result_interval.back()[1] == interval[i][0]) { // b = c
			result_interval.back()[1] = interval[i][1]; // 더 큰 범위로 넓히기
		}
		else { // b > c
			// b와 d중에 더 큰 것 기준으로 범위 변경
			result_interval.back()[1] = max(result_interval.back()[1], interval[i][1]);
		}
	}

	cout << "Result: ";
	for (int i = 0; i < result_interval.size(); i++) {
		cout << "{" << result_interval[i][0] << ", " << result_interval[i][1] << "} ";
	}
	cout << endl;

	system("pause");
	return 0;
}