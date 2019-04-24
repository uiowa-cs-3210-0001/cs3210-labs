#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;


class account {
    double balance;

public:
    explicit account( double balance = 0.0 )
        : balance( balance )
    {}

    double current_balance() const
    { 
        return this->balance; 
    } 

    double deposit( double amount ) { 
        return this->balance += amount; 
    }

    double withdraw( double amount ) { 
        return this->balance -= amount; 
    }
};


double rand_cash_amount( double max )
{
    return ( rand() * max ) / RAND_MAX;
}


void earn( account& acc, int iteration_count, milliseconds ms )
{
    for ( int i = 0; i < iteration_count; ++i )
    {
        acc.deposit( rand_cash_amount( 100 ) );
        this_thread::sleep_for( ms );
    }
}


void spend( account& acc, int iteration_count, milliseconds ms )
{
    for ( int i = 0; i < iteration_count; ++i )
    {
        acc.withdraw( rand_cash_amount( 100 ) );
        this_thread::sleep_for( ms );
    }
}


void report( account const& acc, int iteration_count, milliseconds ms )
{
    for ( int i = 0; i < iteration_count; ++i )
    {
        cout << "Current balance: " << acc.current_balance() << endl;
        this_thread::sleep_for( ms );
    }
}


int main()
{
    std::srand( std::time( nullptr ) );
    int const n = 100;

    account acc;
    vector<thread> threads; 
    threads.push_back( thread{ earn, ref( acc ), n, milliseconds( 10 ) } );
    threads.push_back( thread{ spend, ref( acc ), n, milliseconds( 10 ) } );
    threads.push_back( thread{ report, ref( acc ), n, milliseconds( 10 ) } );

    for ( auto& t: threads )
        t.join();

    cout << "Final balance: " << acc.current_balance() << endl;
}
