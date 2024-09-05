#include <iostream>
using namespace std;
class PhanSo{
    private:
        int tuSo, mauSo;
    public:
        void nhap();
        void xuat();
        int getTuSo();
        void setTuSo(int x);
        int getMauSo();
        void setMauSo(int x);
};
void PhanSo::nhap(){
    cout << "\nNhap tu so va mau so: ";
    cin >> tuSo >> mauSo;
    while(mauSo == 0){
        cout << "\nMau so phai khac 0\n";
        cin >> mauSo;
    }
}
void PhanSo::xuat(){
    cout << "Phan so la: ";
    cout << tuSo << '/' << mauSo;
}
int PhanSo::getTuSo(){
    return tuSo;
}
void PhanSo::setTuSo(int x){
    tuSo = x;
}
int PhanSo::getMauSo(){
    return mauSo;
}
void PhanSo::setMauSo(int x){
    mauSo = x;
}
int main(){
    PhanSo p1;
    p1.nhap();
    p1.xuat();
    cout << "\nTu so la: " << p1.getTuSo();
    cout << "\nMau so la: " << p1.getMauSo();

    int x;
    cout << "Nhap tu so: "; cin >> x;
    p1.setTuSo(x);
    cout << "Nhap mau so: "; cin >> x;
    p1.setMauSo(x);

    p1.xuat();
    return 0;
}