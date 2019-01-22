#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x = 42;
    // int x( 42 );
    // int x = { 42 };
    // int x{ 42 };
    // int x({ 42 });

    vector<int> v = { 1, 2, 3 };
    // vector<int> v{ 1, 2, 3 };
    // vector<int> v({ 1, 2, 3 });

    cout 
        << x << "\n"
        << v[0] << ", " << v[1] << ", " << v[2] << "\n"
        ;

    int i = 7.8;
    // int i{7.8};
    cout << "i: " << i << "\n";
}
