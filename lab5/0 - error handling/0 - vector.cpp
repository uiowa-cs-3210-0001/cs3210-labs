#include <iostream>

using namespace std;


class Vector {
public:
    Vector( int size )
        : size_{ size }, data{ new double[size] }
        {}

    double& operator[](int i); // element access: subscripting
    int size() { return this->size_; }

private:
    int size_;    // number of elements
    double* data; // pointer to elements
};


double& Vector::operator[](int i) 
{
    return this->data[i];
}


int main() {
    Vector v( 10 );
    cout << "v[0]:" << v[0] << endl;
    //cout << "v[10]:" << v[10] << endl;
}
