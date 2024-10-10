#include <iostream>
#include <string>

using namespace std;

int n = 0;

class CanBo{
protected:
    string name;
    int age;
    string sex;
    string address;
public:
    CanBo();
    ~CanBo();

    void setName();
    string getName();
    void setAge();
    int getAge();
    void setSex();
    string getSex();
    void setAddress();
    string getAddress();
};

class CongNhan : public CanBo{
private:
    int level;
public:
    void setLevel();
    int getLevel();
};

class KySu : public CanBo{
private:
    string nganh;
public:
    void setNganh();
    string getNganh();
};

class NhanVien : public CanBo{
private:
    string job;
public:
    void nhapJob();
    string getJob();
};

class QLCB{
private:
    CanBo *listCanBo;
public:
    QLCB();
    ~QLCB();
    void themCB();
    CanBo *timKiemCB(string CBname);
    void xuatCB();
    void xoaCB(string CBname);
};


void run();


int main(){
    run();
    return 0;
}

void run(){
    QLCB s;
    bool quit = false;
    int choose;
    while(!quit){
        system("cls");
        cout << "1. Them can bo.\n";
        cout << "2. Tim can bo.\n";
        cout << "3. Danh sach can bo\n";
        cout << "4. Xoa can bo\n";
        cout << "5. Thoat.\n";
        cout << " ==> Nhap lua chon: "; cin >> choose;
        system("cls");
        switch (choose)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            quit = true;
            break;
        }
    }
}

QLCB::QLCB(){
    listCanBo = nullptr;
}
QLCB::~QLCB(){

}
void CanBo::setName(){
    getline(cin, name);
}
string CanBo::getName(){
    return name;
}
void CanBo::setAge(){
    cin >> age;
    while (age < 15)
    {
        cout << "\nPhai tren 15 tuoi!. Tuoi: ";

        cin >> age;
    }
    
}
int CanBo::getAge(){
    return age;
}
void CanBo::setSex(){
    getline(cin, sex);
    while (true)
    {
        if (sex != "Nam" && sex != "Nu" && sex != "Khac"){
            cout << "\nNhap 1 trong 3: [Nam, Nu, Khac] !!!";
            cin.ignore();
            cout << "\nGioi tinh:";
            getline(cin, sex);
        }else{
            break;
        }
    }
    
}
string CanBo::getSex(){
    return sex;
}
void CanBo::setAddress(){
    getline(cin, address);
}
string CanBo::getAddress(){
    return address;
}
void QLCB::themCB(){
    cout << "THEM CAN BO:\n";
    cout << "Ten: ";
    listCanBo[n].setName();
    cout << "Tuoi: ";
    listCanBo[n].setAge();
    cout << "Gioi tinh: ";
    listCanBo[n].setSex();
    cout << "Dia chi: ";
    listCanBo[n].setAddress();
}