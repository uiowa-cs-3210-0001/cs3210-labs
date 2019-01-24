#include <iostream>
using namespace std;

enum class Traffic_light { green, yellow, red };

Traffic_light& operator++(Traffic_light& t) // prefix increment: ++
{
     switch (t) {
        case Traffic_light::green:     return t=Traffic_light::yellow;
        case Traffic_light::yellow:    return t=Traffic_light::red;
        case Traffic_light::red:       return t=Traffic_light::green;
     }

     return t;
}


int main() {
    Traffic_light light = Traffic_light::red;
    Traffic_light next = ++light; 

    if ( light < Traffic_light::red )
        cout << "go" << endl;
}
