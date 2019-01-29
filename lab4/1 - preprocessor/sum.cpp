#include "vector.hpp"

double sum(Vector& v)
{
    double result = 0;
    for (int i = 0; i < v.size(); ++i)
        result += v[i];
    return result;
}
