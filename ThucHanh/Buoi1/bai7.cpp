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
    bool operator>=(PS ps2);
    friend PS max(PS arr[], int n);
    friend PS min(PS arr[], int n);
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
PS max(PS arr[], int n)
{
    int max_i = 0;
    for (int i = 1; i < n; ++i)
    {  
        if (arr[i] >= arr[max_i]) max_i = i;
    }
    return arr[max_i];
}
PS min(PS arr[], int n)
{
    int max_i = 0;
    for (int i = 1; i < n; ++i)
    {  
        if (arr[max_i] >= arr[i]) max_i = i;
    }
    return arr[max_i];
}
int main()
{
    PS phanso[100];
    PS tong;
    int n; cout << "Nhap so luong phan so: "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        phanso[i].input();
    }
    cout << "Phan so lon nhat: "; max(phanso, n).print();
    cout << "Phan so nho nhat: "; min(phanso, n).print();
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
bool PS::operator>=(PS ps2)
{
    if (mau == ps2.mau && tu >= ps2.mau) return true;
    if (mau != ps2.mau && tu*ps2.mau >= ps2.tu * mau) return true;
    return false;
}