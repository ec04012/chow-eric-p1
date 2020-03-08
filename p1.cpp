#include <iostream>
#include "Matrix.h"

using namespace std;

// Normal constructor, all zeroes
Matrix m(3, 3);
// Copy constructor
Matrix n(m);
// Third matrix
Matrix o(3,3);

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

int main() {
    // Fill matrix m, 0 - 8
    for (int i = 0; i < 9; i++) {
        m.at(i / 3, i % 3) = i;
    }
    cout << "m matrix:\n" << m << endl;

    // Fill matrix n, 10 - 18
    for (int i = 0; i < 9; i++) {
        n.at(i / 3, i % 3) = i + 10;
    }
    cout << "n matrix, copy of m:\n" << n << endl;

    // 2d Array constructor, 100 - 92
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            o.at(i,j) = 100 - (i * 3) - j;
        }
    }    
    cout << "o matrix, constructed from array:\n" << o << endl;    

    demoAdd();
    demoSubtract();
    demoMultiply();
    demoDivide();

    return 0;
}