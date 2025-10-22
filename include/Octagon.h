#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figures.h"
#include <cmath>

class Octagon : public Figure {
private:
    Point vertices[8];

public:
    Octagon() = default;
    Point get_center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const { return area(); }

    Octagon(const Octagon& other);        
    Octagon& operator=(const Octagon& other);        
    Octagon(Octagon&& other) noexcept;      
    Octagon& operator=(Octagon&& other) noexcept;    
    bool operator==(const Octagon& other) const;  
};

#endif