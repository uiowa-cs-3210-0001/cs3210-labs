#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


struct Person
{
    string name;
    string email;
};


struct Ticket
{
  unsigned long ticket_id;
  string event_id;
  Person owner;
};


using TicketsByEmail = multimap<string,Ticket>;
using TicketsByTicketId = map<unsigned long,Ticket>;

struct TicketDb
{
    void add( Ticket const& t )
    {
      this->tickets_by_email.insert( pair( t.owner.email, t ) );
      this->tickets_by_id.insert( pair( t.ticket_id, t ) );
    }

    // std::vector<Ticket>
    // find_ticket_by_email( string email ) const
    // {
    //   auto range = this->tickets_by_email.equal_range( email );
    //   return std::vector<Ticket>( range.first, range.second );
    // }

    Person
    find_ticket_owner( unsigned long ticket_id ) const
    {
      auto iter = this->tickets_by_id.find( ticket_id );
      if ( iter != this->tickets_by_id.end() )
        return iter->second.owner;

      throw runtime_error( "Not found" );
    }

private:
  TicketsByEmail tickets_by_email;
  TicketsByTicketId tickets_by_id;
};



int main()
{
     TicketDb tickets;
}
