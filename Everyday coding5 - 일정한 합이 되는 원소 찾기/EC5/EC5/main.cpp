#include <iostream>
#include <map>
using namespace std;

int main() {
	int arr_size;
	cout << "Input array size: "; // �迭 ũ�� �Է¹ޱ�
	cin >> arr_size;

	int* arr = new int[arr_size];
	cout << "Input array you want: "; // �迭 �Է¹ޱ�
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
	}

	int target;
	cout << "Inut target number: "; // Ÿ�ٰ� �Է¹ޱ�
	cin >> target;

	map<int, int> temp_arr_map; // <��, �ε���>�� �����ϴ� ������ map ����

	int count_pair = 0;
	for (int a = 0; a < arr_size; a++) { // �ð����⵵ O(n)�̹Ƿ� ���� for�� ���
		temp_arr_map.insert(make_pair(arr[a], a));
		if (temp_arr_map.find(target - arr[a]) != temp_arr_map.end()) {
			count_pair++;
			cout << "[" << temp_arr_map.find(target - arr[a])->second << ", " << a << "]" << endl;
		}
	}
	cout << "�� " << count_pair << "��" << endl;

	system("pause");
	return 0;
}