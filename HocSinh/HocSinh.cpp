#include <iostream>
#include <string>

using namespace std;

class SV{
public:
    SV();
    SV(string hoTen, float diemVan, float diemToan);
    SV(const SV& Sv);
    ~SV();
    friend istream& operator >>(istream& is, SV &Sv);
    friend istream& operator <<(ostream& os, SV &Sv);
    friend void inserction_sort(SV Sv[], int n);
    string getName();
    void setMa();
    bool operator >(SV Sv);
    bool operator >=(SV Sv);
    bool operator <(SV Sv);
    bool operator <=(SV Sv);
    bool operator ==(SV Sv);
    bool operator !=(SV Sv);
    void operator =(SV Sv);
    float getDTB();
private:
    int maSv;
    string hoTen;
    float diemVan;
    float diemToan;
};
SV::SV(){
    hoTen = "Nguyen Thanh Tri";
    diemToan = 10;
    diemVan = 6;
    setMa();
}
SV::SV(string hoTen, float diemVan, float diemToan){
    this->hoTen = hoTen;
    this->diemToan = diemToan;
    this->diemVan = diemVan;
    setMa();
}
SV::SV(const SV& Sv){
    hoTen = Sv.hoTen;
    diemToan = Sv.diemToan;
    diemVan = Sv.diemVan;
    setMa();
}
SV::~SV(){

}
string SV::getName(){
    return hoTen;
}
void SV::setMa(){
    static int id = 1;
    this->maSv = id++;
}
istream &operator >>(istream& is, SV &Sv){
    cout << "Nhap thong tin hoc sinh:\n";
    cout << "Nhap ten hoc sinh: ";
    cin.ignore();
    getline(is, Sv.hoTen);
    cout << "Nhap diem toan: "; is >> Sv.diemToan;
    cout << "Nhap diem van: "; is >> Sv.diemVan;
}
istream &operator <<(ostream& os, SV &Sv){
    os << "\n\nMa hoc sinh: " << Sv.maSv;
    os << "\nHo va ten: " << Sv.hoTen;
    os << "\nDiem toan: " << Sv.diemToan;
    os << "\nDiem van: " << Sv.diemVan;
    os << "\nDiem trung binh: " << (Sv.diemToan + Sv.diemVan)/2;
}
bool SV:: operator >(SV Sv){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (Sv.diemToan + Sv.diemVan)/2;
    return (dtb1 > dtb2);
}
bool SV:: operator >=(SV Sv){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (Sv.diemToan + Sv.diemVan)/2;
    return (dtb1 >= dtb2);
}
bool SV:: operator <(SV Sv){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (Sv.diemToan + Sv.diemVan)/2;
    return (dtb1 < dtb2);
}
bool SV:: operator <=(SV Sv){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (Sv.diemToan + Sv.diemVan)/2;
    return (dtb1 <= dtb2);
}
bool SV:: operator ==(SV Sv){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (Sv.diemToan + Sv.diemVan)/2;
    return (dtb1 == dtb2);
}
bool SV:: operator !=(SV Sv){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (Sv.diemToan + Sv.diemVan)/2;
    return (dtb1 != dtb2);
}
void SV::operator =(SV Sv){
    maSv = Sv.maSv;
    hoTen = Sv.hoTen;
    diemVan = Sv.diemVan;
    diemToan = Sv.diemToan;
}
float SV::getDTB(){
    return (diemToan + diemVan) /2;
}
void inputSv(SV Sv[], int n){
    for (int i = 0; i < n; ++i){
        cin >> Sv[i];
    }
}
void outputSv(SV Sv[], int n){
    for (int i = 0; i < n; ++i){
        cout << Sv[i];
    }
    cout << '\n';
}

void inserction_sort(SV Sv[], int n){
    for (int i = 1; i < n; ++i){
        SV key = Sv[i];
        int j = i - 1;
        
        while(j >= 0 && key < Sv[i]){
            Sv[j+1] = Sv[j];
            j--;
        }
        Sv[j+1] = key;
    }
}

int main(){
    SV Sv[100]; int n;
    cout << "So luong hoc sinh: "; cin >> n;
    inputSv(Sv, n);
    outputSv(Sv, n);
    inserction_sort(Sv, n);
    cout << "\n====Sau khi sort===\n";
    outputSv(Sv, n);
    return 0;
}