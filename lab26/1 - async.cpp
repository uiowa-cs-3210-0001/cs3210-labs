#include <iostream>
#include <vector>
#include <future>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;


bool is_prime( long n )
{
    auto const sqrt_n = sqrt( n );
    for ( long i = 2; i <= sqrt_n; ++i )
        if ( ( n % i ) == 0 )
            return false;

    return true;
}


vector<long> find_primes( long max )
{
    vector<long> result;
    for ( long i = 2; i <= max; ++i )
        if ( is_prime( i ) )
            result.push_back( i );

    return result;
}


int main()
{
    // auto start_time = high_resolution_clock::now();
    auto primes = find_primes( 10000000 );

    // auto end_time = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>( end_time - start_time ).count();
    // cout << "Execution time (ms): " << duration << endl;

    cout << "Number of primes: " << primes.size() << endl;
    cout << "Max primes: " << primes.back() << endl;
}
