#include"Matrix.h"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	Matrix<int> mat1(2, 2);
	Matrix<int> mat2(2, 2);
	mat1.random();
	mat2.random();
	
	cout << "������� 1:" << '\n';
	mat1.display();
	cout << "������� 2:" << '\n';
	mat2.display();

	Matrix<int> mat3 = mat1 + mat2;
	cout << "������� 3:" << '\n'; // ����� 1 � 2 �������
	mat3.display();

	cout << "Max element in Matrix 1: " << mat1.max() <<  '\n' << "Min element in Matrix 2: " << mat2.min();
}