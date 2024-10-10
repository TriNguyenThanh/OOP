#include <iostream>
#include <math.h>
using namespace std;

class SoPhuc{
private:
    int a;
    int b;
public:
    SoPhuc();
    SoPhuc(int a, int b);
    SoPhuc(const SoPhuc &sp);
    void setSoPhuc(int a, int b);
    int getReal();
    int getImag();
    float module();
    SoPhuc conjugate();
	friend istream& operator >>(istream &is, SoPhuc &p);
	friend ostream& operator <<(ostream &os, SoPhuc &p);
    SoPhuc operator+(SoPhuc x);
    SoPhuc operator-(SoPhuc x);
    SoPhuc operator*(SoPhuc x);
    SoPhuc operator/(SoPhuc x);
    int operator==(SoPhuc x);
    friend int tong(SoPhuc x);
};

SoPhuc::SoPhuc(){
    a = b = 1;
}
SoPhuc::SoPhuc(int a, int b){
    this->a = a;
    this->b = b;
}
SoPhuc::SoPhuc(const SoPhuc &sp){
    a = sp.a;
    b = sp.b;
}

int main(){
    SoPhuc n, n2;
    int x, y;
    
    cout << "Nhap a, b cua so phuc a + bi: "; cin >> n;
    cout << "\nn1 = "; cout << n;

    cout << "\nNhap lai he so a, b: "; cin >> x >> y;
    n.setSoPhuc(x, y);
    cout << "\nSo phuc sau thay doi: "; cout << n;

    cout << "\nNhap a, b cua so phuc thu hai: "; cin >> n2;
    cout << "\nn2 = "; cout << n2;

    SoPhuc tmp;
    tmp = n + n2;
    cout << "\nTong la: "; cout << tmp;

    tmp = n - n2;
    cout << "\nHieu la: ";cout << tmp;

    tmp = n * n2;
    cout << "\nTich la: ";cout << tmp;

    tmp = n/n2;
    cout << "\nThuong la: ";cout << tmp;
    
    cout << '\n';
    switch (n == n2)
    {
    case -1:
        cout << "n1 ngan hon n2";
        break;
    case 0:
        cout << "n1 bang n2";
        break;
    case 1:
        cout << "n1 dai hon n2";
        break;
    }
    return 0;
}

istream& operator >>(istream &is, SoPhuc &p){
    cout << "\nNhap phan thuc, phan ao: ";
    is >> p.a >> p.b;

    return is;
}
ostream& operator <<(ostream &os, SoPhuc &p){
    if (p.a != 0){
        os << p.a;
        if (p.b > 0) os << " + ";
    }
    if (p.b < 0) os << " - ";
    if (p.b != 0){
        if (p.b != 1) os << p.b;
        os << 'i';
    }

    return os;
}

void SoPhuc::setSoPhuc(int a, int b){
    this->a = a;
    this->b = b;
}
int SoPhuc::getReal(){
    return a;
}
int SoPhuc::getImag(){
    return b;
}
float SoPhuc::module(){
    return sqrt((double) (a*a + b*b));
}
SoPhuc SoPhuc::conjugate(){
    SoPhuc x;
    x.a = a;
    x.b = -b;

    return x;
}
SoPhuc SoPhuc:: operator +(SoPhuc x){
    SoPhuc n;
    n.a = a + x.a;
    n.b = b + x.b;

    return n;
}
SoPhuc SoPhuc::operator-(SoPhuc x){
    SoPhuc n;
    n.a = a - x.a;
    n.b = b - x.b;

    return n;
}
SoPhuc SoPhuc::operator*(SoPhuc x){
    SoPhuc n;
    n.a = a*x.a - b*x.b;
    n.b = a*x.b + b*x.a;

    return n;
}
SoPhuc SoPhuc::operator/(SoPhuc x){
    SoPhuc n;
    n.a = (a*x.a + b*x.b)/(a*a + b*b);
    n.b = (a*x.b + b*x.a)/(a*a + b*b);

    return n;
}
int SoPhuc::operator==(SoPhuc x){
    int tmp = this->module() - x.module();
    if (tmp == 0) return 0;
    if (tmp < 0) return -1;
    if (tmp > 0) return 1;
}