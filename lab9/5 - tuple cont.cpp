#include <iostream>
#include <string>

template< typename T >
struct tuple_element
{
    T t;
};

template< typename ...Ts >
struct tuple : tuple_element<Ts>...
{
};


int main()
{
    tuple<int,std::string,bool,float> t = { -1, "Error opening file", true };
    // auto [i, str] = t;
    // std::cout << i << std::endl;
    // std::cout << str << std::endl;
}

