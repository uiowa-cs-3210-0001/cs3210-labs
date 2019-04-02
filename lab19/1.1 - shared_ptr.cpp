#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Thingy
{
    Thingy() { cout << "Thingy" << endl; }
    ~Thingy() { cout << "~Thingy" << endl; }

    shared_ptr<Thingy> parent;
};


unique_ptr<Thingy> create() { return unique_ptr<Thingy>( new Thingy ); }


void foo( vector<shared_ptr<Thingy>>& things)
{
    things.push_back( create() );
    things.push_back( create() );

    things[0]->parent = things[1];

    // ..
    things[0] = shared_ptr<Thingy>();
    things[1] = shared_ptr<Thingy>();
}

int main()
{
    vector<shared_ptr<Thingy>> things;
    foo( things );
    cout << "foo" << endl;
}


// vector<shared_ptr<Thingy>> processed;

// struct Thingy: enable_shared_from_this<Thingy> {

//   void process()
//   {
//     processed.emplace_back(shared_from_this());
//   }

// };
