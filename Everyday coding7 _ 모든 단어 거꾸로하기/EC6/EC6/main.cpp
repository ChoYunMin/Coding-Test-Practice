#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string inputS;
	cout << "Input: ";
	getline(cin, inputS); // ���� ���� �� �� �ٿ�ޱ�

	stringstream ss(inputS);
	vector<vector<char>> vectorS;

	string temp;
	while (ss >> temp) { // stringstream�� �̿��ؼ� ���� ������ string ������
		vector<char> vectorTemp(temp.begin(), temp.end()); // �� �ܾ��� string�� �� ���ھ� ������
		vectorS.push_back(vectorTemp);
	}

	for (int i = 0; i < vectorS.size(); i++) { // ����� ���ڵ��� �ܾ�� �Ųٷ� ���
		for (int j = vectorS[i].size() - 1; j >= 0; j--) {
			cout << vectorS[i][j];
		}
		cout << " ";
	}

	system("pause");
	return 0;
}