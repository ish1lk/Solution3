#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double Re; // �������������� �����
    double Im; // ������ �����

public:
    // ������������
    Complex() : Re(0), Im(0) {}
    Complex(double r, double i) : Re(r), Im(i) {}
    Complex(const Complex& other) : Re(other.Re), Im(other.Im) {}

    // ����� ��������
    void add(const Complex& other) {
        Re += other.Re;
        Im += other.Im;
    }

    // ����� ���������� ��������
    void assign(const Complex& other) {
        Re = other.Re;
        Im = other.Im;
    }

    // ������������� ������� ��������
    friend Complex addComplex(const Complex& a, const Complex& b) {
        return Complex(a.Re + b.Re, a.Im + b.Im);
    }

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << "(" << c.Re << ", " << c.Im << ")";
        return os;
    }
};

#endif
