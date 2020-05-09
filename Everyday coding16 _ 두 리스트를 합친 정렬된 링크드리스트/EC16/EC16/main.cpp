#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> List[2]; // list 2개
	for (int count = 0; count < 2; count++) {
		cout << "Input list" << count + 1 << ": ";
		do { // list 입력받으면서 정렬하기
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
		if (list1 != List[0].end() && list2 != List[1].end()) { // 두 list 다 남아있을 경우
			if (*list1 > *list2) {
				orderedList.push_back(*list2);
				list2++;
			}
			else {
				orderedList.push_back(*list1);
				list1++;
			}
		}
		else if (list1 == List[0].end() && list2 != List[1].end()) { // list2만 남았을 경우
			orderedList.push_back(*list2);
			list2++;
		}
		else if (list2 == List[1].end() && list1 != List[0].end()) { // list1만 남았을 경우
			orderedList.push_back(*list1);
			list1++;
		}
		else { // 두 list 다 끝났을 경우
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