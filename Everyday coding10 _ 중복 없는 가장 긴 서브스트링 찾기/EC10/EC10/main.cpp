#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cout << "Input: ";
	string inputString;
	cin >> inputString;

	int first = 0;
	int last = 0;
	int maximum = 1;
	for (int i = 1; i < inputString.size(); i++) {
		int j;
		for (j = first; j <= last; j++) {
			if (inputString[j] == inputString[i]) {
				// 중복된 Char 발견
				maximum = max(last - first + 1, maximum); // 현재까지 가장 긴 서브스트링 저장
				first = j+1; // 겹치는 char 바로 다음부터 다시 서브스트링 카운트
				last = i; // last는 현재까지
				break;
			}
		}
		
		if(j > last) // 겹치는 부분이 없을 경우 for문을 끝까지 돌기 때문에 마지막은 last+1
			last++;
	}
	maximum = max(last - first + 1, maximum);

	cout << "Output: " << maximum << endl;

	system("pause");
	return 0;
}