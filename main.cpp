#include <iostream>
#include "figure_array.h"
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

int main()
{
    FigureArray figures;

    int choice;
    while (true)
    {
        std::cout << "\n=== МЕНЮ ===\n";
        std::cout << "1. Добавить треугольник\n";
        std::cout << "2. Добавить шестиугольник\n";
        std::cout << "3. Добавить восьмиугольник\n";
        std::cout << "4. Показать все фигуры\n";
        std::cout << "5. Показать общую площадь\n";
        std::cout << "6. Удалить фигуру по индексу\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice == 0)
            break;

        Figure *f = nullptr;

        switch (choice)
        {
        case 1:
        {
            auto *t = new Triangle();
            std::cout << "\nВведите данные для треугольника.\n";
            std::cout << "Формат: <число вершин> x1 y1 x2 y2 x3 y3\n";
            std::cout << "Пример: 3 0 0 3 0 0 4\n";
            std::cout << "Ваш ввод: ";
            std::cin >> *t;
            f = t;
            break;
        }
        case 2:
        {
            auto *h = new Hexagon();
            std::cout << "\nВведите данные для шестиугольника.\n";
            std::cout << "Формат: <число вершин> x1 y1 x2 y2 ... x6 y6\n";
            std::cout << "Пример: 6 0 0 1 0 2 1 2 2 1 3 0 2\n";
            std::cout << "Ваш ввод: ";
            std::cin >> *h;
            f = h;
            break;
        }
        case 3:
        {
            auto *o = new Octagon();
            std::cout << "\nВведите данные для восьмиугольника.\n";
            std::cout << "Формат: <число вершин> x1 y1 x2 y2 ... x8 y8\n";
            std::cout << "Пример: 8 0 0 1 0 2 1 2 2 1 3 0 3 -1 2 -1 1\n";
            std::cout << "Ваш ввод: ";
            std::cin >> *o;
            f = o;
            break;
        }
        case 4:
        {
            std::cout << "\nСписок фигур\n";
            figures.printAll();
            continue;
        }
        case 5:
        {
            std::cout << "Общая площадь: " << figures.totalArea() << "\n";
            continue;
        }
        case 6:
        {
            size_t index;
            std::cout << "Введите индекс фигуры для удаления: ";
            std::cin >> index;
            figures.remove(index);
            continue;
        }
        default:
            std::cout << "Неверный выбор, попробуйте снова.\n";
            continue;
        }

        if (f != nullptr)
        {
            figures.push_back(f);
            std::cout << "Фигура добавлена.\n";
        }
    }

    std::cout << "\nВыход из программы.\n";
    return 0;
}
