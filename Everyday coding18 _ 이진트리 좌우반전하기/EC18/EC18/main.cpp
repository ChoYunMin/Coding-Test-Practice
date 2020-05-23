#include <iostream>
#include "BTree.h"
using namespace std;

int main() {
	BTree<int> tree;

	int count = 0;
	cout << "Input Tree data as you want: ";
	do {
		int temp;
		cin >> temp;

		if (count == 0) {
			tree.SetRoot(temp);
			count++;
		}
		else {
			tree.InputNewData(temp, tree.GetRoot());
		}
	} while (getc(stdin) == ' ');

	cout << "<Before>" << endl;
	tree.PrintTree();

	tree.ReverseTree(tree.GetRoot());
	cout << "<After>" << endl;
	tree.PrintTree();

	system("pause");
	return 0;
}