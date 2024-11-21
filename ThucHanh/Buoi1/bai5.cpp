#include <iostream>
using namespace std;

class PS
{
private:
    int tu;
    int mau;
public:
    PS() {tu = 0; mau = 1;}
    ~PS() {}
    void input();
    void print();
    void shorten();
    PS operator+(PS ps2);
    PS operator-(PS ps2);
    PS operator*(PS ps2);
    PS operator/(PS ps2);
    PS& operator=(PS ps2);
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main()
{
    PS phanso[100];
    PS tong;
    int n; cout << "Nhap so luong phan so: "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        phanso[i].input();
        if (i == 0)
            tong = phanso[0];
        else
            tong = tong + phanso[i];
        tong.shorten();
    }
    cout << "\nTong: "; tong.print();
    return 0;
}
void PS::input()
{
    cout << "Nhap tu so: "; cin >> tu;
    cout << "Nhap mau so: "; cin >> mau;
    while (mau == 0)
    {
        cout << "Nhap lai mau so khac 0: ";
    }   
}
void PS::print()
{
    if (mau == 1)
        cout << tu;
    else if (tu == 0)
        cout << '0';
    else cout << tu << '/' << mau;
}
void PS::shorten()
{
    int heso = gcd(tu, mau);
    tu /= heso;
    mau /= heso;
}
PS PS::operator+(PS ps2)
{
    PS tmp;
    tmp.tu = tu*ps2.mau + ps2.tu*mau;
    tmp.mau = mau*ps2.mau;

    tmp.shorten();
    return tmp;
}
PS PS::operator-(PS ps2)
{
    PS tmp;
    tmp.tu = tu*ps2.mau - ps2.tu*mau;
    tmp.mau = mau*ps2.mau;

    tmp.shorten();
    return tmp;

}
PS PS::operator*(PS ps2)
{
    PS tmp;
    tmp.tu = tu*ps2.tu;
    tmp.mau = mau*ps2.mau;
    tmp.shorten();

    return tmp;
}
PS PS::operator/(PS ps2)
{
    PS tmp;
    tmp.tu = tu * ps2.mau;
    tmp.mau = mau * ps2.tu;

    tmp.shorten();
    return tmp;
}
PS& PS::operator=(PS ps2)
{
    this->tu = ps2.tu;
    this->mau = ps2.mau;

    return *this;
}