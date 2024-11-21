#include <iostream>
using namespace std;

class Vector {
private:
    int n;
    int *v;

public:
    Vector(int size = 0) : n(size) {
        v = new int[n];
    }

    Vector(const Vector& other) {
        n = other.n;
        v = new int[n];
        for (int i = 0; i < n; ++i) {
            v[i] = other.v[i];
        }
    }

    ~Vector() {
        delete[] v;
    }

    void input() {
        cout << "Nhap " << n << " phan tu: ";
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
    }

    void display() const {
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    bool sameSize(const Vector &other) const {
        return n == other.n;
    }

    friend Vector operator+(const Vector &v1, const Vector &v2);
};

Vector operator+(const Vector &v1, const Vector &v2) {
    Vector result(v1.n);
    for (int i = 0; i < v1.n; ++i) {
        result.v[i] = v1.v[i] + v2.v[i];
    }
    return result;
}

int main() {
    int size_1;
    cout << "Nhap so luong phan tu cua vector thu nhat: ";
    cin >> size_1;

    int size_2;
    cout << "Nhap so luong phan tu cua vector thu hai: ";
    cin >> size_2;

    Vector a(size_1), b(size_2);
    cout << "Nhap vector a:\n";
    a.input();
    cout << "Nhap vector b:\n";
    b.input();

    if (a.sameSize(b)) {
        Vector sum = a + b;
        cout << "Vector tong a + b: ";
        sum.display();
    } else {
        cout << "Hai vector khong cung kich thuoc, khong the cong!" << endl;
    }

    return 0;
}
