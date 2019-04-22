#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

mutex cout_mutex;

void f()
{
    scoped_lock l( cout_mutex );
    cout << "Hello, " << endl;
    cout << "Bob! " << endl;
    cout << "-------" << endl;
}


struct F {
    void operator()()
    {
        scoped_lock l( cout_mutex );
        cout << "Hi, " << endl;
        cout << "Alice! " << endl;
        cout << "-------" << endl;
    }
};


int main()
{
    // auto start_time = high_resolution_clock::now();
    for ( int i = 0; i < 1000; ++i )
    {
        thread t1{ f };
        thread t2{ F() };

        t1.join();
        t2.join();
    }

    // auto end_time = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>( end_time - start_time ).count();
    // cout << "Execution time (ms): " << duration << endl;
}
