typedef unsigned int uint;

#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

Matrix::Matrix(uint rows, uint cols) {
	m_cols = cols;
	m_rows = rows;
	arr = new double*[rows];
	for(uint i = 0; i < rows; i++) {
		arr[i] = new double[cols];
        for (uint j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
	}
}

Matrix::Matrix(double** values, int w, int h) {
	m_cols = w;
	m_rows = h;
	arr = new double*[h];
	for(int i = 0; i < h; i++) {
        arr[i] = new double[w];
		for (int j = 0; j < w; j++) {
			arr[i][j] = values[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& m) {
    m_cols = m.m_cols;
	m_rows = m.m_rows;
	arr = new double*[m_rows];
    for (uint i = 0; i < m.m_rows; i++) {
        arr[i] = new double[m_cols];
        for (uint j = 0; j < m.m_cols; j++) {
            arr[i][j] = m.at(i, j);
        }
    }
}

Matrix::~Matrix() {
	for (uint i = 0; i < m_rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

Matrix Matrix::add(double s) const {
    Matrix temp (m_rows, m_cols);
    for (uint i = 0; i < m_rows; i++) {
        for (uint j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] + s;
        }
    }
    return temp;
}
Matrix Matrix::add(const Matrix& m) const {
    Matrix temp (m_rows, m_cols);
    for (uint i = 0; i < m_rows; i++) {
        for (uint j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] + m.at(i,j);
        }
    }
    return temp;
}

Matrix Matrix::subtract(double s) const {
    Matrix temp (m_rows, m_cols);
    for (uint i = 0; i < m_rows; i++) {
        for (uint j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] - s;
        }
    }
    return temp;
}
Matrix Matrix::subtract(const Matrix& m) const {
    Matrix temp (m_rows, m_cols);
    for (uint i = 0; i < m_rows; i++) {
        for (uint j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] - m.at(i,j);
        }
    }
    return temp;
}

Matrix Matrix::multiply(double s) const {
    Matrix temp (m_rows, m_cols);
    for (uint i = 0; i < m_rows; i++) {
        for (uint j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] * s;
        }
    }
    return temp;
}

Matrix Matrix::multiply(const Matrix& m) const {
    /**
     * Temp will have the same number of rows as this
     * and same number of cols as m
     **/
    Matrix temp (m_rows, m.m_cols);
    for (uint i = 0; i < m_rows; i++) { // for every row in this
        for (uint j = 0; j < m.m_cols; j++) { // for ever col in m
            for (uint k = 0; k < m_cols; k++) { // compute product of row and col
                temp.at(i, j) = temp.at(i,j) + arr[i][k] * m.at(k,j);
            }
        }
    }
    return temp;
}

Matrix Matrix::divide(double s) const {
    Matrix temp (m_rows, m_cols);
    for (uint i = 0; i < m_rows; i++) {
        for (uint j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] / s;
        }
    }
    return temp;
}
/**
 * Transpose of this matrix
 **/
Matrix Matrix::t() const {
    Matrix temp (m_cols, m_rows);
    for (uint i = 0; i < m_rows; i++) {
        for (uint j = 0; j < m_cols; j++) {
            temp.at(j, i) = arr[i][j];
        }
    }
    return temp;
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

/**
 * Returns an array containing the length of the longest number
 * of every column. Used for formatting and printing Matrices.
 **/
int* Matrix::getWidthArray() const {
    int* widthArray = new int[m_cols];
    // Make sure widthArray is filled with 0s
    for (uint i = 0; i < m_cols; i++) {
        widthArray[i] = 0;
    }
    
    int temp;
    // Fill widthArray
    for (uint c = 0; c < m_cols; c++) {
        for (uint r = 0; r < m_rows; r++) {
            temp = arr[r][c];
            if (temp < 0) {
                temp = (int)log10(temp * -10) + 1;
            } else if (temp == 0) {
                temp = 1;
            } else {
                temp = (int)log10(temp) + 1;
            }

            if (temp > widthArray[c]) {
                widthArray[c] = temp;
            }
        }
    }
    return widthArray;
}

// Stream instertion overload
std::ostream & operator<<(std::ostream & output, const Matrix & m) {
    // wdithArray stores the length of the longest double in each column, 
    // it is used to line up columns
    int* widthArray = m.getWidthArray();
    output << "[ ";
    for (uint i = 0; i < m.numRows(); i++) {        
        for (uint j = 0; j < m.numCols(); j++) {
            output << setw(widthArray[j]) << std::setprecision(5) << m.at(i,j);
            if (j < m.numCols() - 1) {
                output << ", ";
            }
        }    
        if (i < m.numRows() -1) {
            output << " ]\n[ ";
        }
    }
    output << " ]\n";
    delete [] widthArray;
    return output;
} 

// Matrix and scalar overloads
Matrix operator+(const Matrix &m, const double &s) {
    return m.add(s);
}
Matrix operator-(const Matrix &m, const double &s) {
    return m.subtract(s);
}
Matrix operator*(const Matrix &m, const double &s) {
    return m.multiply(s);
}
Matrix operator/(const Matrix &m, const double &s) {
    return m.divide(s);
}

// Scalar and Matrix overloads
Matrix operator+(const double &s, const Matrix &m) {
    return m.add(s);
}
Matrix operator-(const double &s, const Matrix &m) {
    return m.subtract(s);
}
Matrix operator*(const double &s, const Matrix &m) {
    return m.multiply(s);
}
Matrix operator/(const double &s, const Matrix &m) {
    Matrix temp (m.m_rows, m.m_cols);
    for (uint i = 0; i < m.m_rows; i++) {
        for (uint j = 0; j < m.m_cols; j++) {
            temp.at(i, j) = s / m.at(i,j);
        }
    }
    return temp;
}

// Matrix and Matrix
Matrix operator+(const Matrix &m, const Matrix &n) {
    return m.add(n);
}
Matrix operator-(const Matrix &m, const Matrix &n) {
    return m.subtract(n);
}
Matrix operator*(const Matrix &m, const Matrix &n) {
    return m.multiply(n);
}

// Function call overloads
double& Matrix::operator()(uint row, uint col) {
	return arr[row][col];
}
const double& Matrix::operator()(uint row, uint col) const {
	return arr[row][col];
}

// Assignment overload
Matrix& Matrix::operator=(const Matrix & m) {
    // Delete this object
    for (uint i = 0; i < m_rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;

    // Make a copy
    m_cols = m.m_cols;
	m_rows = m.m_rows;
	arr = new double*[m_rows];
    for (uint i = 0; i < m.m_rows; i++) {
        arr[i] = new double[m_cols];
        for (uint j = 0; j < m.m_cols; j++) {
            arr[i][j] = m.at(i, j);
        }
    }
    return *this;
}

// Assignment overload
Matrix Matrix::operator-() const {    
    return (*this).multiply(-1).add(0);
}