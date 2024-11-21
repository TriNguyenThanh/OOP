#include <iostream>
using namespace std;

class Vector {
    private:
        int length;
        int* data;
    public:
        Vector(int size = 0) : length(size) { data = new int[size]; } 

        Vector(const Vector& other) {
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }
        
        ~Vector() {
            delete[] data;
        }

        void input() {
            cout << "Enter length: " << length << endl;
            for (int i = 0; i < length; i++) {
                cout << "Enter element at index " << i << ": ";
                cin >> data[i];
            }
        }

        void display() const {
            cout << "Vector: ";
            for (int i = 0; i < length; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        Vector& operator=(const Vector& other) {
            if (this != &other) {
                delete[] data;
                length = other.length;
                data = new int[length];
                for (int i = 0; i < length; i++) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        friend Vector operator+(const Vector &v1, const Vector &v2);
};

Vector operator+(const Vector &v1, const Vector &v2) {
    int size = (v1.length < v2.length) ? v1.length : v2.length;
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = v1.data[i] + v2.data[i];
    }
    return result;
}

int main() {
    int size;
    cout << "Nhap so luong phan tu cua vector: ";
    cin >> size;

    Vector a(size), b(size);
    cout << "Nhap vector a:\n";
    a.input();
    cout << "Nhap vector b:\n";
    b.input();

    Vector sum = a + b;

    cout << "Vector a: ";
    a.display();
    cout << "Vector b: ";
    b.display();
    cout << "Tong vector a + b: ";
    sum.display();

    return 0;
}