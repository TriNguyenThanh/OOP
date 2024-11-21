#include <iostream>
using namespace std;

class Vector
{
private:
    int n;
    int *data;
public:
    Vector(int n_);
    Vector(const Vector& other);
    ~Vector();
    void input();
    void print();
    Vector& operator=(Vector x);
    friend Vector operator+(Vector x1, Vector x2);
};

int main()  
{
    
    return 0;
}
Vector::Vector(int n_)
{
    n = n_;
    data = new int[n];
}
Vector::Vector(const Vector& other)
{
    this->n = other.n;
    data = new int[n];
    for (int i = 0; i < n; i++) {
        data[i] = other.data[i];
    }
}
Vector::~Vector() {;}
void Vector::input()
{
    cout << "Enter n: " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element at index " << i << ": ";
        cin >> data[i];
    }
}
void Vector::print()
{
    cout << "Vector: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
Vector& Vector::operator=(Vector other)
{
    if (this != &other) {
        delete[] data;
        n = other.n;
        data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}
Vector operator+(Vector v1, Vector v2)
{
    int size = (v1.n < v2.n) ? v1.n : v2.n;
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = v1.data[i] + v2.data[i];
    }
    return result;
}