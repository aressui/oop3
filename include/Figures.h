#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point get_center() const = 0;
    virtual double area() const = 0; 
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);

#endif