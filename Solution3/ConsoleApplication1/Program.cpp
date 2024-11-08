#include <iostream>
#include "Complex.h"
#include "Array.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем объекты Complex
    Complex x(1.3, 4.2), y(4.0, 8.1), z(y);
    z.assign(addComplex(x, y)); // Присваиваем z сумму x и y
    cout << "Сумма x и y присвоена z: " << z << endl;

    // Создаем и инициализируем объекты Array
    Array a1(10), a2(10);
    (a1[0]).assign(y); // Присваиваем y первому элементу a1
    a2 += a1; // Складываем массив a1 к a2
    a1 = a2; // Присваиваем a2 к a1
    cout << "Массив a2 после сложения с a1: " << a2 << endl;

    return 0;
}
