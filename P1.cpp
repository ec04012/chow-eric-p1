#include<iostream>
#include "Matrix.h"

using namespace std;

int main() { 
    Matrix m (3,3);
    cout << m.at(0,0) << endl;
    m.at(0,0) = 3;
    cout << m.at(0,0) << endl;
    return 0; 
}
