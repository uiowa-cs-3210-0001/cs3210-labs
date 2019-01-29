
double sqrt(double n)
{
    double result = n / 2;
    for (int i = 0; i < 10; ++i) {
        result = ( result + n / result ) / 2;
    }
    return result;
}
