#include <iostream>
#include <set>
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


int main()
{
    set<Ticket> s; // ???
}
