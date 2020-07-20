#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &inputA, int left, int right);

int main() {
	vector<int> inputArray;

	cout << "Input array: ";
	do {
		int temp;
		cin >> temp;
		inputArray.push_back(temp);
	} while (getc(stdin) == ' ');

	// 시간복잡도 O(n log n) -> 합병 정렬
	mergeSort(inputArray, 0, inputArray.size() - 1);

	cout << "Output: ";
	for (int i = 0; i < inputArray.size(); i++) {
		cout << inputArray[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void merge(vector<int> &inputA, int left, int mid, int right) {
	vector<int> leftArray;
	for (int a = left; a <= mid; a++) {
		leftArray.push_back(inputA[a]);
	}

	vector<int> rightArray;
	for (int b = mid + 1; b <= right; b++) {
		rightArray.push_back(inputA[b]);
	}

	int i = 0, j = 0, k = left;
	int leftL = mid - left + 1;
	int rightL = right - mid;

	while (i < leftL && j < rightL) {
		if (leftArray[i] < rightArray[j]) {
			inputA[k] = leftArray[i++];
		}
		else {
			inputA[k] = rightArray[j++];
		}
		k++;
	}

	while (i < leftL) {
		inputA[k++] = leftArray[i++];
	}

	while (j < rightL) {
		inputA[k++] = rightArray[j++];
	}

	return;
}

void mergeSort(vector<int> &inputA, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSort(inputA, left, mid);
		mergeSort(inputA, mid + 1, right);
		merge(inputA, left, mid, right);
	}

	return;
}