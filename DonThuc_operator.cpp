#include <iostream>
using namespace std;

class DonThuc {
private:
    float heSo;
    int soMu;
public:
    DonThuc();
    DonThuc(float heSo, int soMu);
    DonThuc(const DonThuc& dt);
    friend istream& operator>>(istream& is, DonThuc &x);
    friend ostream& operator<<(ostream& os, DonThuc &x);
    float getHeSo() { return heSo; }
    int getSoMu() { return soMu; }
    void setHeSo(float x);
    void setSoMu(int x);
    DonThuc operator+(DonThuc x);
    DonThuc operator-(DonThuc x);
    DonThuc operator*(DonThuc x);
    DonThuc operator/(DonThuc x);
    int DonThuc::operator==(DonThuc x);
    float value(float x);
};
DonThuc::DonThuc(){
    heSo = 2;
    soMu = 1;
}
DonThuc::DonThuc(float heSo, int soMu){
    this->heSo = heSo;
    this->soMu = soMu;
}
DonThuc::DonThuc(const DonThuc& dt){
    heSo = dt.heSo;
    soMu = dt.soMu;
}
istream& operator>>(istream& is, DonThuc &x){
    cout << "\nNhap he so va so mu: ";
    is >> x.heSo >> x.soMu;
    return is;
}
ostream& operator<<(ostream& os, DonThuc &x){
    if (x.heSo != 1) os << x.heSo;
    if (x.heSo != 0) {
        if (x.soMu == 1) os << "x";
        else if (x.soMu > 1) os << "x^" << x.soMu;
    }

    return os;
}
void DonThuc::setHeSo(float x) {
    heSo = x;
}
void DonThuc::setSoMu(int x) {
    soMu = x;
}

float DonThuc::value(float x) {
    if (soMu == 0) return heSo;
    for (int i = 1; i < soMu; ++i)
        x *= x;
    return heSo * x;
}
DonThuc DonThuc:: operator+(DonThuc x){
    DonThuc tmp;
    tmp.heSo = tmp.soMu = 0;
    if (soMu != x.soMu){
        cout << "\nPhai cung so mu";
        return tmp;
    }else{
        tmp.heSo = heSo + x.heSo;
        return tmp;
    }
    
}
DonThuc DonThuc:: operator-(DonThuc x){
    DonThuc tmp;
    tmp.heSo = tmp.soMu = 0;
    if (soMu != x.soMu){
        cout << "\nPhai cung so mu";
        return tmp;
    }else{
        tmp.heSo = heSo - x.heSo;
        return tmp;
    }
}
DonThuc DonThuc:: operator*(DonThuc x){
        DonThuc tmp;
        tmp.heSo = heSo * x.heSo;
        tmp.soMu = soMu + x.soMu;

        return tmp;
}
DonThuc DonThuc:: operator/(DonThuc x){
    DonThuc tmp;
    tmp.heSo = heSo/x.heSo;
    tmp.soMu = soMu - x.soMu;

    return tmp;
}
int DonThuc::operator==(DonThuc x) {
    if (heSo > x.heSo) return 1;
    if (heSo == x.heSo) return 0;
    return -1;
}

int main(){
    DonThuc n1, n2;
    cout << "Nhap don thuc thu 1:\n"; cin >> n1;
    float x;
    int y;
    cout << "\nNhap lai he so va so mu: "; cin >> x >> y;
    n1.setHeSo(x);
    n1.setSoMu(y);
    cout << "Nhap don thuc thu 2:\n"; cin >> n2;

    cout << "Tong: " << n1 + n2;
    cout << "Hieu: " << n1 - n2;
    cout << "Tich: " << n1 * n2;
    cout << "Thuong: " << n1 / n2;
    
    return 0;
}