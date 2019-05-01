#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::multiprecision;

using big_int = cpp_int;
// using rational = cpp_rational;


int main()
{
    big_int i;
    cout << "Enter an arbitrary large integer number: " << endl;
    cin >> i;

    cout << "You entered:\n" << i << endl;
    cout << "i * 2 = " << i * 2 << endl;
    cout << "i / i = " << i / i << endl;
}
