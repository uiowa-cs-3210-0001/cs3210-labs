#include <iostream>
#include <list>
using namespace std;


struct Entry
{
    string name;
    string phone_number;
};

ostream& operator<<( ostream& out, Entry const& e )
{
    return out << e.name << ": " << e.phone_number;
}


int main()
{
    list<Entry> phone_book = {
        { "David Hume", "1-319-515-0217" },
        { "Karl Popper", "1-818-921-3650" },
        { "1-800-Flowers", "1-800-716-4851" },
    };

    // for ( unsigned i = 0; i < phone_book.size(); ++i )
    //     cout << phone_book[i] << endl;
}
