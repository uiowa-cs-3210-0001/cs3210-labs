#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(Point top_left, Point right_bottom)
    : top_left( top_left ), right_bottom( right_bottom )
{}

Point Rectangle::center() const
{
    return Point{
        ( this->right_bottom.x - this->top_left.x ) / 2,
        ( this->right_bottom.y - this->top_left.y ) / 2
    };
}

void Rectangle::move(Point to)
{
    // TODO
}


void Rectangle::print() const
{
    std::cout 
        << "[rectangle]: " 
        << "(" << this->top_left.x << ", " << this->top_left.y << "), "
        << "(" << this->right_bottom.x << ", " << this->right_bottom.y << ")"
        << std::endl;
}


void Rectangle::rotate(int)
{
    // TODO
}
