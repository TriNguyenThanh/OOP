#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;
public:
    PhanSo(int a, int b);
    ~PhanSo();
    void output()
    {
        cout << tu << '/' << mau;
    }
    PhanSo operator+(PhanSo x);
    PhanSo operator*(int x);
    bool operator<(int x);
    PhanSo ABS(PhanSo x);
};

PhanSo::PhanSo(int a, int b)
{
    tu = a;
    mau = b;

    if (mau < 0)
    {
        mau *= -1;
        tu *= -1;
    }
}
PhanSo::~PhanSo()
{
    tu = 0;
    mau = 1;
}
PhanSo PhanSo::operator + (PhanSo x)
{
    PhanSo result(1, 1);
    if (this->mau == x.mau)
    {
        result.tu = this->tu + x.tu;
        result.mau = this->mau;
    }
    else
    {
        result.mau = this->mau * x.mau;
        result.tu = this->tu * x.mau + this->mau * x.tu;
    }
    return result;
}
PhanSo PhanSo::operator * (int x)
{
    tu *= x;
}
bool PhanSo::operator < (int x)
{
    return (tu < x*mau);
}
PhanSo PhanSo::ABS(PhanSo x)
{
    PhanSo tmp(tu, mau);
    if (tu < 0) tmp.tu = 0 - tu;
    if (mau < 0) tmp.mau = 0 - mau; 

    return tmp;
}

template <class T> T operator+(T x1, T x2)
{
    return x1 + x2;
}

template <class T> T ABS(T &x)
{
    if (x < 0)
        x *= -1;
    return x;
}

int main()
{
    PhanSo p1(2, 5), p2(4, 5);
    PhanSo p3 = p1 + p2;
    p3.output();
    cout << '\n';
    PhanSo p4(-3, 5);
    PhanSo p5 = p4.ABS(p4);
    p5.output();
    return 0;
}