#include <functional>
#include <iostream>
#include <string>
using namespace std;

struct event {
    string type;
    string value;
};


struct event_dispatcher {
    void subscribe( string const& type, ... );
    void dispatch( event const& );
};
 

struct user {
    user( event_dispatcher& d )
    {
        d.subscribe( "mouseenter", ... );
    }

    void on_mouseenter( event const& e )
    {
        cout << e.type << ":" << e.value << endl; 
    }
};

 
int main()
{
    event_dispatcher d;
    user u1( d );
    user u2( d );

    d.dispatch( event{ "mouseenter", "(5, 5)" } );
    d.dispatch( event{ "mouseexit", "(15, 15)" } );
}
