#pragma once
#include "figure.h"

class Hexagon : public Figure {
public:
    Hexagon();
    using Figure::Figure;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};
