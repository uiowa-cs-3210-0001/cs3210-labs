#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;


struct Student
{
    string name;
    string email;
};


Student find_by_email( 
    vector<Student> const& students,
    string const& email 
    )
{
    for ( auto const& s : students )
        if ( s.email == email )
            return s;

    throw runtime_error( "No student with email " + email );
}


int main()
{
    vector<Student> students = {
        { "Alice", "alice@uiowa.edu" },
        { "Bob", "Bob@uiowa.edu" },
        { "Karl", "karl@uiowa.edu" },
        { "Zoe", "zoe@uiowa.edu" }
    };

    try {
        auto r = find_by_email( students, "zoe@uiowa.edu" );
        cout << r.name << endl;
    }
    catch ( exception const& x )
    {
        cout << x.what();
    }
}
