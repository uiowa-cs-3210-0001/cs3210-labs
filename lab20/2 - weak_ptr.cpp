#include <iostream>
#include <memory>
#include <set>
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
    set<weak_ptr<Node>, owner_less<>> predecessors;
    set<shared_ptr<Node>> successors;
};

void add( shared_ptr<Node> l, shared_ptr<Node> r )
{
    l->successors.insert( r );
    r->predecessors.insert( l );
}

void remove( shared_ptr<Node> l, shared_ptr<Node> r )
{
    l->successors.erase( r );
    r->predecessors.erase( l );
}


int main()
{
    shared_ptr<Node> n1( new Node( "1" ) );
    shared_ptr<Node> n2( new Node( "2" ) );
    shared_ptr<Node> n3( new Node( "3" ) );
    shared_ptr<Node> n4( new Node( "4" ) );
    shared_ptr<Node> n5( new Node( "5" ) );
    shared_ptr<Node> n6( new Node( "6" ) );
    shared_ptr<Node> n7( new Node( "7" ) );
    shared_ptr<Node> n8( new Node( "8" ) );

    add( n5, n4 );
    add( n5, n7 );
    add( n5, n8 );

    add( n7, n8 );
    add( n7, n3 );

    add( n3, n1 );
    add( n3, n8 );

    add( n4, n2 );
    add( n4, n6 );
    add( n4, n1 );

    add( n8, n6 );

    add( n6, n1 );

    cout << "n1 ref count: " << n1.use_count() << endl;
}
