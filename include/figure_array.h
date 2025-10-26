#pragma once
#include "figure.h"
#include <cstddef> // для size_t
#include <iostream>

class FigureArray {
public:
    FigureArray();
    FigureArray(const FigureArray& other);           // копирование
    FigureArray(FigureArray&& other) noexcept;       // перемещение
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;
    ~FigureArray();

    void push_back(Figure* f);      // добавить фигуру
    void remove(size_t index);      // удалить фигуру по индексу
    size_t size() const;            // количество фигур
    Figure* operator[](size_t index);          // доступ по индексу
    const Figure* operator[](size_t index) const;

    double totalArea() const;       // общая площадь всех фигур
    void printAll() const;          // печать всех фигур с центрами и площадями

private:
    Figure** data;      // массив указателей на фигуры
    size_t capacity;    // текущая емкость массива
    size_t count;       // количество элементов

    void resize(size_t newCapacity);
};
