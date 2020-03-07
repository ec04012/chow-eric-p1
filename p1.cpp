#include<iostream>
#include "Matrix.h"

using namespace std;

int main() {
    // Normal constructor, all zeroes
    Matrix m (3,3);
    for (int i = 0; i < 9; i++) {
        m.at(i/3,i%3)=i;
    }
    cout << "m matrix:\n" << m << endl;

    // Copy constructor
    Matrix n (m);
    cout << "n matrix, copy of m:\n" << n << endl;

    // 2d Array constructor
    double ** arr = new double*[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            arr[i][j]=100-(i*3)-j;
        }
    }
    Matrix o (arr,3,3);
    cout << "o matrix, constructed from array:\n" << o << endl;
    for (int i = 0; i < 3; i++) {
        delete [] arr[i];
    }
    delete [] arr;

    // Adding scalar
    cout << "Adding 10 to m" << endl;
    cout << m.add(10);
    cout << "m is unchanged" << endl;
    cout << m << endl;

    // Adding another matrix
    cout << "Adding m and n" << endl;
    cout << m.add(n);
    cout << "m is unchanged" << endl;
    cout << m << endl;

    // Subtracting scalar
    cout << "Subtracting 20 from m" << endl;
    cout << m.subtract(20);
    cout << "m is unchanged" << endl;
    cout << m << endl;

    // Subtracting another matrix
    cout << "Subtracting m from o" << endl;
    cout << o.subtract(m);
    cout << "o is unchanged" << endl;
    cout << o << endl;


    return 0;
}
