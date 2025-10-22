#include "../include/Hexagon.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon(const Hexagon& other) {
    for (int i = 0; i < 6; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        for (int i = 0; i < 6; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Hexagon::Hexagon(Hexagon&& other) noexcept {
    for (int i = 0; i < 6; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 6; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Hexagon::operator==(const Hexagon& other) const {
    for (int i = 0; i < 6; ++i) {
        if (vertices[i].x != other.vertices[i].x || 
            vertices[i].y != other.vertices[i].y) {
            return false;
        }
    }
    return true;
}

Point Hexagon::get_center() const {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < 6; ++i) {
        sum_x += vertices[i].x;
        sum_y += vertices[i].y;
    }
    return Point(sum_x / 6, sum_y / 6);
}

double Hexagon::area() const {
    double area = 0;
    for (int i = 0; i < 6; ++i) {
        int j = (i + 1) % 6; 
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

void Hexagon::print(std::ostream& os) const {
    os << "Hexagon vertices: ";
    for (int i = 0; i < 6; ++i) { 
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i < 5) os << " ";   
    }
}

void Hexagon::read(std::istream& is) {
    for (int i = 0; i < 6; ++i) {
        is >> vertices[i].x >> vertices[i].y;
    }
}