#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Thingy
{
    Thingy() { cout << "Thingy" << endl; }
    ~Thingy() { cout << "~Thingy" << endl; }

    void process() { cout << "process" << endl; }
};


unique_ptr<Thingy> create() { return unique_ptr<Thingy>( new Thingy ); }

int main()
{
    unique_ptr<Thingy> t( new Thingy() );
    // Thingy* ptr = new Thingy();

    unique_ptr<Thingy> t;

    t.reset( new Thingy() );
    // t.reset( new Thingy() );

    unique_ptr<Thingy> t1( create() );

    vector< unique_ptr<Thingy> > v;
    v.push_back( create() );
    v.push_back( create() );
    v.push_back( create() );

    // t = ptr;
    t->process();
    (*t).process();
    // ...

    // delete ptr;
}
