#include <iostream>
#include <cmath>
using namespace std;

int main() {
	bool check_integer = false;
	int input;

	while (!check_integer) {
		cout << "Input an integer: ";
		cin >> input;

		if (!cin) { // input이 숫자가 아닐 경우
			cout << "**It is not a number**" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else
			check_integer = true;
	}

	int count = 1; // 몇자리수인지 확인하기 위한 변수
	int decimal = 10;
	// 10의 거듭제곱으로 나누었을 때, 몫이 1보다 클 때 더 읽을 숫자가 있음
	while (input / decimal > 0) {
		count++;
		decimal *= 10;
	}
	
	int i;
	decimal = 10;
	for (i = 0; i < count / 2; i++) {
		if (input % (int)pow(decimal, i) != input % (int)pow(decimal, count - i)) {
			break;
		}
	}
	if (i == count / 2 && input >= 0) { // 1자리수라도 True, 하지만 음수는 False
		cout << "True" << endl;
	}
	else
		cout << "False" << endl;

	system("pause");
	return 0;
}