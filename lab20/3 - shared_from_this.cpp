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

    void process();

    string name;
    set<shared_ptr<Node>> successors;
};

set<shared_ptr<Node>> processed;

void Node::process()
{
    processed.insert( shared_ptr<Node>( this ) );
}


int main()
{
    shared_ptr<Node> p1( new Node( "5" ) );
    p1->process();
}
