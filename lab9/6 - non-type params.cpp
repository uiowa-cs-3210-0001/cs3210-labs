#include <iostream>
#include <string>

template< std::size_t N >
struct buffer
{
    typedef unsigned char byte;

    explicit buffer( std::size_t size )
        : ptr( size > N ? new byte[size] : buf )
    {}

    ~buffer()
    {
        if ( this->ptr != this->buf )
            delete[] this->ptr;
    }

    byte* c_ptr() { return this->ptr; }

private:
    byte buf[N];
    byte* ptr;
};


int main()
{
    buffer<512> b( 10 );
    // std::cout << static_cast<void*>( &b ) << std::endl;
    std::cout << static_cast<void*>( b.c_ptr() ) << std::endl;

    buffer<512> b1( 1024 );
    std::cout << static_cast<void*>( b1.c_ptr() ) << std::endl;
}
