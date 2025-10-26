#pragma once
#include "figure.h"

class Triangle : public Figure {
public:
    Triangle();  // Конструктор по умолчанию
    using Figure::Figure;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};
