#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int count;
	cout << "How many arrays you want to input: ";
	cin >> count;
	cin.clear();

	vector<int*> interval; // [count][2] ������ 2���� �迭�� interval �迭 ����
	for (int i = 0; i < count; i++) {
		int* input_temp = new int[2];
		cout << "Input first, second number: ";
		cin >> input_temp[0] >> input_temp[1];
		if (input_temp[0] <= input_temp[1]) { // ���� ���ڴ� �� ���ں��� �۰ų� ���ƾ� �Ѵٴ� ����
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

	// (a, b), (c, d)���� �� �������� ������ ������ - ������ ���� �̹� a<=c
	vector<int*> result_interval;
	result_interval.push_back(interval[0]); // ù ��° ����� �ְ� ����
	for (int i = 1; i < interval.size(); i++) {
		if (result_interval.back()[1] < interval[i][0]) { // b < c
			// ��ġ�� �κ� �ϳ��� ����
			result_interval.push_back(interval[i]);
		}
		else if (result_interval.back()[1] == interval[i][0]) { // b = c
			result_interval.back()[1] = interval[i][1]; // �� ū ������ ������
		}
		else { // b > c
			// b�� d�߿� �� ū �� �������� ���� ����
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