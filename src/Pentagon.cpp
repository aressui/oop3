#include "../include/Pentagon.h"
#include <iostream>
#include <cmath>

Pentagon::Pentagon(const Pentagon& other) {
    for (int i = 0; i < 5; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        for (int i = 0; i < 5; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    for (int i = 0; i < 5; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 5; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
    for (int i = 0; i < 5; ++i) {
        if (vertices[i].x != other.vertices[i].x || 
            vertices[i].y != other.vertices[i].y) {
            return false;
        }
    }
    return true;
}

Point Pentagon::get_center() const {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < 5; ++i) {
        sum_x += vertices[i].x;
        sum_y += vertices[i].y;
    }
    return Point(sum_x / 5, sum_y / 5);
}

double Pentagon::area() const {
    double area = 0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon vertices: ";
    for (int i = 0; i < 5; ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i < 4) os << " ";
    }
}

void Pentagon::read(std::istream& is) {
    for (int i = 0; i < 5; ++i) {
        is >> vertices[i].x >> vertices[i].y;
    }
}