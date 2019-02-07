#ifndef CS3210_LAB6_SHAPE_HPP
#define CS3210_LAB6_SHAPE_HPP

struct Point {
    int x{};
    int y{};
};

class Shape {
public:
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;

    virtual void print() const = 0;
    virtual void rotate(int angle) = 0;

    virtual ~Shape() {}
    // ...
};

#endif // #ifndef CS3210_LAB6_VECTOR_HPP
