#include <iostream>
#include "Matrix.h"

using namespace std;

// Normal constructor, all zeroes
Matrix m(3, 3);
// Copy constructor
Matrix n(m);
// Third matrix
Matrix o(3, 3);

void demoAdd() {
    // Adding scalar
    cout << "Adding 10 to m" << endl;
    cout << m.add(10);
    cout << "m is unchanged" << endl;
    cout << m << endl;

    // Adding another matrix
    cout << "Adding m and n" << endl;
    cout << m.add(n) << endl;
}
void demoSubtract() {
    // Subtracting scalar
    cout << "Subtracting 20 from m" << endl;
    cout << m.subtract(20) << endl;

    // Subtracting another matrix
    cout << "Subtracting m from o" << endl;
    cout << o.subtract(m) << endl;
}
void demoMultiply() {
    // Multiply by scalar
    cout << "Multiply m by 3" << endl;
    cout << m.multiply(3) << endl;

    // Multiply by another matrix
    cout << "Multiply m by o" << endl;
    cout << m.multiply(o) << endl;
}
void demoDivide() {
    // Divide by sclar
    cout << "Divide o by 3" << endl;
    cout << o.divide(3) << endl;
}

void demoAddOverload() {
    // Adding Matrix and scalar
    cout << "Adding 10 to m" << endl;
    cout << m + 10;
    cout << "m is unchanged" << endl;
    cout << m << endl;

    // Adding scalar and matrix
    cout << "Adding 50 to m" << endl;
    cout << 50 + m;

    // Adding another matrix
    cout << "Adding m and n" << endl;
    cout << m + n << endl;
}
void demoSubtractOverload() {
    // Subtracting by scalar
    cout << "Subtracting 20 from m" << endl;
    cout << m - 20 << endl;

    // Subtracting from scalar
    cout << "Subtracting m from 1000" << endl;
    cout << 1000 - m << endl;

    // Subtracting another matrix
    cout << "Subtracting m from o" << endl;
    cout << o - m << endl;
}
void demoMultiplyOverload() {
    // Multiply matrix by scalar
    cout << "Multiply m by 3" << endl;
    cout << m * 3 << endl;

    // Multiply scalar by matrix
    cout << "Multiply 4 by m" << endl;
    cout << 4 * m << endl;

    // Multiply by another matrix
    cout << "Multiply m by o" << endl;
    cout << m * o << endl;
}
void demoDivideOverload() {
    // Divide by scalar
    cout << "Divide o by 3" << endl;
    cout << o / 3 << endl;

    // Divide scalar by matrix
    cout << "Divide 200 by o" << endl;
    cout << 200 / o << endl;
}

void demoConstMatrix() {
    const Matrix cm(o);
    cout << "cm at 0,0" << endl;
    cout << cm(0, 0) << endl;
    cout << cm;

    cout << "Multiply cm by 5" << endl;
    cout << cm * 5 << endl;
}
void demoAssignment() {
    Matrix temp(2, 3);
    for (uint i = 0; i < temp.numRows(); i++) {
        for (uint j = 0; j < temp.numCols(); j++) {
            temp(i,j) = 50 + (i * temp.numRows()) + j;
        }
    }
    cout << "Temp matrix:" << endl;
    cout << temp;
    cout << "Assigning m to temp:" << endl;
    temp = m;
    cout << temp << endl;
}

int main() {
    // Fill matrix m, 0 - 8
    for (int i = 0; i < 9; i++) {
        m(i / 3, i % 3) = i;
    }
    cout << "m matrix:\n" << m << endl;

    // Fill matrix n, 10 - 18
    for (int i = 0; i < 9; i++) {
        n(i / 3, i % 3) = i + 10;
    }
    cout << "n matrix, copy of m:\n" << n << endl;

    // 2d Array constructor, 100 - 92
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            o(i, j) = 100 - (i * 3) - j;
        }
    }
    cout << "o matrix, constructed from array:\n" << o << endl;

    /**
    demoAdd();
    demoSubtract();
    demoMultiply();
    demoDivide();
    **/

    demoAddOverload();
    demoSubtractOverload();
    demoMultiplyOverload();
    demoDivideOverload();
    demoConstMatrix();
    demoAssignment();
    return 0;
}