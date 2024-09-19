#include <iostream>
#include <math.h>
using namespace std;

class SOPHUC{
private:
    int a;
    int b;
public:
    void setSophuc(int a, int b);
    int getReal();
    int getImag();
    float module();
    SOPHUC conjugate();
	friend istream& operator >>(istream &is, SOPHUC &p);
	friend ostream& operator <<(ostream &os, SOPHUC &p);
    SOPHUC operator+(SOPHUC x);
    SOPHUC operator-(SOPHUC x);
    SOPHUC operator*(SOPHUC x);
    SOPHUC operator/(SOPHUC x);
    int operator==(SOPHUC x);
    friend int tong(SOPHUC x);
};

int tong(SOPHUC x){
    
}

int main(){
    SOPHUC n, n2;
    int x, y;
    
    cout << "Nhap a, b cua so phuc a + bi: "; cin >> n;
    cout << "\nn1 = "; cout << n;

    cout << "\nNhap lai he so a, b: "; cin >> x >> y;
    n.setSophuc(x, y);
    cout << "\nSo phuc sau thay doi: "; cout << n;

    cout << "\nNhap a, b cua so phuc thu hai: "; cin >> n2;
    cout << "\nn2 = "; cout << n2;

    SOPHUC tmp;
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

istream& operator >>(istream &is, SOPHUC &p){
    cout << "\nNhap phan thuc, phan ao: ";
    is >> p.a >> p.b;

    return is;
}
ostream& operator <<(ostream &os, SOPHUC &p){
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

void SOPHUC::setSophuc(int a, int b){
    this->a = a;
    this->b = b;
}
int SOPHUC::getReal(){
    return a;
}
int SOPHUC::getImag(){
    return b;
}
float SOPHUC::module(){
    return sqrt((double) (a*a + b*b));
}
SOPHUC SOPHUC::conjugate(){
    SOPHUC x;
    x.a = a;
    x.b = -b;

    return x;
}
SOPHUC SOPHUC:: operator +(SOPHUC x){
    SOPHUC n;
    n.a = a + x.a;
    n.b = b + x.b;

    return n;
}
SOPHUC SOPHUC::operator-(SOPHUC x){
    SOPHUC n;
    n.a = a - x.a;
    n.b = b - x.b;

    return n;
}
SOPHUC SOPHUC::operator*(SOPHUC x){
    SOPHUC n;
    n.a = a*x.a - b*x.b;
    n.b = a*x.b + b*x.a;

    return n;
}
SOPHUC SOPHUC::operator/(SOPHUC x){
    SOPHUC n;
    n.a = (a*x.a + b*x.b)/(a*a + b*b);
    n.b = (a*x.b + b*x.a)/(a*a + b*b);

    return n;
}
int SOPHUC::operator==(SOPHUC x){
    int tmp = this->module() - x.module();
    if (tmp == 0) return 0;
    if (tmp < 0) return -1;
    if (tmp > 0) return 1;
}