#include "triangle.h"
#include <iostream>

Triangle::Triangle() : Figure(std::vector<Point>(3)) {}

void Triangle::print(std::ostream& os) const {
    Figure::print(os);
}

void Triangle::read(std::istream& is) {
    Figure::read(is);
    if (vertices.size() != 3) throw std::runtime_error("Triangle: expected 3 points");
}
