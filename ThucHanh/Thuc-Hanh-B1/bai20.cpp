#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    void input() {
        cout << "Nhap phan thuc: ";
        cin >> real;
        cout << "Nhap phan ao: ";
        cin >> imag;
    }

    void display() const {
        cout << real << " + " << imag << "i";
    }
};

int main() {
    Complex c1, c2;
    cout << "So phuc thu nhat: ";
    c1.input();
    cout << "So phuc thu hai: ";
    c2.input();

    Complex sum = c1 + c2;
    cout << "Tong 2 phan so: ";
    sum.display();

    Complex diff = c1 - c2;
    cout << "\nHieu 2 phan so: ";
    diff.display();

    return 0;
}
