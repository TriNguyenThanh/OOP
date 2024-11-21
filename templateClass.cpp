#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;
public:
    int getTu() {return tu;}
    int getMau() {return mau;}
    void input(int x, int y) {tu = x; mau = y;}
};

template <class T> class Array
{
private:
    T* array;
    int n;
public:
    Array();
    ~Array();
    void Push(T x);
    void Output();
    void Sort();
    T Max();
};
template <class T> Array<T>::Array()
{
    array = nullptr;
    n = 0;
}
template <class T> Array<T>::~Array(){;}
template <class T> void Array<T>::Push(T x)
{
    int newSize = n+1;
    T* newArray = new T[newSize];
    for (int i = 0; i < n; ++i)
    {
        newArray[i] = array[i];
    }
    newArray[n] = x;

    delete array;
    array = newArray;
    n = newSize;
}
template <class T> void Array<T>::Output()
{
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << ' ';
    }
}
template <class T> void Array<T>::Sort()
{
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
        {
            if (array[i] > array[j])
            {
                T x = array[i];
                array[i] = array[j];
                array[j] = x;
            }
        }
}
template <class T> T Array<T>::Max()
{
    T max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max) max = array[i];
    }
    return max;
}
int main()
{
    Array<int> soNguyen;
    Array<float> soThuc;
    Array<PhanSo> phanSo;
    // so nguyen    
    int n, x;
    cout << "Nhap so luong so nguyen: "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        soNguyen.Push(x);
    }
    cout << "\nMang vua nhap: ";
    soNguyen.Output();

    soNguyen.Sort();
    cout << "\nMang sau khi sap xep: ";
    soNguyen.Output();

    cout << "\nSo lon nhat trong mang: " << soNguyen.Max();

    // so Thuc
    int n, x;
    cout << "Nhap so luong so Thuc: "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        soThuc.Push(x);
    }
    cout << "\nMang vua nhap: ";
    soThuc.Output();

    soThuc.Sort();
    cout << "\nMang sau khi sap xep: ";
    soThuc.Output();

    cout << "\nSo lon nhat trong mang: " << soThuc.Max();

        // so nguyen
    int n, x;
    cout << "Nhap so luong so nguyen: "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        soNguyen.Push(x);
    }
    cout << "\nMang vua nhap: ";
    soNguyen.Output();

    soNguyen.Sort();
    cout << "\nMang sau khi sap xep: ";
    soNguyen.Output();

    cout << "\nSo lon nhat trong mang: " << soNguyen.Max();
    return 0;
}