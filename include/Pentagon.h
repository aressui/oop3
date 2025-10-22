#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figures.h"
#include <cmath>

class Pentagon : public Figure {
private:
    Point vertices[5];

public:
    Pentagon() = default;
    Point get_center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const { return area(); }

    Pentagon(const Pentagon& other);         
    Pentagon& operator=(const Pentagon& other);         
    Pentagon(Pentagon&& other) noexcept;       
    Pentagon& operator=(Pentagon&& other) noexcept;     
    bool operator==(const Pentagon& other) const;  
};

#endif