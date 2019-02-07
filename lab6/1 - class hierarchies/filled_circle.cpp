#include "filled_circle.hpp"
#include <iostream>

Filled_Circle::Filled_Circle(Point c, int rad)
    : Circle( c, rad )
{}


void Filled_Circle::print() const
{
    // std::cout 
    //     << "[filled circle] center: " 
    //     << "(" << this->center_.x << ", " << this->center_.y << "), "
    //     << "radius: " << this->radius << std::endl;
}
