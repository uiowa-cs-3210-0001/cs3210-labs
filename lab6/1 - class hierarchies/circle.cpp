#include "circle.hpp"
#include <iostream>

Circle::Circle(Point c, int rad)
    : center_( c ), radius( rad )
{}


void Circle::print() const
{
    std::cout 
        << "[circle] center: " 
        << "(" << this->center_.x << ", " << this->center_.y << "), "
        << "radius: " << this->radius << std::endl;
}
