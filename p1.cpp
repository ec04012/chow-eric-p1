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
    cout << "n matrix:\n" << n << endl;

    // 2d Array constructor
    double ** arr = new double*[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            arr[i][j]=100-(i*3)-j;
        }
    }
    Matrix o (arr,3,3);
    cout << "o matrix:\n" << o << endl;
    for (int i = 0; i < 3; i++) {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
