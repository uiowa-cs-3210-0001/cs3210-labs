#ifndef CS3210_LAB5_COMPLEX_HPP
#define CS3210_LAB5_COMPLEX_HPP

class complex {
     double re, im; // representation: two doubles
public:
     complex(double r, double i) :re{r}, im{i} {}    // construct complex from two scalars
     complex(double r) :re{r}, im{0} {}              // construct complex from one scalar
     complex() :re{0}, im{0} {}                      // default complex: {0,0}

     double real() const { return re; }
     void real(double d) { re=d; }

     double imag() const { return im; }
     void imag(double d) { im=d; }

     complex& operator+=(complex z);
     complex& operator-=(complex z);
};

// unary minus
inline complex operator-(complex a) { return {-a.real(), -a.imag()}; } 
complex operator+(complex a, complex b);
complex operator-(complex a, complex b);

bool operator==(complex a, complex b);
bool operator!=(complex a, complex b);

#endif // #ifndef CS3210_LAB5_COMPLEX_HPP
