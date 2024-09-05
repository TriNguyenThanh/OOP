#include <iostream>
using namespace std;
class PhanSo{
    private:
        int tuSo, mauSo;
        int ucln(int a, int b);
    public:
        void nhap();
        void xuat();
        int getTuSo();
        void setTuSo(int x);
        int getMauSo();
        void setMauSo(int x);
        void nghichDao();
        void rutGon();
        PhanSo cong(PhanSo x);
        PhanSo tru(PhanSo x);
        PhanSo nhan(PhanSo x);
        PhanSo chia(PhanSo x);
        void sosanh(PhanSo x);
        
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
    if (tuSo == 0) cout << '0';
    else if(mauSo == 1) cout << tuSo;

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
void PhanSo::nghichDao(){
    int tmp = tuSo;
    tuSo = mauSo;
    mauSo = tmp;
}
int PhanSo::ucln(int a, int b){
    if (a < 0) a = 0 - a;
    if (b < 0) b = 0 - b;
    if (a == 0) return b;
    while(a !=  b){
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}
void PhanSo::rutGon(){
    int u = ucln(tuSo, mauSo);
    tuSo = tuSo / u;
    mauSo = mauSo / u;
}
PhanSo PhanSo::cong(PhanSo x){
    PhanSo kq;
    kq.tuSo = tuSo * x.mauSo + x.tuSo * mauSo;
    kq.mauSo = mauSo * x.mauSo;

    kq.rutGon();
    return kq;
}
PhanSo PhanSo::tru(PhanSo x){
    PhanSo kq;
    kq.tuSo = tuSo * x.mauSo - x.tuSo * mauSo;
    kq.mauSo = mauSo * x.mauSo;

    kq.rutGon();
    return kq;
}
PhanSo PhanSo::nhan(PhanSo x){
    PhanSo kq;
    kq.tuSo = tuSo * x.tuSo;
    kq.mauSo = mauSo * x.mauSo;

    kq.rutGon();
    return kq;
}
PhanSo PhanSo::chia(PhanSo x){
    PhanSo kq;
    kq.tuSo = tuSo * x.mauSo;
    kq.mauSo = mauSo * x.tuSo;

    kq.rutGon();
    return kq;
}
void PhanSo::sosanh(PhanSo x){
    int tu1 = tuSo, tu2 = x.tuSo;
    if (mauSo != x.mauSo){
        tu1 = tuSo * x.mauSo;
        tu2 = x.tuSo * mauSo;
    }
    if (tu1 == tu2) cout << tuSo << '/' << mauSo << " = " << x.tuSo << "/" << x.mauSo;
    else if (tu1 < tu2) cout << tuSo << '/' << mauSo << " < " << x.tuSo << "/" << x.mauSo;
    else cout << tuSo << '/' << mauSo << " > " << x.tuSo << "/" << x.mauSo;
}
int main(){
    PhanSo p1, p2, p;
    p1.nhap();
    cout << "\nPhan so: ";p1.xuat();
    cout << "\nTu so la: " << p1.getTuSo();
    cout << "\nMau so la: " << p1.getMauSo();

    int x;
    cout << "\nNhap tu so: "; cin >> x;
    p1.setTuSo(x);
    cout << "Nhap mau so: "; cin >> x;
    p1.setMauSo(x);
    cout << "\nPhan so: ";p1.xuat();

    p2.nhap();
    p = p1.cong(p2);
    cout << p1.getTuSo() << '/' << p1.getMauSo() << " + " << p2.getTuSo() << "/" << p2.getMauSo() << " = " << p.getTuSo() << '/' << p.getMauSo() << '\n';
    p = p1.tru(p2);
    cout << p1.getTuSo() << '/' << p1.getMauSo() << " - " << p2.getTuSo() << "/" << p2.getMauSo() << " = " << p.getTuSo() << '/' << p.getMauSo() << '\n';
    p = p1.nhan(p2);
    cout << p1.getTuSo() << '/' << p1.getMauSo() << " * " << p2.getTuSo() << "/" << p2.getMauSo() << " = " << p.getTuSo() << '/' << p.getMauSo() << '\n';
    p = p1.chia(p2);
    cout << p1.getTuSo() << '/' << p1.getMauSo() << " / " << p2.getTuSo() << "/" << p2.getMauSo() << " = " << p.getTuSo() << '/' << p.getMauSo() << '\n';
    
    p1.sosanh(p2);
    
    return 0;
}