#include <iostream>
#include <map>
using namespace std;

int main() {
	int arr_size;
	cout << "Input array size: "; // 배열 크기 입력받기
	cin >> arr_size;

	int* arr = new int[arr_size];
	cout << "Input array you want: "; // 배열 입력받기
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
	}

	int target;
	cout << "Inut target number: "; // 타겟값 입력받기
	cin >> target;

	map<int, int> temp_arr_map; // <값, 인덱스>를 저장하는 형태의 map 생성

	int count_pair = 0;
	for (int a = 0; a < arr_size; a++) { // 시간복잡도 O(n)이므로 단일 for문 사용
		temp_arr_map.insert(make_pair(arr[a], a));
		if (temp_arr_map.find(target - arr[a]) != temp_arr_map.end()) {
			count_pair++;
			cout << "[" << temp_arr_map.find(target - arr[a])->second << ", " << a << "]" << endl;
		}
	}
	cout << "총 " << count_pair << "개" << endl;

	system("pause");
	return 0;
}