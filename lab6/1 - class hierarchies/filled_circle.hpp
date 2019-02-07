#ifndef CS3210_LAB6_FILLED_CIRCLE_HPP
#define CS3210_LAB6_FILLED_CIRCLE_HPP

#include "circle.hpp"

class Filled_Circle : public Circle {
public:
    Filled_Circle(Point c, int rad);
    void print() const override;
};

#endif // #ifndef CS3210_LAB6_FILLED_CIRCLE_HPP
