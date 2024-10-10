#include <iostream>

class TaiKhoan{
private:
    float m_fSoDu = 0;
public:
    float baoSoDu() {return m_fSoDu;};
    void napTien(float fSoTien) {m_fSoDu += fSoTien;};
    void rutTien(float fSoTien) {
        if (fSoTien <= m_fSoDu) m_fSoDu -= fSoTien;
    }
};

class TaiKhoanTietKiem: public TaiKhoan
{
private:
    int kyHanGui;
    float laiSuat;
    int soThangDaGui;
public:
    void napTien(float fSoTien);
    void rutTien(float fSoTien);
    void tangSoThangDaGui();
    float baoSoDu();
};

void TaiKhoanTietKiem::napTien(float fSoTien){
    TaiKhoan::napTien(fSoTien);
    soThangDaGui = 0;
}

void TaiKhoanTietKiem::rutTien(float fSoTien){
    if (soThangDaGui >= kyHanGui){
        TaiKhoan::rutTien(fSoTien);
    }
}

void TaiKhoanTietKiem::tangSoThangDaGui(){
    soThangDaGui++;
}

float TaiKhoanTietKiem::baoSoDu(){
    return TaiKhoan::baoSoDu() * (1 + laiSuat);
}

int main(){
    return 0;
}