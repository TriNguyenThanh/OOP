#include <iostream>
using namespace std;

class Complex {
private:
    double a, b;  
public:
    Complex(int a_ = 0, int b_ = 0) {a = a_; b = b_;}
    void input();
    void print();
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
};
Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.a + c2.a, c1.b + c2.b);
}
Complex operator-(const Complex &c1, const Complex &c2) {
    return Complex(c1.a - c2.a, c1.b - c2.b);
}
void Complex::input() {
    cout << "Nhap phan thuc: "; cin >> a;
    cout << "Nhap phan ao: "; cin >> b;
}
void Complex::print()
{
    cout << a;
    if (b > 0) cout << " + ";
    if (b < 0)
    {
        cout << " - ";
        b *= -1;
    }
    cout << b << "i";
}
int main() {
    Complex x, y;
    
    cout << "Nhap so phuc x:\n"; x.input();
    cout << "Nhap so phuc y:\n"; y.input();

    Complex sum = x + y;
    Complex diff = x - y;

    cout << "Tong hai so phuc: "; sum.print();
    cout << "Hieu hai so phuc: "; diff.print();

    return 0;
}
