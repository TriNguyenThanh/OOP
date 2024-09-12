#include <iostream>
#include <math.h>
using namespace std;

class SOPHUC{
private:
    int a;
    int b;
public:
    void input();
    void print();
    void setSophuc(int a, int b);
    int getReal();
    int getImag();
    float module();
    SOPHUC conjugate();
    SOPHUC add(SOPHUC x);
    SOPHUC sub(SOPHUC x);
    SOPHUC MULTI(SOPHUC x);
    SOPHUC DIV(SOPHUC x);
    int compare(SOPHUC x);
    friend int tong(SOPHUC x);
};

int tong(SOPHUC x){
    
}

int main(){
    SOPHUC n, n2;
    int x, y;
    
    cout << "Nhap a, b cua so phuc a + bi: "; n.input();
    cout << "\nn1 = "; n.print();

    cout << "\nNhap lai he so a, b: "; cin >> x >> y;
    n.setSophuc(x, y);
    cout << "\nSo phuc sau thay doi: "; n.print();

    cout << "\nNhap a, b cua so phuc thu hai: "; n2.input();
    cout << "\nn2 = "; n2.print();

    SOPHUC tmp;
    tmp = n.add(n2);
    cout << "\nTong la: "; tmp.print();

    tmp = n.sub(n2);
    cout << "\nHieu la: ";tmp.print();

    tmp = n.MULTI(n2);
    cout << "\nTich la: ";tmp.print();

    tmp = n.DIV(n2);
    cout << "\nThuong la: ";tmp.print();
    
    cout << '\n';
    switch (n.compare(n2))
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
void SOPHUC::input(){
    cin>>a>>b;
}
void SOPHUC::print(){
    if (a != 0){
        cout << a;
        if (b > 0) cout << " + ";
    }
    if (b < 0) cout << " - ";
    if (b != 0){
        if (b != 1) cout << b;
        cout << 'i';
    }
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
SOPHUC SOPHUC::add(SOPHUC x){
    SOPHUC n;
    n.a = a + x.a;
    n.b = b + x.b;

    return n;
}
SOPHUC SOPHUC::sub(SOPHUC x){
    SOPHUC n;
    n.a = a - x.a;
    n.b = b - x.b;

    return n;
}
SOPHUC SOPHUC::MULTI(SOPHUC x){
    SOPHUC n;
    n.a = a*x.a - b*x.b;
    n.b = a*x.b + b*x.a;

    return n;
}
SOPHUC SOPHUC::DIV(SOPHUC x){
    SOPHUC n;
    n.a = (a*x.a + b*x.b)/(a*a + b*b);
    n.b = (a*x.b + b*x.a)/(a*a + b*b);

    return n;
}
int SOPHUC::compare(SOPHUC x){
    int tmp = this->module() - x.module();
    if (tmp == 0) return 0;
    if (tmp < 0) return -1;
    if (tmp > 0) return 1;
}