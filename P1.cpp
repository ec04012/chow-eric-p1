#include<iostream>
#include "Matrix.cpp"

using namespace std;

int main() { 
    Matrix m (3,3);
    cout << m.at(0,0) << endl;
    m.at(0,0) = 3;
    cout << m.at(0,0) << endl;
    cout << "Hello World" << endl;
    return 0; 
}
