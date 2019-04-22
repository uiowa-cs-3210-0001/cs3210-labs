#include <iostream>
#include <thread>
using namespace std;


void f()
{
    cout << "Hello, " << endl;
    cout << "Bob! " << endl;
    cout << "-------" << endl;
}


struct F {
    void operator()()
    {
        cout << "Hi, " << endl;
        cout << "Alice! " << endl;
        cout << "-------" << endl;
    }
};


int main()
{    
    thread t1{ f };
    thread t2{ F() };

    t1.join();
    t2.join();
}
