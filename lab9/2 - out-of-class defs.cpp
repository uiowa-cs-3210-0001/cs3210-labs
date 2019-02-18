#include <iostream>
#include <stdexcept>

template< typename T >
class vector {
public:
    vector( int size );
    ~vector();

    T& operator[](int i);
    int size() const;

private:
    int size_;
    T* data;
};


template< typename T >
vector<T>::vector( int size )
    : size_{ size }, data{ new T[size]{} }
{}


template< typename T >
vector<T>::~vector()
{
    delete[] this->data;
    this->data = 0;
}


template< typename T >
T& vector<T>::operator[](int i)
{
    if ( i < 0 || i >= this->size() ) {
        throw std::out_of_range( "vector::operator[]: Index " 
            + std::to_string( i ) + " is out of range (size: " 
            + std::to_string( this->size() ) + ")"
            );
    }

    return this->data[i];
}


template< typename T >
int vector<T>::size() const 
{
    return this->size_;
}


int main()
{
    vector<double> v( 1 );
    v[0] = 3.14;
    std::cout << v[0] << std::endl;
}
