#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <cmath> // для std::abs

class Figure {
public:
    struct Point {
        double x;
        double y;
    };
    using Points = std::vector<Point>;

protected:
    std::vector<Point> vertices; // Вершины фигуры

public:
    // --- Конструкторы ---
    Figure() = default;
    Figure(const std::vector<Point>& verts);
    Figure(std::vector<Point>&& verts) noexcept;
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;

    // --- Операторы присваивания ---
    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;

    // --- Виртуальные методы ---
    virtual bool operator==(const Figure& other) const;
    virtual double area() const;                   // Формула Гаусса
    virtual std::pair<double, double> center() const;
    virtual void print(std::ostream& os) const;
    virtual void read(std::istream& is);

    virtual ~Figure() = default;
};

// --- Вспомогательные операторы ---
std::ostream& operator<<(std::ostream& os, const Figure& f);
std::istream& operator>>(std::istream& is, Figure& f);
