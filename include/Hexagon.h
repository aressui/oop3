#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figures.h"
#include <cmath>

class Hexagon : public Figure {
private:
    Point vertices[6];

public:
    Hexagon() = default;
    Point get_center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const { return area(); }

    Hexagon(const Hexagon& other);         
    Hexagon& operator=(const Hexagon& other);         
    Hexagon(Hexagon&& other) noexcept;       
    Hexagon& operator=(Hexagon&& other) noexcept;     
    bool operator==(const Hexagon& other) const;  
};

#endif