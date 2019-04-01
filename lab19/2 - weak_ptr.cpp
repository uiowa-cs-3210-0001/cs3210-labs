#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Thingy
{
    Thingy() { cout << "Thingy" << endl; }
    ~Thingy() { cout << "~Thingy" << endl; }
    weak_ptr<Thingy> parent;
};


int main()
{
    vector<shared_ptr<Thingy>> things;
    shared_ptr<Thingy> thing1( new Thingy );
    shared_ptr<Thingy> thing2( new Thingy );
    thing1->parent = thing2;

    things.push_back( thing1 );
    things.push_back( thing2 );

    // ..
    things[1] = shared_ptr<Thingy>();
}
