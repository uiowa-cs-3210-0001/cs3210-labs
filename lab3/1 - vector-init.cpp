#include <iostream>

using namespace std;


struct Vector {
    int size;       // number of elements
    double* data; // pointer to elements
};


void vector_init(Vector& v, int size)
{
    v.data = new double[size]; // allocate an array of `size` doubles
    v.size = size;
}


int main() {
    Vector v;
    vector_init(v, 10);

    cout << v.size;
}
