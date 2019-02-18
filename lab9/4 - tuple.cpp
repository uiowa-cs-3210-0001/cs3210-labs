#include <iostream>
#include <string>

template< typename T, typename U >
struct tuple
{
    T t;
    U u;
};


int main()
{
    tuple<int,std::string> t = { -1, "Error opening file" };
    auto [i, str] = t;
    std::cout << i << std::endl;
    std::cout << str << std::endl;

    // tuple<int,int> t2 = { -1, 0 };
    // std::cout << "### iterating through tuple<int,int>" << std::endl;
    // for ( auto i : t2.as_array() )
    //     std::cout << i << std::endl;
}

// template< typename T >
// struct tuple<T,T>
// {
//     T t[2];

//     typedef T array_type[2];
//     array_type& as_array() { return this->t; }
// };
