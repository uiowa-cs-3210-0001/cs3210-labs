#include <iostream>

using namespace std;


struct Vector {
    int size;     // number of elements
    double* data; // pointer to elements
};


void vector_init(Vector& v, int size)
{
    v.data = new double[size]; // allocate an array of `size` doubles
    v.size = size;
}


double read_and_sum(int size)
{
    Vector v;
    vector_init(v, size);

    for (int i = 0; i < size; ++i)
        cin >> v.data[i]; // read into elements

    double sum = 0;
    for (int i=0; i < size; ++i)
        sum += v.data[i]; // compute the sum of the elements

    return sum;
}


int main() {
    cout << read_and_sum(5);
}
