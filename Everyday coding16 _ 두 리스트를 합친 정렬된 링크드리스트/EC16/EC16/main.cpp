#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> List[2]; // list 2��
	for (int count = 0; count < 2; count++) {
		cout << "Input list" << count + 1 << ": ";
		do { // list �Է¹����鼭 �����ϱ�
			int temp;
			cin >> temp;

			if (List[count].size() == 0) {
				List[count].push_back(temp);
			}
			else {
				list<int>::iterator iter;
				iter = List[count].begin();
				for (int i = 0; i < List[count].size(); i++) {
					if (*iter > temp) {
						List[count].insert(iter, temp);
						break;
					}
					else {
						iter++;
					}
				}
				if (iter == List[count].end()) {
					List[count].push_back(temp);
				}
			}

		} while (getc(stdin) == ' ');
	}
	
	list<int>::iterator list1 = List[0].begin();
	list<int>::iterator list2 = List[1].begin();

	list<int> orderedList;
	while (1) {
		if (list1 != List[0].end() && list2 != List[1].end()) { // �� list �� �������� ���
			if (*list1 > *list2) {
				orderedList.push_back(*list2);
				list2++;
			}
			else {
				orderedList.push_back(*list1);
				list1++;
			}
		}
		else if (list1 == List[0].end() && list2 != List[1].end()) { // list2�� ������ ���
			orderedList.push_back(*list2);
			list2++;
		}
		else if (list2 == List[1].end() && list1 != List[0].end()) { // list1�� ������ ���
			orderedList.push_back(*list1);
			list1++;
		}
		else { // �� list �� ������ ���
			break;
		}
	}

	list<int>::iterator printiter = orderedList.begin();
	for (int i = 0; i < orderedList.size(); i++) {
		cout << *printiter << " ";
		printiter++;
	}
	cout << endl;

	system("pause");
	return 0;
}