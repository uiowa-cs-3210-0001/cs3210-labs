#ifndef CS3210_LAB6_CIRCLE_HPP
#define CS3210_LAB6_CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape {
public:
    Circle(Point c, int rad);

    Point center() const override { return this->center_; }
    void move(Point to) override { this->center_ = to; }

    void print() const override;
    void rotate(int) override {}

private:
     Point center_;
     int radius;
};

#endif // #ifndef CS3210_LAB6_CIRCLE_HPP
