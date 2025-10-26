#include "hexagon.h"
#include <iostream>

Hexagon::Hexagon() : Figure(std::vector<Point>(6)) {}

void Hexagon::print(std::ostream& os) const {
    Figure::print(os);
}

void Hexagon::read(std::istream& is) {
    Figure::read(is);
    if (vertices.size() != 6) throw std::runtime_error("Hexagon: expected 6 points");
}