#include <iostream>
#include <string>
#include <tuple>

int main()
{
    std::tuple<int,std::string> t = { -1, "Error opening file" };
    auto [i, str] = t;
    std::cout << i << std::endl;
    std::cout << str << std::endl;
}
