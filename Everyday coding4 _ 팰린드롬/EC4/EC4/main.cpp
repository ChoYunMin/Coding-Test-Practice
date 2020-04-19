#include <iostream>
#include <cmath>
using namespace std;

int main() {
	bool check_integer = false;
	int input;

	while (!check_integer) {
		cout << "Input an integer: ";
		cin >> input;

		if (!cin) { // input�� ���ڰ� �ƴ� ���
			cout << "**It is not a number**" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else
			check_integer = true;
	}

	int count = 1; // ���ڸ������� Ȯ���ϱ� ���� ����
	int decimal = 10;
	// 10�� �ŵ��������� �������� ��, ���� 1���� Ŭ �� �� ���� ���ڰ� ����
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
	if (i == count / 2 && input >= 0) { // 1�ڸ����� True, ������ ������ False
		cout << "True" << endl;
	}
	else
		cout << "False" << endl;

	system("pause");
	return 0;
}