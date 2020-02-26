typedef unsigned int uint;

#include "Matrix.h"

double** arr;
double tempX = 0;
Matrix::Matrix(uint rows, uint cols) {}
Matrix::Matrix(double** values, int w, int h) {}
Matrix::Matrix(const Matrix& m) {}
Matrix::~Matrix() {}

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
	return tempX;
}
const double& Matrix::at(uint row, uint col) const {
	return tempX;
}