#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <algorithm>
#include <iostream>
#include <string>

using boost::multi_index_container;
using namespace boost::multi_index;
using namespace std;


struct employee
{
    int id;
    string name;
    int age;

    employee( int id, std::string const& name, int age )
        : id( id ), name( name ), age( age) 
    {}

    friend ostream& operator<<( ostream& os, employee const& e )
    {
        return os << e.id << " " << e.name << " " << e.age << std::endl;
    }
};


struct id {};
struct name {};
struct age {};

typedef multi_index_container<
    employee,
    indexed_by<
        ordered_unique< tag<id>, member<employee, int, &employee::id> >,
        ordered_non_unique< tag<name>, member<employee, std::string, &employee::name> >,
        ordered_non_unique< tag<age>, member<employee, int, &employee::age> >
        >
    > employee_set;


template< typename Tag >
void print_out_by( employee_set const& s )
{
    auto const& index = get<Tag>( s );
    std::copy( index.begin(), index.end(), 
        ostream_iterator<employee>( std::cout ) );
}


int main()
{
    employee_set es;

    es.insert( employee( 0, "Joe", 31 ) );
    es.insert( employee( 1, "Robert", 27 ) );
    es.insert( employee( 2, "John", 40 ) );

    // next insertion will fail, as there is an employee with
    // the same ID
    es.insert( employee( 2, "Aristotle", 2387 ) );

    es.insert( employee( 3, "Albert", 20 ) );
    es.insert( employee( 4, "John", 57 ) );

    std::cout << "by ID" << std::endl;
    print_out_by<id>( es );
    std::cout << std::endl;

    std::cout << "by name" << std::endl;
    print_out_by<name>( es );
    std::cout << std::endl;

    std::cout << "by age" << std::endl;
    print_out_by<age>( es );
    std::cout << std::endl;

    auto& employees_by_name = es.get<name>();
    auto [ first, last ] = employees_by_name.equal_range( "John" );
    std::cout << "Johns:" << endl;
    std::copy( first, last, 
        ostream_iterator<employee>( std::cout ) );
}
