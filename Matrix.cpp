typedef unsigned int uint;

#include "Matrix.h"

double** arr;
double tempX = 0;
Matrix::Matrix(uint rows, uint cols) {
	arr = new double*[rows];
	for(uint i = 0; i < rows; i++) {
		arr[i] = new double[cols];
	}
}
Matrix::Matrix(double** values, int w, int h) {
	arr = new double*[w];
	for(int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			arr[i][j] = values[i][j];
		}
	}
}
Matrix::Matrix(const Matrix& m) {}
Matrix::~Matrix() {
	delete arr;
}

Matrix Matrix::add(double s) const {
	return Matrix(0, 0);
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
	return tempX;
}