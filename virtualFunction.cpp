#include <iostream>
#include <iomanip>
using namespace std;

class SV
{
private:
    string Lop;
    string Hoten;
public:
    SV();
    SV(string lop_, string hoten_);
    ~SV();
    virtual void show();
    virtual void input();
};

class SVTC: public SV
{
private:
    int Hocphi;
public:
    SVTC();
    SVTC(int hocphi_);
    void show();
    void input();
};

class SVCN: public SV
{
private:
    float Dtb;
    int Hocbong;
public:
    SVCN();
    SVCN(float dtb_, int hocbong_);
    void show();
    int operator > (SVCN x);
    void input();
};

int main()
{
    SV* sinhVienTaiChuc = new SVTC;
    SV* sinhVienCuNhan = new SVCN;

    cout << "Nhap sinh vien tai chuc:\n";
    sinhVienTaiChuc->input();
    cout << "\nNhap sinh vien cu nhan:\n";
    sinhVienCuNhan->input();

    cout << "\nThong tin sinh vien:";
    cout << "\nSinh vien tai chuc:\n";
    sinhVienTaiChuc->show();
    cout << "\nSinh vien cu nhan:\n";
    sinhVienCuNhan->show();

    return 0;
}

//Sinh vien
SV::SV()
{
    Lop = "None";
    Hoten = "None";
}
SV::SV(string lop_, string hoten_)
{
    Lop = lop_;
    Hoten = hoten_;
}
SV::~SV()
{

}
void SV::show()
{
    cout << "Ho va ten: " << Hoten << '\n';
    cout << "Lop: " << Lop;
}
void SV::input()
{
    cout << "\nNhap ten: ";
    getline(cin, Hoten);

    cout << "Nhap lop: ";
    getline(cin, Lop);
}

//Sinh vien tai chuc
SVTC::SVTC()
{
    Hocphi = 0;
}
SVTC::SVTC(int hocphi_)
{
    Hocphi = hocphi_;
}
void SVTC::show()
{
    SV::show();
    cout << '\n' << "Hoc phi: " << Hocphi;
    while (Hocphi < 0)
    {
        cout << "Nhap sai hoc phi!!. Nhap lai hoc phi: ";
        cin >> Hocphi;
    }
}
void SVTC::input()
{
    SV::input();
    cout << "Nhap hoc phi: ";
    cin >> Hocphi;
}

//Sinh vien cu nhan
SVCN::SVCN()
{
    Dtb = 0;
    Hocbong = 0;
}
SVCN::SVCN(float dtb_, int hocbong_)
{
    Dtb = dtb_;
    Hocbong = hocbong_;
}
void SVCN::show()
{
    SV::show();
    cout << '\n' << "Dien trung binh: " << fixed << setprecision(2) << Dtb;
    cout << '\n' << "Hoc bong: ";
    if (Hocbong) cout << "Co";
    else cout << "Khong";
}
int SVCN::operator > (SVCN x)
{
    if (this->Dtb > x.Dtb) return 1;
    if (this->Dtb == x.Dtb) return 0;
    if (this->Dtb < x.Dtb) return -1;
}
void SVCN::input()
{
    SV::input();
    cout << "Nhap diem trung binh: ";
    cin >> Dtb;
    while (Dtb < 0 || Dtb > 4)
    {
        cout << "Nhap sai diem trung binh!!. Nhap lai: ";
        cin >> Dtb;
    }
    if (Dtb >= 3.5) Hocbong = 1;
}