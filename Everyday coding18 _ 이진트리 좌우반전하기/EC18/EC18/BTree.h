#pragma once

template <typename T>
class BTree;

template <typename T>
class TreeNode {
	friend class BTree<T>;
private:
	TreeNode* left;
	T data;
	TreeNode* right;
public:
	TreeNode(T input = 0, TreeNode* left = NULL, TreeNode* right = NULL) {
		data = input;
		this->left = left;
		this->right = right;
	}
	~TreeNode() {}
};

template <typename T>
class BTree {
private:
	TreeNode<T>* root;
	void print(TreeNode<T>* node); // ��ͷ� Ʈ�� ���
public:
	BTree() {};
	~BTree() {};

	TreeNode<T>* GetRoot() { return root; }
	void SetRoot(T input) { root = new TreeNode<T>(input); return; }
	void InputNewData(T input, TreeNode<T>* node); // ��ͷ� �˸��� ��ġ ã�Ƽ� ������ �Է�
	void PrintTree(); // �ܺο��� ȣ�� ������ ��� �Լ�
	void ReverseTree(TreeNode<T>* node); // Ʈ�� �¿� ����
};

template <typename T>
void BTree<T>::InputNewData(T input, TreeNode<T>* node) {
	if (node->data >= input) {
		if (node->left == NULL) { // ������ ������� �� ��� �߰�
			node->left = new TreeNode<T>(input);
		}
		else
			InputNewData(input, node->left);
	}
	else {
		if (node->right == NULL) { // �������� ������� �� ��� �߰�
			node->right = new TreeNode<T>(input);
		}
		else
			InputNewData(input, node->right);
	}
	return;
}

template <typename T>
void BTree<T>::print(TreeNode<T>* node) {
	std::cout << node->data << " ";
	if (node->left != NULL)
		print(node->left);
	if(node->right != NULL)
		print(node->right);
	return;
}

template <typename T>
void BTree<T>::PrintTree() {
	std::cout << "���� ��ȸ (Preorder) ���: ";
	print(root);
	std::cout << std::endl;
	return;
}

template <typename T>
void BTree<T>::ReverseTree(TreeNode<T>* node) {
	if (node->left != NULL || node->right != NULL) { // ���� ������ �ϳ��� ����Ű�� ��尡 ������ �ڸ� �ٲٱ�
		TreeNode<T>* temp;
		temp = node->right;
		node->right = node->left;
		node->left = temp;
	}

	if (node->left != NULL) {
		ReverseTree(node->left);
	}
	if (node->right != NULL) {
		ReverseTree(node->right);
	}

	return;
}