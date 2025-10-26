#pragma once
#include "figure.h"

class Octagon : public Figure {
public:
    Octagon();
    using Figure::Figure;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};
