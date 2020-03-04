typedef unsigned int uint;

#include "Matrix.h"
#include <iostream>
using namespace std;

double** arr;
double tempX = 0;
int m_rows;
int m_cols;
Matrix::Matrix(uint rows, uint cols) {
	m_cols = cols;
	m_rows = rows;
	arr = new double*[rows];
	for(uint i = 0; i < rows; i++) {
		arr[i] = new double[cols];
	}
}
Matrix::Matrix(double** values, int w, int h) {
	m_cols = w;
	m_rows = h;
	arr = new double*[h];
	for(int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			arr[i][j] = values[i][j];
		}
	}
}
Matrix::Matrix(const Matrix& m) {}
Matrix::~Matrix() {
	cout << "rows" << m_rows << endl;
	for (int i = 0; i < m_rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

Matrix Matrix::add(double s) const {
	/*
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = arr[i][j] + s;
		}
	}	
	*/
	return Matrix(1, 1);
}
Matrix Matrix::add(const Matrix& m) const {
	return Matrix(0, 0);	
}

Matrix Matrix::subtract(double s) const {
	return Matrix(0, 0);
}
Matrix Matrix::subtract(const Matrix& m) const {
	return Matrix(0, 0);
}

Matrix Matrix::multiply(double s) const {
	return Matrix(0, 0);
}
Matrix Matrix::multiply(const Matrix& m) const {
	return Matrix(0, 0);
}

Matrix Matrix::divide(double s) const {
	return Matrix(0, 0);
}
Matrix Matrix::t() const {
	return Matrix(0, 0);
}

const uint Matrix::numRows() const {
	return 1;
}
const uint Matrix::numCols() const {
	return 1;
}

double& Matrix::at(uint row, uint col) {
	return arr[row][col];
}
const double& Matrix::at(uint row, uint col) const {
	return arr[row][col];
}