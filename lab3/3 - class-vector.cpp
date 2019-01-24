#include <iostream>

using namespace std;


class Vector {
public:
     Vector( int size )
        : size_{ size }, data{ new double[size] }
        {}

     double& operator[](int i) // element access: subscripting
        { return this->data[i]; } 
     
     int size() { return this->size_; }

private:
    int size_;    // number of elements
    double* data; // pointer to elements
};


int main() {
    Vector v( 10 );
    // cout << v.size;
    cout << v.size();
}
