#include <iostream>
using namespace std;

class Vector {
private:
    int n;
    int *v;

public:
    Vector(int size = 0) : n(size) {
        v = new int[n];
        for (int i = 0; i < n; ++i) v[i] = 0; 
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

    int size() const {
        return n;
    }

    int getValue(int index) const {
        return (index < n) ? v[index] : 0;  
    }

    friend Vector operator+(const Vector &v1, const Vector &v2);
};

Vector operator+(const Vector &v1, const Vector &v2) {
    int size = max(v1.size(), v2.size()); 
    Vector result(size);

    for (int i = 0; i < size; ++i) {
        result.v[i] = v1.getValue(i) + v2.getValue(i);
    }
    return result;
}

int main() {
    int size1, size2;
    cout << "Nhap so luong phan tu cua vector a: ";
    cin >> size1;
    Vector a(size1);

    cout << "Nhap vector a:\n";
    a.input();

    cout << "Nhap so luong phan tu cua vector b: ";
    cin >> size2;
    Vector b(size2);

    cout << "Nhap vector b:\n";
    b.input();

    Vector sum = a + b;
    cout << "Tong cua vector a va b:\n";
    sum.display();

    return 0;
}
