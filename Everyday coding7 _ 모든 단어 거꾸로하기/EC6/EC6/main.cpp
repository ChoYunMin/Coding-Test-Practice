#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string inputS;
	cout << "Input: ";
	getline(cin, inputS); // 공백 없이 한 줄 다운받기

	stringstream ss(inputS);
	vector<vector<char>> vectorS;

	string temp;
	while (ss >> temp) { // stringstream을 이용해서 공백 단위로 string 나누기
		vector<char> vectorTemp(temp.begin(), temp.end()); // 한 단어의 string을 한 문자씩 나누기
		vectorS.push_back(vectorTemp);
	}

	for (int i = 0; i < vectorS.size(); i++) { // 저장된 문자들을 단어별로 거꾸로 출력
		for (int j = vectorS[i].size() - 1; j >= 0; j--) {
			cout << vectorS[i][j];
		}
		cout << " ";
	}

	system("pause");
	return 0;
}