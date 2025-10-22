#include "../include/Octagon.h"
#include <iostream>
#include <cmath>

Octagon::Octagon(const Octagon& other) {
    for (int i = 0; i < 8; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Octagon::Octagon(Octagon&& other) noexcept {
    for (int i = 0; i < 8; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Octagon::operator==(const Octagon& other) const {
    for (int i = 0; i < 8; ++i) {
        if (vertices[i].x != other.vertices[i].x || 
            vertices[i].y != other.vertices[i].y) {
            return false;
        }
    }
    return true;
}

Point Octagon::get_center() const {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < 8; ++i) {
        sum_x += vertices[i].x;
        sum_y += vertices[i].y;
    }
    return Point(sum_x / 8, sum_y / 8);
}

double Octagon::area() const {
    double area = 0;
    for (int i = 0; i < 8; ++i) {
        int j = (i + 1) % 8;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

void Octagon::print(std::ostream& os) const {
    os << "Octagon vertices: ";
    for (int i = 0; i < 8; ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i < 7) os << " ";
    }
}

void Octagon::read(std::istream& is) {
    for (int i = 0; i < 8; ++i) {
        is >> vertices[i].x >> vertices[i].y;
    }
}