#include <iostream>
#include <string>

using namespace std;

class HocSinh{
public:
    HocSinh();
    HocSinh(string hoTen, float diemVan, float diemToan);
    HocSinh(const HocSinh& hs);
    ~HocSinh();
    friend istream& operator >>(istream& is, HocSinh &hs);
    friend istream& operator <<(ostream& os, HocSinh &hs);
    friend void inserction_sort(HocSinh hs[], int n);
    string getName();
    void setMa();
    bool operator >(HocSinh hs);
    bool operator >=(HocSinh hs);
    bool operator <(HocSinh hs);
    bool operator <=(HocSinh hs);
    bool operator ==(HocSinh hs);
    bool operator !=(HocSinh hs);
    void operator =(HocSinh hs);
    float getDTB();
private:
    int maHS;
    string hoTen;
    float diemVan;
    float diemToan;
};
HocSinh::HocSinh(){
    hoTen = "Nguyen Thanh Tri";
    diemToan = 10;
    diemVan = 6;
    setMa();
}
HocSinh::HocSinh(string hoTen, float diemVan, float diemToan){
    this->hoTen = hoTen;
    this->diemToan = diemToan;
    this->diemVan = diemVan;
    setMa();
}
HocSinh::HocSinh(const HocSinh& hs){
    hoTen = hs.hoTen;
    diemToan = hs.diemToan;
    diemVan = hs.diemVan;
    setMa();
}
HocSinh::~HocSinh(){

}
string HocSinh::getName(){
    return hoTen;
}
void HocSinh::setMa(){
    static int id = 1;
    this->maHS = id++;
}
istream &operator >>(istream& is, HocSinh &hs){
    cout << "Nhap thong tin hoc sinh:\n";
    cout << "Nhap ten hoc sinh: ";
    cin.ignore();
    getline(is, hs.hoTen);
    cout << "Nhap diem toan: "; is >> hs.diemToan;
    cout << "Nhap diem van: "; is >> hs.diemVan;
}
istream &operator <<(ostream& os, HocSinh &hs){
    os << "\n\nMa hoc sinh: " << hs.maHS;
    os << "\nHo va ten: " << hs.hoTen;
    os << "\nDiem toan: " << hs.diemToan;
    os << "\nDiem van: " << hs.diemVan;
    os << "\nDiem trung binh: " << (hs.diemToan + hs.diemVan)/2;
}
bool HocSinh:: operator >(HocSinh hs){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (hs.diemToan + hs.diemVan)/2;
    return (dtb1 > dtb2);
}
bool HocSinh:: operator >=(HocSinh hs){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (hs.diemToan + hs.diemVan)/2;
    return (dtb1 >= dtb2);
}
bool HocSinh:: operator <(HocSinh hs){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (hs.diemToan + hs.diemVan)/2;
    return (dtb1 < dtb2);
}
bool HocSinh:: operator <=(HocSinh hs){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (hs.diemToan + hs.diemVan)/2;
    return (dtb1 <= dtb2);
}
bool HocSinh:: operator ==(HocSinh hs){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (hs.diemToan + hs.diemVan)/2;
    return (dtb1 == dtb2);
}
bool HocSinh:: operator !=(HocSinh hs){
    float dtb1 = (diemToan + diemVan)/2;
    float dtb2 = (hs.diemToan + hs.diemVan)/2;
    return (dtb1 != dtb2);
}
void HocSinh::operator =(HocSinh hs){
    maHS = hs.maHS;
    hoTen = hs.hoTen;
    diemVan = hs.diemVan;
    diemToan = hs.diemToan;
}
float HocSinh::getDTB(){
    return (diemToan + diemVan) /2;
}
void inputHS(HocSinh hs[], int n){
    for (int i = 0; i < n; ++i){
        cin >> hs[i];
    }
}
void outputHS(HocSinh hs[], int n){
    for (int i = 0; i < n; ++i){
        cout << hs[i];
    }
    cout << '\n';
}

void inserction_sort(HocSinh hs[], int n){
    for (int i = 1; i < n; ++i){
        HocSinh key = hs[i];
        int j = i - 1;
        
        while(j >= 0 && key < hs[i]){
            hs[j+1] = hs[j];
            j--;
        }
        hs[j+1] = key;
    }
}

int main(){
    
    // HocSinh hs1;
    // cout << hs1; cout << '\n';
    // HocSinh hs2("Banh Thi Buoi", 7, 8);
    // cout << hs2; cout << "\n";
    // HocSinh hs3(hs2);
    // cout << hs3; cout << '\n';

    // cout << hs1.getName();
    // if (hs1 < hs2) cout << " < ";
    // else if (hs1 <= hs2) cout << " <= ";
    // else if (hs1 > hs2) cout << " > ";
    // else if (hs1 >= hs2) cout << " >= ";
    // else if (hs1 == hs2) cout << " == ";
    // else cout << " != ";
    // cout << hs2.getName();

    HocSinh hs[100]; int n;
    cout << "So luong hoc sinh: "; cin >> n;
    inputHS(hs, n);
    outputHS(hs, n);
    inserction_sort(hs, n);
    cout << "\n====Sau khi sort===\n";
    outputHS(hs, n);
    return 0;
}