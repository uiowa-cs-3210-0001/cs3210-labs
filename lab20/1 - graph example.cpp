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

    void add_successor( shared_ptr<Node> n ) { this->successors.insert( n ); }
    void remove_successor( shared_ptr<Node> n ) { this->successors.erase( n ); }

    string name;
    set<shared_ptr<Node>> successors;
};


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

    n5->add_successor( n4 );
    n5->add_successor( n7 );
    n5->add_successor( n8 );

    n7->add_successor( n8 );
    n7->add_successor( n3 );

    n3->add_successor( n1 );
    n3->add_successor( n8 );

    n4->add_successor( n2 );
    n4->add_successor( n6 );
    n4->add_successor( n1 );

    n8->add_successor( n6 );

    n6->add_successor( n1 );

    cout << "n1 ref count: " << n1.use_count() << endl;
}
