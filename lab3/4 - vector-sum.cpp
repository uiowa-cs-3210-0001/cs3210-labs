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


double read_and_sum(int size)
{
    Vector v(size);

    for (int i = 0; i < size; ++i)
        cin >> v[i]; // read into elements

    double sum = 0;
    for (int i=0; i < size; ++i)
        sum += v[i]; // compute the sum of the elements

    return sum;
}


int main() {
    cout << read_and_sum(5);
}
