#include <iostream>
#include <stdexcept>


class vector {
public:
    vector( int size )
        : size_{ size }, data{ new double[size]{} }
        {}

    ~vector()
    {
        delete[] this->data;
        this->data = 0;
    }

    double& operator[](int i)
    {
        if ( i < 0 || i >= this->size() ) {
            throw std::out_of_range( "vector::operator[]: Index " 
                + std::to_string( i ) + " is out of range (size: " 
                + std::to_string( this->size() ) + ")"
                );
        }

        return this->data[i];
    }
    
    int size() const { return this->size_; }

private:
    int size_;
    double* data;
};


int main()
{
    vector v( 1 );
    v[0] = 3.14;
    std::cout << v[0] << std::endl;
}
