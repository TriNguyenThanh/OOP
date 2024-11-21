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
    bool operator>(PS ps2);
    PS operator=(PS ps2);
    friend void swap(PS &ps1, PS &ps2);
    friend void sortPS(PS arr[]);
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void swap(PS &ps1, PS &ps2) {
    int tempTu = ps1.tu;
    int tempMau = ps1.mau;
    ps1.tu = ps2.tu;
    ps1.mau = ps2.mau;
    ps2.tu = tempTu;
    ps2.mau = tempMau;
}

void sortPS(PS arr[], int n) { 
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) { 
                swap(arr[i], arr[j]);
            }
        }
    }
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
    sortPS(phanso, n);
    cout << "\nDanh sach phan so sau khi sap xep: ";
    for (int i = 0; i < n; ++i)
    {
        phanso[i].print();
        cout << ' ';
    }
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
PS PS::operator=(PS ps2)
{
    tu = ps2.tu;
    mau = ps2.mau;
}
bool PS::operator>(PS ps2)
{
    if (mau == ps2.mau && tu > ps2.mau) return true;
    if (mau != ps2.mau && tu*ps2.mau > ps2.tu * mau) return true;
    return false;
}