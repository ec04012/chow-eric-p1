typedef unsigned int uint;

#include "Matrix.h"
#include <iostream>
using namespace std;

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

Matrix::Matrix(const Matrix& m) {
    m_cols = m.m_cols;
	m_rows = m.m_rows;
	arr = new double*[m_rows];
    for (int i = 0; i < m.m_rows; i++) {
        arr[i] = new double[m_cols];
        for (int j = 0; j < m.m_cols; j++) {
            arr[i][j] = m.at(i, j);
        }
    }
}

Matrix::~Matrix() {
	cout << "rows" << m_rows << endl;
	for (int i = 0; i < m_rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

Matrix Matrix::add(double s) const {
    Matrix temp (m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] + s;
        }
    }
    return temp;
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
	return m_rows;
}
const uint Matrix::numCols() const {
	return m_cols;
}

double& Matrix::at(uint row, uint col) {
	return arr[row][col];
}
const double& Matrix::at(uint row, uint col) const {
	return arr[row][col];
}
