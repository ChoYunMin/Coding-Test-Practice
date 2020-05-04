#include <iostream>
using namespace std;

class List { // 링크드리스트 class 선언
private: 
	int node;
	List* next;
public:
	List() {
		next = NULL;
	}
	~List() {}

	void setNode(int num) {
		node = num;
	}

	int getNode() {
		return node;
	}

	void setNext(List* ptr) {
		next = ptr;
	}

	List* getNext() {
		return next;
	}
};

int main() {
	cout << "Input linked list numbers: ";

	List* head = new List();
	List* listPtr = NULL;
	int listCount = 0;
	do { // 원하는 만큼 입력받기
		int temp;
		cin >> temp;
		
		List* list = new List();
		list->setNode(temp);
		listCount++;

		if (listCount == 1) {
			head->setNext(list);
			listPtr = list;
		}
		else {
			listPtr->setNext(list);
			listPtr = list;
		}
	} while (getc(stdin) == ' ');

	int Nth;
	while (true) { // 범위에 맞는 N이 입력될 때 까지 반복
		cout << "Input N: ";
		cin >> Nth;
		if (Nth > listCount) {
			cout << "N must be smaller than list size. Please try again." << endl;
		}
		else if (Nth <= 0) {
			cout << "N must be bigger than 0. Please try again." << endl;
		}
		else
			break;
	}
	
	int inverseNth = listCount + 1 - Nth; // 앞에서 몇 번째로 바꿔주기
	listPtr = head;
	for (int i = 1; i <= listCount; i++) {
		if (inverseNth == i) {
			List* tempPtr;
			tempPtr = listPtr->getNext(); // tempPtr: 지우고자 하는 노드, listPtr: 지우고자 하는 것 바로 전 노드
			if (tempPtr->getNext() != NULL) {
				listPtr->setNext(listPtr->getNext()->getNext());
				delete tempPtr;
			}
			else {
				listPtr->setNext(NULL);
				delete tempPtr;
			}
		}
		else {
			cout << listPtr->getNext()->getNode() << " ";
			listPtr = listPtr->getNext();
		}
	}
	if (listCount == 1) { // list가 1개였을 경우 남아있는 것이 없으므로
		cout << "null";
	}
	cout << endl;

	system("pause");
	return 0;
}