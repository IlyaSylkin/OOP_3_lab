#include "figure_array.h"

// ===== Конструкторы =====
FigureArray::FigureArray() : data(nullptr), capacity(0), count(0) {}

FigureArray::FigureArray(const FigureArray& other) : capacity(other.capacity), count(other.count) {
    data = new Figure*[capacity];
    for (size_t i = 0; i < count; ++i) {
        data[i] = other.data[i]; // просто копируем указатели
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept
    : data(other.data), capacity(other.capacity), count(other.count) {
    other.data = nullptr;
    other.capacity = 0;
    other.count = 0;
}

// ===== Операторы присваивания =====
FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        for (size_t i = 0; i < count; ++i) delete data[i];
        delete[] data;

        capacity = other.capacity;
        count = other.count;
        data = new Figure*[capacity];
        for (size_t i = 0; i < count; ++i)
            data[i] = other.data[i]; // копирование указателей
    }
    return *this;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < count; ++i) delete data[i];
        delete[] data;

        data = other.data;
        capacity = other.capacity;
        count = other.count;

        other.data = nullptr;
        other.capacity = 0;
        other.count = 0;
    }
    return *this;
}

// ===== Деструктор =====
FigureArray::~FigureArray() {
    for (size_t i = 0; i < count; ++i)
        delete data[i];
    delete[] data;
}

// ===== Методы =====
void FigureArray::resize(size_t newCapacity) {
    Figure** newData = new Figure*[newCapacity];
    for (size_t i = 0; i < count; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void FigureArray::push_back(Figure* f) {
    if (count >= capacity) {
        resize(capacity == 0 ? 2 : capacity * 2);
    }
    data[count++] = f;
}

void FigureArray::remove(size_t index) {
    if (index >= count) return;
    delete data[index];
    for (size_t i = index; i < count - 1; ++i)
        data[i] = data[i + 1];
    --count;
}

size_t FigureArray::size() const { return count; }

Figure* FigureArray::operator[](size_t index) { return data[index]; }
const Figure* FigureArray::operator[](size_t index) const { return data[index]; }

double FigureArray::totalArea() const {
    double sum = 0;
    for (size_t i = 0; i < count; ++i)
        sum += data[i]->area();
    return sum;
}

void FigureArray::printAll() const {
    for (size_t i = 0; i < count; ++i) {
        std::cout << "Figure " << i << ": " << *data[i]
                  << ", center=(" << data[i]->center().first << ", " << data[i]->center().second << ")"
                  << ", area=" << data[i]->area() << "\n";
    }
}
