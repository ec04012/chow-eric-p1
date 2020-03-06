#include<iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix m (3,3);
    for (int i = 0; i < 9; i++) {
        m.at(i/3,i%3)=i;
    }
    cout << m;
    return 0;
}
