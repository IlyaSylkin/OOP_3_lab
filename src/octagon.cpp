#include "octagon.h"
#include <iostream>

Octagon::Octagon() : Figure(std::vector<Point>(8)) {}

void Octagon::print(std::ostream& os) const {
    Figure::print(os);
}

void Octagon::read(std::istream& is) {
    Figure::read(is);
    if (vertices.size() != 8) throw std::runtime_error("Octagon: expected 8 points");
}
