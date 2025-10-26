#include "figure.h"
#include <iomanip>
#include <cmath>

// --- Конструкторы ---
Figure::Figure(const std::vector<Point>& verts) : vertices(verts) {}
Figure::Figure(std::vector<Point>&& verts) noexcept : vertices(std::move(verts)) {}
Figure::Figure(const Figure& other) : vertices(other.vertices) {}
Figure::Figure(Figure&& other) noexcept : vertices(std::move(other.vertices)) {}

// --- Операторы присваивания ---
Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

// --- Сравнение ---
bool Figure::operator==(const Figure& other) const {
    if (vertices.size() != other.vertices.size()) return false;
    for (size_t i = 0; i < vertices.size(); ++i)
        if (vertices[i].x != other.vertices[i].x || vertices[i].y != other.vertices[i].y)
            return false;
    return true;
}

// --- Площадь (формула Гаусса) ---
double Figure::area() const {
    double a = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % n];
        a += p1.x * p2.y - p2.x * p1.y;
    }
    return std::abs(a) / 2.0;
}

// --- Центр фигуры ---
std::pair<double, double> Figure::center() const {
    double cx = 0.0, cy = 0.0;
    for (const auto& p : vertices) {
        cx += p.x;
        cy += p.y;
    }
    size_t n = vertices.size();
    if (n == 0) return {0.0, 0.0};
    return {cx / n, cy / n};
}

void Figure::print(std::ostream& os) const {
    os << vertices.size();
    for (const auto& p : vertices) {
        os << " " << p.x << " " << p.y;
    }
}

void Figure::read(std::istream& is) {
    size_t n;
    if (!(is >> n)) return;            // если чтение не удалось — уходим
    vertices.resize(n);
    for (size_t i = 0; i < n; ++i) {
        is >> vertices[i].x >> vertices[i].y;
    }
}

// --- Глобальные операторы ---
std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& f) {
    f.read(is);
    return is;
}
