#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> pibo;
	pibo.push_back(0);
	pibo.push_back(1);

	int input_num;
	cout << "Input: ";
	cin >> input_num;

	int i;
	for (i = 0; i < pibo.size() - 1; i++) {
		if (pibo[pibo.size() - 1] < input_num) {
			pibo.push_back(pibo[i] + pibo[i + 1]);
		}
		else {
			break;
		}
	}

	cout << "Pibo, smaller than input number" << endl;
	int sum = 0;
	for (int j = 0; j <= i; j++) {
		cout << pibo[j] << " ";
		if (pibo[j] % 2 == 0) {
			sum += pibo[j];
		}
	}
	cout << endl;
	cout << "Summerize all even numbers: " << sum << endl;

	system("pause");
	return 0;
}