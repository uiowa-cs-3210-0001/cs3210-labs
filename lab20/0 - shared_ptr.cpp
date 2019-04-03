#include <iostream>
#include <memory>
using namespace std;


struct Node {

    Node( string name ) 
        : name( name ) 
    {
        cout << "Node(" << this->name << ")" << endl;
    }
    
    ~Node()
    {
        cout << "~Node(" << this->name << ")" << endl;
    }

    string name;
};


int main()
{
    shared_ptr<Node> p1( new Node( "5" ) );
    shared_ptr<Node> p2( p1 );
    shared_ptr<Node> p3( new Node( "7" ) );

    cout << "p1 ref count: " << p1.use_count() << endl;
    // cout << "p2 ref count: " << p2.use_count() << endl;
    // cout << "p3 ref count: " << p3.use_count() << endl;

}
