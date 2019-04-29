#include <boost/signals2/signal.hpp>
#include <iostream>
#include <string>
#include <functional>

using namespace std;
using namespace boost::signals2;


class Document
{
public:
    typedef signal<void ()>  signal_t;

    connection connect( signal_t::slot_type const& subscriber )
    {
        return this->sig.connect( subscriber );
    }

    void append(const char* s)
    {
        this->text += s;
        this->sig();
    }

    std::string const& content() const
    {
        return this->text;
    }

private:
    signal_t    sig;
    std::string text;
};


class TextView
{
public:
    TextView( Document& doc, string_view id )
        : document( doc )
        , connection( document.connect( bind( &TextView::refresh, this ) ) )
        , id( id )
    {}

    ~TextView()
    {
        this->connection.disconnect();
    }

    void refresh() const
    {
        std::cout << "TextView" << this->id << ": " << document.content() << std::endl;
    }

private:
    Document&   document;
    connection  connection;
    string      id;
};



int main()
{
    Document    doc;
    TextView    v1( doc, "view 1" );

    {
    TextView    v2( doc, "view 2" );
    doc.append( "Hi there!" );
    }

    doc.append( " Welcome to Boost.Signals" );
    return 0;
}
