typedef unsigned int uint;

#include "Matrix.h"

double **arr;
Matrix::Matrix(uint rows, uint cols) {}
Matrix::Matrix(double **values, int w, int h) {}

Matrix::Matrix(const Matrix &m) {}
Matrix::~Matrix() {}

Matrix Matrix::add(double s) const {}
Matrix Matrix::add(const Matrix &m) const {}

Matrix Matrix::subtract(double s) const {}
Matrix Matrix::subtract(const Matrix &m) const {}

Matrix Matrix::multiply(double s) const {}
Matrix Matrix::multiply(const Matrix &m) const {}

Matrix Matrix::divide(double s) const {}
Matrix Matrix::t() const {}

const uint Matrix::numRows() const {}
const uint Matrix::numCols() const {}

double & Matrix::at(uint row, uint col) {}
const double & Matrix::at(uint row, uint col) const {}
;