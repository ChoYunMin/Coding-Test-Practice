#include <iostream>
using namespace std;

int main() {
	const int input[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	//const int input[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };

	int rowFirst = 0;
	int rowLast = 2;
	int colFirst = 0;
	int colLast = 2;

	int rowCur = rowFirst;
	int colCur = colFirst;
	bool right = true; // ���� ���� ���� ������
	bool down = true; // ���� ���� ���� �Ʒ���
	
	while (true) {
		cout << input[rowCur][colCur] << " ";

		if (right && colCur < colLast) { // ���������� ����
			colCur++;

			if (colCur == colLast) {
				down = true;
				rowFirst++;
			}
		}
		else if (down && rowCur < rowLast) { // �Ʒ��� ����
			rowCur++;

			if (rowCur == rowLast) {
				right = false;
				colLast--;
			}
		}
		else if (!right && colCur > colFirst) { // �������� ����
			colCur--;

			if (colCur == colFirst) {
				down = false;
				rowLast--;
			}
		}
		else if (!down && rowCur > rowFirst) { // �������� ����
			rowCur--;

			if (rowCur == rowFirst) {
				right = true;
				colFirst++;
			}
		}
		else { // ����
			break;
		}
	}

	system("pause");
	return 0;
}