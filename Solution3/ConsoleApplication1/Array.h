#ifndef ARRAY_H
#define ARRAY_H

#include "Complex.h"
#include <iostream>
using namespace std;

class Array {
private:
    Complex* arr; // Указатель на массив комплексных чисел
    int size;     // Размер массива

public:
    // Конструктор
    Array(int s) : size(s) {
        arr = new Complex[size];
    }

    // Конструктор копирования
    Array(const Array& other) : size(other.size) {
        arr = new Complex[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Деструктор
    ~Array() {
        delete[] arr;
    }

    // Перегрузка оператора []
    Complex& operator[](int index) {
        return arr[index];
    }

    // Перегрузка оператора += для сложения массивов
    Array& operator+=(const Array& other) {
        for (int i = 0; i < size && i < other.size; ++i) {
            arr[i].add(other.arr[i]);
        }
        return *this;
    }

    // Перегрузка оператора = для присваивания массивов
    Array& operator=(const Array& other) {
        if (this == &other) return *this; // Проверка самоприсваивания
        delete[] arr; // Удаляем старый массив
        size = other.size;
        arr = new Complex[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Array& a) {
        os << "[";
        for (int i = 0; i < a.size; ++i) {
            os << a.arr[i];
            if (i < a.size - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

#endif
