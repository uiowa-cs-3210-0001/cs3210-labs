#include <iostream>
#include <memory>
using namespace std;

struct Thingy
{
    Thingy() { cout << "Thingy" << endl; }
    ~Thingy() { cout << "~Thingy" << endl; }
};


int main()
{
    Thingy* t = new Thingy();
    // ...

    delete t;
}
