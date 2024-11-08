#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double Re; // Действительная часть
    double Im; // Мнимая часть

public:
    // Конструкторы
    Complex() : Re(0), Im(0) {}
    Complex(double r, double i) : Re(r), Im(i) {}
    Complex(const Complex& other) : Re(other.Re), Im(other.Im) {}

    // Метод сложения
    void add(const Complex& other) {
        Re += other.Re;
        Im += other.Im;
    }

    // Метод присвоения значений
    void assign(const Complex& other) {
        Re = other.Re;
        Im = other.Im;
    }

    // Дружественная функция сложения
    friend Complex addComplex(const Complex& a, const Complex& b) {
        return Complex(a.Re + b.Re, a.Im + b.Im);
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << "(" << c.Re << ", " << c.Im << ")";
        return os;
    }
};

#endif
