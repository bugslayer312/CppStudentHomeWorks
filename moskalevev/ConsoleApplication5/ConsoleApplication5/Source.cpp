#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
	int **a;

	int rows = 3;
	int cols = 4;
	int q = 1000000000;
	cout << "HEllo\n";

	a = new int*[rows]; // ������ ���������� 

	for (int i = 0; i < rows; i++) {
		a[i] = new int[cols]; // ������ ���������
	}

	int u = 1; // ���������� � ��� ������� ��������
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			a[i][j] = u++;
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}

	for (int i = 0; i < rows; i++) {
		delete a[i]; // ����������� ���������
	}

	delete a;


	a = new int*[rows]; // 8
	a[0] = new int[rows*cols];
	a[1] = a[0] + cols;
	a[2] = a[1] + cols;

	// ������ ���������� ���� ��������

	delete a[0];
	delete a;


	return 0;
}