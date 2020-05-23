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
	void print(TreeNode<T>* node); // 재귀로 트리 출력
public:
	BTree() {};
	~BTree() {};

	TreeNode<T>* GetRoot() { return root; }
	void SetRoot(T input) { root = new TreeNode<T>(input); return; }
	void InputNewData(T input, TreeNode<T>* node); // 재귀로 알맞은 위치 찾아서 데이터 입력
	void PrintTree(); // 외부에서 호출 가능한 출력 함수
	void ReverseTree(TreeNode<T>* node); // 트리 좌우 반전
};

template <typename T>
void BTree<T>::InputNewData(T input, TreeNode<T>* node) {
	if (node->data >= input) {
		if (node->left == NULL) { // 왼쪽이 비었으면 새 노드 추가
			node->left = new TreeNode<T>(input);
		}
		else
			InputNewData(input, node->left);
	}
	else {
		if (node->right == NULL) { // 오른쪽이 비었으면 새 노드 추가
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
	std::cout << "전위 순회 (Preorder) 출력: ";
	print(root);
	std::cout << std::endl;
	return;
}

template <typename T>
void BTree<T>::ReverseTree(TreeNode<T>* node) {
	if (node->left != NULL || node->right != NULL) { // 왼쪽 오른쪽 하나라도 가리키는 노드가 있으면 자리 바꾸기
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