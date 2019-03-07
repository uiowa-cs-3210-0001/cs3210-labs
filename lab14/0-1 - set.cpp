#include <iostream>
#include <set>
#include <stdexcept>
using namespace std;


struct Student
{
    string name;
    string email;
    string id;
};

namespace std {

template<>
struct less<Student>
{
    using is_transparent = void;
    
    bool operator()( Student const& lhs, Student const& rhs ) const
    {
        return lhs.email < rhs.email;
    }

    bool operator()( Student const& lhs, string const& email ) const
    {
        return lhs.email < email;
    }

    bool operator()( string const& email, Student const& rhs ) const
    {
        return email < rhs.email;
    }
};

}


struct less_by_id
{
    bool operator()( Student const& lhs, Student const& rhs ) const
    {
        return lhs.id < rhs.id;
    }
};


using Students = set<Student>;
using StudentsById = set<Student,less_by_id>;


Student find_by_email( 
    Students const& students,
    string const& email 
    )
{
    auto iter = students.find( email );
    if ( iter != students.end() )
        return *iter;

    // for ( auto const& s : students )
    //     if ( s.email == email )
    //         return s;

    throw runtime_error( "No student with email " + email );
}


int main()
{
    Students students;
    students.insert( { "Alice", "alice@uiowa.edu" } );
    students.insert( { "Bob", "Bob@uiowa.edu" } );
    students.erase( { "Bob", "Bob@uiowa.edu" } );

    auto iter = students.count( "Bob@uiowa.edu" );


    //     { "Alice", "alice@uiowa.edu" },
    //     { "Bob", "Bob@uiowa.edu" },
    //     { "Karl", "karl@uiowa.edu" },
    //     { "Zoe", "zoe@uiowa.edu" },
    //     { "Zoe Salinger", "zoe@uiowa.edu" },
    //     { "Zoe Salinger", "zoe@uiowa.edu" }
    // };

    for ( auto const& s : students )
        cout << s.name << endl;

    try {
        auto r = find_by_email( students, "zoe@uiowa.edu" );
        // cout << r.name << endl;
    }
    catch ( exception const& x )
    {
        cout << x.what();
    }
}
