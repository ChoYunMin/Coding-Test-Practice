#include <iostream>
using namespace std;

int Total_count = 0;
//void fnRecur(char* arr, int count, int first, int last, bool check);
void Print_Paren(int* arr, int arr_size);
void Paren(int* arr, int arr_size, int open_paren, int close_paren);

int main() {
	int n_num;
	cout << "input number: ";
	cin >> n_num; // 최대 n_num개 '(' 연속 가능

	/* // 잘못 생각한 알고리즘
	char* chr_arr = new char[n_num * 2 + 1];
	chr_arr[n_num * 2] = '\0';
	fnRecur(chr_arr, n_num, 0, n_num * 2 - 1, false);
	cout << "total: " << Total_count << endl;
	*/

	int* int_arr = new int[n_num * 2];
	Paren(int_arr, 0, n_num, 0);
	cout << "total: " << Total_count << endl;

	system("pause");
	return 0;
}

/* // 잘못 생각한 알고리즘 - 빠지는 경우가 생김
void fnRecur(char* arr, int count, int first, int last, bool check) {
	if (count > 2) {
		//1번 케이스
		if (!check) {
			arr[last - 1] = '(';
			arr[last] = ')';
			fnRecur(arr, count - 1, first, last - 2, false);
		}

		//2번 케이스
		arr[first] = '(';
		arr[last] = ')';
		fnRecur(arr, count - 1, first + 1, last - 1, false);

		//3번 케이스
		arr[first] = '(';
		arr[first + 1] = ')';
		fnRecur(arr, count - 1, first + 2, last, true);
		return;
	}
	else if (count == 2) {
		//1번 케이스
		if (!check) {
			arr[last - 1] = '(';
			arr[last] = ')';
			fnRecur(arr, count - 1, first, last - 2, false);
		}

		//2번 케이스
		arr[first] = '(';
		arr[last] = ')';
		fnRecur(arr, count - 1, first + 1, last - 1, false);
		return;
	}
	else {
		arr[first] = '(';
		arr[last] = ')';
		cout << arr << endl;
		Total_count++;
		return;
	}
}
*/

void Print_Paren(int* arr, int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == 0)
			cout << "(";
		else
			cout << ")";
	}
	cout << endl;
}

void Paren(int* arr, int arr_size, int open_paren, int close_paren) {
	if (open_paren == 0 && close_paren == 0) {
		Print_Paren(arr, arr_size);
		Total_count++;
		return;
	}

	if (open_paren > 0) {
		arr[arr_size] = 0;
		Paren(arr, arr_size + 1, open_paren - 1, close_paren + 1);
	}
	if (close_paren > 0) {
		arr[arr_size] = 1;
		Paren(arr, arr_size + 1, open_paren, close_paren - 1);
	}
}