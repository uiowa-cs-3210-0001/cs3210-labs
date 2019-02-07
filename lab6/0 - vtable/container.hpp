#ifndef CS3210_LAB6_CONTAINER_HPP
#define CS3210_LAB6_CONTAINER_HPP

class Container {
public:
     virtual double& operator[](int) = 0;     // pure virtual function
     virtual int size() const = 0;            // const member function (§4.2.1)
     virtual ~Container() {}                  // destructor (§4.2.2)
};

#endif // #ifndef CS3210_LAB6_CONTAINER_HPP
