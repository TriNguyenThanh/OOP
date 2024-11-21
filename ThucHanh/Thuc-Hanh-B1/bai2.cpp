#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double a, b;

public:
    Complex(double a_ = 0, double b_ = 0) {a = a_; b = b_;}

    void input() {
        cout << "Nhap phan thuc: "; cin >> a;
        cout << "Nhap phan ao: "; cin >> b;
    }

    void print() const {
        cout << a << " + " << b << "i" << endl;
    }

    Complex& operator=(const Complex &c) {
        a = c.a;
        b = c.b;
        return *this;
    }

    Complex operator+(const Complex &c) const {
        return Complex(a + c.a, b + c.b);
    }
};

int main() {
    int n;
    cout << "Nhap so luong so phuc: ";
    cin >> n;

    vector<Complex> arr(n);
    Complex sum;

    for (int i = 0; i < n; ++i) {
        cout << "Nhap so phuc thu " << i + 1 << ":\n";
        arr[i].input();
        sum = sum + arr[i];
    }

    cout << "Tong cac so phuc: ";
    sum.print();

    return 0;
}
