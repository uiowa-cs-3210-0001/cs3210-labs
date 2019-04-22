#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

mutex cout_mutex;

int iteration_count = 0;
mutex iteration_mutex;


void f()
{
    scoped_lock l1( iteration_mutex );
    scoped_lock l2( cout_mutex );
    ++iteration_count;

    cout << "Hello, " << endl;
    cout << "Bob! " << endl;
    cout << "-------" << endl;
}


struct F {
    void operator()()
    {
        scoped_lock l1( iteration_mutex );
        scoped_lock l2( cout_mutex );
        ++iteration_count;

        cout << "Hi, " << endl;
        cout << "Alice! " << endl;
        cout << "-------" << endl;
    }
};


void inc()
{
    scoped_lock l( iteration_mutex );
    ++iteration_count;
}



int main()
{
    for ( int i = 0; i < 1000; ++i )
    {
        thread t1{ f };
        thread t2{ F() };
        thread t3{ inc };

        t1.join();
        t2.join();
        t3.join();
    }

    cout << "iteration_count: " << iteration_count << endl;
}
