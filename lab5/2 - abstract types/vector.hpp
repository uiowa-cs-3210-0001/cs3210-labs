#ifndef CS3210_LAB5_VECTOR_HPP
#define CS3210_LAB5_VECTOR_HPP

class Vector {
public:
    Vector( int size )
        : size_{ size }, data{ new double[size] }
        {}

    double& operator[](int i); // element access: subscripting
    int size() const { return this->size_; }

private:
    int size_;    // number of elements
    double* data; // pointer to elements
};

inline
double& Vector::operator[](int i) 
{
    return this->data[i];
}

#endif // #ifndef CS3210_LAB5_VECTOR_HPP
