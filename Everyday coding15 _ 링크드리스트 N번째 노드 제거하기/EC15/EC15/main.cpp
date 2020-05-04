#include <iostream>
using namespace std;

class List { // ��ũ�帮��Ʈ class ����
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
	do { // ���ϴ� ��ŭ �Է¹ޱ�
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
	while (true) { // ������ �´� N�� �Էµ� �� ���� �ݺ�
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
	
	int inverseNth = listCount + 1 - Nth; // �տ��� �� ��°�� �ٲ��ֱ�
	listPtr = head;
	for (int i = 1; i <= listCount; i++) {
		if (inverseNth == i) {
			List* tempPtr;
			tempPtr = listPtr->getNext(); // tempPtr: ������� �ϴ� ���, listPtr: ������� �ϴ� �� �ٷ� �� ���
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
	if (listCount == 1) { // list�� 1������ ��� �����ִ� ���� �����Ƿ�
		cout << "null";
	}
	cout << endl;

	system("pause");
	return 0;
}