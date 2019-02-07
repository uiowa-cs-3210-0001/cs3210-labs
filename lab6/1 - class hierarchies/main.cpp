#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<Shape*>& shapes, int angle)
{
    for (auto s : shapes)
        s->rotate( angle );
}

void print(vector<Shape*>& shapes)
{    
    for (auto s : shapes)
        s->print();
}


int main()
{
    vector<Shape*> shapes;
    shapes.push_back( new Circle( Point{5,5}, 10 ) );
    shapes.push_back( new Circle( Point{-1,-1}, 5 ) );
    shapes.push_back( new Rectangle( Point{1,1}, Point{10,10} ) );

    rotate( shapes, 90 );
    print( shapes );
}


// void print_filled(vector<Shape*>& shapes)
// {    
//     for (auto s : shapes)
//         if ( ??? )
//             s->print();
// }
