// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
#include <ctime>
using namespace std;

void vec_random_fill(TDynamicVector<double>& vec)
{
	
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = rand() % 100;
	}
}

void matrix_random_fill(TDynamicMatrix<double>& m)
{	
	srand(time(NULL));
	for (int i = 0; i < m.size(); i++) {
		vec_random_fill(m[i]);
	}
}

void fill(TDynamicMatrix<double>& m)
{
	cin >> m;
}


void main()
{
	TDynamicMatrix<double> mat(2);
	int choose;
	enum operations {
		ADD_MATRICES = 1,
		SUBTRACT_MATRICES,
		MULTIPLY_MATRIX_AND_SCALAR,
		MULTIPLY_MATRIX_AND_VECTOR,
		MULTIPLY_MATRICES
		
		
	};
	setlocale(LC_ALL, "Russian");
	cout << "выберете тип заполнения" << endl;
	cout << "1 - случайное заполнение" << endl;
	cout << "2 - ручное заполнение" << endl;
	cin >> choose;
	if (choose == 1) {
		matrix_random_fill(mat);
	}
	else if (choose == 2) {
		fill(mat);
	}
	else {
		throw exception("неверный тип заполния");
	}
	cout << mat << endl;
	cout << "выберете операцию" << endl;
	cout << "1 - сложение матриц" << endl;
	cout << "2 - разность матриц" << endl;
	cout << "3 - умножение матрицы на скаляр" << endl;
	cout << "4 - умножение матрицы на вектор" << endl;
	cout << "5 - матричное умножение" << endl;
	cin >> choose;
	switch(choose)
	{
	case ADD_MATRICES:
	{
		TDynamicMatrix<double> a(mat.size());
		matrix_random_fill(a);
		cout << "вторая матрица:" << endl;
		cout << a << endl;
		cout << "сумма матриц:" << endl;
		cout << a + mat << endl;
		break;
	}
	case SUBTRACT_MATRICES:
	{

	
		TDynamicMatrix<double> a(mat.size());
		matrix_random_fill(a);
		cout << "вторая матрица:" << endl;
		cout << a << endl;
		cout << "сумма матриц:" << endl;
		cout << mat -a << endl;
		break;
	}
	case MULTIPLY_MATRIX_AND_SCALAR:
	{
		double scal;
		srand(time(NULL));
		scal = rand() & 100;
		cout << "скаляр:" << endl;
		cout << scal << endl;
		cout << "произведение матрицы на скаляр:" << endl;
		cout << mat * scal << endl;
		break;
	}
	case MULTIPLY_MATRIX_AND_VECTOR:
	{
		TDynamicVector<double> vec(mat.size());
		vec_random_fill(vec);
		cout << "вектор" << endl;
		cout << vec << endl;
		cout << "произведение матрицы на вектор" << endl;
		cout << mat * vec << endl;
		break;
	}
	case MULTIPLY_MATRICES:
	{
		TDynamicMatrix<double> b(mat.size());
		matrix_random_fill(b);
		cout << "вторая матрица" << endl;
		cout << b << endl;
		cout << "матричное произвдение" << endl;
		cout << mat * b << endl;
		break;
	}
	default:
	{
		cout << "неверная операция" << endl;
		break;
	}
	}
	

















}