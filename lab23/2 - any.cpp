#include <functional>
#include <iostream>
#include <string>
#include <any>
#include <map>

using namespace std;

struct event {
    string type;
    std::any value;
};


struct event_dispatcher {
    using event_receiver = function<void ( event const& )>;

    void subscribe( string const& type, event_receiver const& f )
    {
        this->subscribers.insert( pair( type, f ) );
    }

    void dispatch( event const& e )
    {
        auto [ i, end ] = this->subscribers.equal_range( e.type );
        for_each( i, end, [&]( auto s ) {
            s.second( e );
        } );
    }

    std::multimap<string,event_receiver> subscribers;
};


struct mouse_pos
{
    int x, y;
    friend ostream& operator<<( ostream& out, mouse_pos const& pos )
    {
        return out << '(' << pos.x << ',' << pos.y << ')';
    }
};


struct mouse_state
{
    mouse_pos pos;
    int button;

    friend ostream& operator<<( ostream& out, mouse_state const& state )
    {
        return out << state.pos << '^' << state.button;
    }
};


struct user {

    user( event_dispatcher& d )
    {
        d.subscribe( "mouseenter", [=]( auto e ) { this->on_mouseenter( e ); } );
        // d.subscribe( "mouseexit", this );
    }

    void on_mouseenter( event const& e )
    {
        if ( auto pos = any_cast<mouse_pos>( &e.value ) )
            cout << e.type << ":" << *pos << endl;
    }
};


int main()
{
    event_dispatcher d;
    user u1( d );
    user u2( d );

    d.subscribe( "mousedown", []( event const& e ) {
        if ( auto state = any_cast<mouse_state>( &e.value ) )
            cout << e.type << ":" << *state << endl;
    } );


    d.dispatch( event{ "mouseenter", mouse_pos{ 5, 5 } } );
    d.dispatch( event{ "mouseenter", mouse_pos{ 25, 55 } } );

    d.dispatch( event{ "mousedown", mouse_state{ 17, 42, 1 } } );
}
