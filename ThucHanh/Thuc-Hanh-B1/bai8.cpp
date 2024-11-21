#include <iostream>
using namespace std;

class Vector {
private:
    int n;
    int *v;

public:
    Vector(int size = 0){
        n = size;
        v = new int[n];
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

    void print() const {
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    friend Vector operator*(double k, const Vector &other);
};

Vector operator*(double k, const Vector &other) {
    Vector result(other.n);
    for (int i = 0; i < other.n; ++i) {
        result.v[i] = other.v[i] * k;
    }
    return result;
}

int main() {
    int size;
    double k;
    cout << "Nhap so luong phan tu cua vector: ";
    cin >> size;

    Vector a(size);
    cout << "Nhap vector a:\n";
    a.input();

    cout << "Nhap so thuc k: ";
    cin >> k;

    Vector result = k * a;

    cout << "Vector a: ";
    a.print();
    cout << "Vector k * a: ";
    result.print();

    return 0;
}
