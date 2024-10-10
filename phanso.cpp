#include<iostream>
using namespace std;
class PhanSo{
	private:
		int tu, mau;
	public:
        PhanSo();
        PhanSo(int tu, int mau);
        PhanSo(const PhanSo &p);
		friend istream& operator >>(istream &is, PhanSo &p);
		friend ostream& operator <<(ostream &os, PhanSo p);
		friend PhanSo operator + (PhanSo a, PhanSo b);		
		PhanSo operator -(PhanSo a);
		bool operator ==(PhanSo a);
};
 istream& operator >>(istream &is, PhanSo &p){
 	cout <<"Nhap tu so: "; is >> p.tu;
 	cout <<"Nhap mau so: "; is >> p.mau;
 	return is;
 }
 ostream& operator <<(ostream &os, PhanSo p){
 	os << p.tu << "/" << p.mau;
 	return os; 	
 }
 PhanSo operator + (PhanSo a, PhanSo b){
 	PhanSo t;
 	t.tu=a.tu*b.mau+b.tu*a.mau;
 	t.mau=a.mau*b.mau;
 	return t;
 }
PhanSo PhanSo::operator -(PhanSo a){
	PhanSo t;
 	t.tu=tu*a.mau-a.tu*mau;
 	t.mau=mau*a.mau;
 	return t;
}
bool PhanSo::operator ==(PhanSo a){
	return tu*a.mau == mau*a.tu;
}
PhanSo::PhanSo(){
    tu = 1;
    mau = 1;
}
PhanSo::PhanSo(int tu, int mau){
    this->tu = tu;
    this->mau = mau;
}
PhanSo::PhanSo(const PhanSo &p){
    tu = p.tu;
    mau = p.mau;
}


int main(){
	PhanSo a,b;
	cout<<"Nhap a: ";
	cin>>a;
	cout<<"Nhap b: ";
	cin>>b;
	cout<<"Tong hai phan so: "<<a+b;
}
