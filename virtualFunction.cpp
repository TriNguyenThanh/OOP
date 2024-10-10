#include <iostream>
#include <iomanip>
#include <string>
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
    SV* sv[10];
    int i = 0;
    int x;
    while (true)
    {
        system("cls");
        cout << "Menu:";
        cout << "\n1. Nhap thong tin sinh vien tai chuc.";
        cout << "\n2. Nhap thong tin sinh vien cu nhan.";
        cout << "\n3. Xuat thong tin tat ca sinh vien.";
        cout << "\n4. Xuat thong tin sinh vien tai chuc.";
        cout << "\n5. Xuat thong tin sinh vien cu nhan.";
        cout << "\n6. Thoat.";
        cout << "\nNhap lua chon: ";
        cin >> x;
        switch (x)
        {
            case 1:
            {
                SV* svtc_ = new SVTC;
                svtc_->input();
                sv[i++] = svtc_;
                cout << '\n';system("pause");
                break;
            }
            case 2:
            {
                SV* svcn_ = new SVCN;
                svcn_->input();
                sv[i++] = svcn_;
                cout << '\n';system("pause");
                break;
            }
            case 3:
            {
                for (int j = 0; j < i; ++j)
                {
                    sv[j]->show();
                    cout << '\n';
                }
                cout << '\n';system("pause");
                break;
            }
            case 4:
            {
                cout << "\nThong tin sinh vien tai chuc:";
                for (int j = 0; j < i; ++j)
                {
                    SVTC* svtc_ = dynamic_cast<SVTC*>(sv[j]);
                    if (svtc_ != nullptr) svtc_->show();
                }
                cout << '\n';system("pause");
                break;
            }
            case 5:
            {
                cout << "\nThong tin sinh vien cu nhan:";
                for (int j = 0; j < i; ++j)
                {
                    cout << '\n';
                    SVCN* svcn_ = dynamic_cast<SVCN*>(sv[j]);
                    if (svcn_ != nullptr) svcn_->show();
                }
                cout << '\n';system("pause");
                break;
            }
            case 6:
            {
                return 0;
                break;
            }
            default:
            {
                cout << "Lua chon khong hop le!. Nhap lai lua chon: ";
                cin >> x;
                break;
            }
        }
    }
    
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
    cin.ignore();
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
}
void SVTC::input()
{
    SV::input();
    cout << "Nhap hoc phi: ";
    cin >> Hocphi;
    while (Hocphi < 0)
    {
        cout << "Hoc phi khong hop le!. Nhap lai hoc phi: ";
        cin >> Hocphi;
    }
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