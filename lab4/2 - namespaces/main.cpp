#include <iostream>
using namespace std;

namespace cs3210 {

    class complex {
    public:
        complex(double r, double i)
            : _real(r), _imag(i)
            {}

        double real() const { return this->_real; }
        double imag() const { return this->_imag; }
            
    private:
        double _real;
        double _imag;
    };

    // ...

    int main();
}

int cs3210::main()
{
    complex z{1,2};
    cout << '{' << z.real() << ',' << z.imag() << "}\n";
    // ...
}

int main()
{
    return cs3210::main();
}
