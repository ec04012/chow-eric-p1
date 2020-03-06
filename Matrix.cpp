typedef unsigned int uint;

#include "Matrix.h"
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
    Matrix temp (m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] + m.at(i,j);
        }
    }
    return temp;
}

Matrix Matrix::subtract(double s) const {
    Matrix temp (m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] - s;
        }
    }
    return temp;
}
Matrix Matrix::subtract(const Matrix& m) const {
    Matrix temp (m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            temp.at(i, j) = arr[i][j] - m.at(i,j);
        }
    }
    return temp;
}

Matrix Matrix::multiply(double s) const {
    Matrix temp (m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
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
    for (int i = 0; i < m_rows; i++) { // for every row in this
        for (int j = 0; j < m.m_cols; j++) { // for ever col in m
            for (int k = 0; k < m_cols; k++) { // compute product of row and col
                temp.at(i, j) = temp.at(i,j) + arr[i][k] + m.at(k,j);
            }
        }
    }
    return temp;
}

Matrix Matrix::divide(double s) const {
    Matrix temp (m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
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
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
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

// overloaded stream insertion operator
// If the matrix is 0x0, nothing is printed
std::ostream & operator<<(std::ostream & output, const Matrix & m) {
    for (uint i = 0; i < m.numRows(); i++) {
        output << "[";
        for (uint j = 0; j < m.numCols(); j++) {
            output << m.at(i,j);
            if (j < m.numCols() - 1) {
                output << ", ";
            }
        }
        output << "]\n";
    }
    return output; // enables cout << a << b << c;
} // end function operator<<
