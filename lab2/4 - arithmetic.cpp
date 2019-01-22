#include <iostream>
using namespace std;

int main()
{
    int x = 42;
    float y = 2.5;

    cout 
        << x + y << "\n"
        << x - y << "\n"
        << -x << "\n"
        << x * y << "\n"
        << x / y << "\n"
        << x % 3 << "\n"
    ;

    if ( x < y || x <= 10 || x > y * 2 || x >= 100 )
        cout << "yes";
    else
        cout << "no";

    // x += 10;
    // cout << x << "\n";
    // x++;
    // cout << x << "\n";
}
