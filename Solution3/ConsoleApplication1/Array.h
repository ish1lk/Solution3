#ifndef ARRAY_H
#define ARRAY_H

#include "Complex.h"
#include <iostream>
using namespace std;

class Array {
private:
    Complex* arr; // ��������� �� ������ ����������� �����
    int size;     // ������ �������

public:
    // �����������
    Array(int s) : size(s) {
        arr = new Complex[size];
    }

    // ����������� �����������
    Array(const Array& other) : size(other.size) {
        arr = new Complex[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // ����������
    ~Array() {
        delete[] arr;
    }

    // ���������� ��������� []
    Complex& operator[](int index) {
        return arr[index];
    }

    // ���������� ��������� += ��� �������� ��������
    Array& operator+=(const Array& other) {
        for (int i = 0; i < size && i < other.size; ++i) {
            arr[i].add(other.arr[i]);
        }
        return *this;
    }

    // ���������� ��������� = ��� ������������ ��������
    Array& operator=(const Array& other) {
        if (this == &other) return *this; // �������� ����������������
        delete[] arr; // ������� ������ ������
        size = other.size;
        arr = new Complex[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // ���������� ��������� ������
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
