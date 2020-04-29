#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> inputArr;
	cout << "Input an integer array: ";

	do {
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

	/////

	system("pause");
	return 0;
}