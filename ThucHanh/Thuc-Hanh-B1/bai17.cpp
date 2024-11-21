#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    void input() {
        cout << "Nhap phan thuc: ";
        cin >> real;
        cout << "Nhap phan ao: ";
        cin >> imag;
    }

    void display() const {
        cout << real << " + " << imag << "i";
    }

    bool operator==(const Complex &other) const {
        return real == other.real && imag == other.imag;
    }
};

int main() {
    int n;
    cout << "Nhap so luong so phuc: ";
    cin >> n;

    vector<Complex> arr(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap so phuc thu " << i + 1 << ":\n";
        arr[i].input();
    }

    Complex x;
    cout << "Nhap so phuc can tim:\n";
    x.input();

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            cout << "So phuc can tim o vi tri " << i + 1 << " trong mang.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "So phuc can tim khong co trong mang.\n";
    }

    return 0;
}
