class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();

private:
    double* elem; // elem points to an array of sz doubles
    int sz;
};

Vector::Vector(int s)                  // definition of the constructor
     :elem{new double[s]}, sz{s}       // initialize members
{
}

double& Vector::operator[](int i)      // definition of subscripting
{
     return elem[i];
}

int Vector::size()                     // definition of size()
{
     return sz;
}
