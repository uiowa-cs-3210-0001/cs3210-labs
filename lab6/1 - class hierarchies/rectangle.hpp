#ifndef CS3210_LAB6_RECTANGLE_HPP
#define CS3210_LAB6_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Point top_left, Point right_bottom);

    Point center() const override;
    void move(Point to) override;

    void print() const override;
    void rotate(int) override;

private:
    Point top_left;
    Point right_bottom;
};

#endif // #ifndef CS3210_LAB6_RECTANGLE_HPP
