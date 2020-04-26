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
				// �ߺ��� Char �߰�
				maximum = max(last - first + 1, maximum); // ������� ���� �� ���꽺Ʈ�� ����
				first = j+1; // ��ġ�� char �ٷ� �������� �ٽ� ���꽺Ʈ�� ī��Ʈ
				last = i; // last�� �������
				break;
			}
		}
		
		if(j > last) // ��ġ�� �κ��� ���� ��� for���� ������ ���� ������ �������� last+1
			last++;
	}
	maximum = max(last - first + 1, maximum);

	cout << "Output: " << maximum << endl;

	system("pause");
	return 0;
}