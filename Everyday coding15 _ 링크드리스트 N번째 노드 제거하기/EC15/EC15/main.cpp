#include <iostream>
using namespace std;

class List {
private: 
	int node;
	List* next;
public:
	List() {
		next = NULL;
	}
	~List() {
		delete next;
	}

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

	List* head;
	List* listPtr;
	head = listPtr;
	do {
		int temp;
		cin >> temp;
		
		List list;
		list.setNode(temp);
		listPtr->setNext(&list);
		listPtr = listPtr->getNext();

	} while (getc(stdin) == ' ');

	cout << "Input N: ";
	int Nth;
	cin >> Nth;

	system("pause");
	return 0;
}