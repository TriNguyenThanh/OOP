#include <iostream>
#include <iomanip>
using namespace std;

class MyTime
{
private:
    int hour;
    int minute;
    int second;
public:
    MyTime(){}
    ~MyTime(){}
    friend istream& operator >>(istream& is, MyTime& mt);
    friend ostream& operator <<(ostream& os, MyTime& mt);
    MyTime operator + (int n);
    MyTime& operator = (MyTime md);
};

class MyDate
{
private:
    int day;
    int month;
    int year;
public:
    MyDate(){}
    ~MyDate(){}
    friend istream& operator >>(istream& is, MyDate& md);
    friend ostream& operator <<(ostream& os, MyDate& md);
    MyDate operator + (int n);
    MyDate& operator = (MyDate md);
};

class DateTime: public MyDate, public MyTime
{
public:
    DateTime(){}
    ~DateTime(){}
    friend istream& operator >>(istream& is, DateTime& dt);
    friend ostream& operator <<(ostream& os, DateTime& dt);
};

int main()
{
    DateTime dt[3];
    int t = 0;
    int n = 1;
    while (t++ != n)
    {
        cout << "Nhap thong tin date time thu " << t << ":\n";
        cin >> dt[t-1];
    }
    cout << "\n--------------------\n";
    t = 0;
    while (t++ != n)
    {
        cout << "\nThong tin date time thu " << t << ":\n";
        cout << dt[t-1];
    }
    
    return 0;
}

istream& operator >> (istream& is, DateTime& dt)
{
    is >> static_cast<MyDate&>(dt);
    is >> static_cast<MyTime&>(dt);

    return is;
}
ostream& operator << (ostream& os, DateTime& dt)
{
    os << static_cast<MyDate&>(dt);
    os << " ";
    os << static_cast<MyTime&>(dt);

    return os;
}

istream& operator >> (istream& is, MyTime& mt)
{
    do{
        cout << "\nNhap gio: ";
        is >> mt.hour;
        if (mt.hour > 24 || mt.hour < 0) cout << "\nNhap sai!";
    }while(mt.hour > 24 || mt.hour < 0);
    do{
        cout << "\nNhap phut: ";
        is >> mt.minute;
        if (mt.minute > 59 || mt.minute < 0) cout << "\nNhap sai!";
    }while(mt.minute > 59 || mt.minute < 0);
    do{
        cout << "\nNhap giay: ";
        is >> mt.second;
        if (mt.second > 59 || mt.second < 0) cout << "\nNhap sai!";
    }while(mt.second > 59 || mt.second < 0);

    return is;
}
ostream& operator<<(ostream& os, MyTime& mt)
{
    os << setw(2) << setfill('0') << mt.hour << " : " << mt.minute << " : " << mt.second;

    return os;
}
ostream& operator<<(ostream& os, MyDate& md)
{
    os << setw(2) << setfill('0') << md.day << '-' << md.month << '-' << md.year;

    return os;
}
istream& operator >> (istream& is, MyDate& md)
{
    cout << "\nNhap nam: "; is >> md.year;
    do
    {
        cout << "\nNhap thang: ";
        is >> md.month;
        if (md.month < 0 || md.month > 12) cout << "\nNhap sai!";
    } while (md.month < 0 || md.month > 12);
    switch (md.month)
    {
        case 1:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 31) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 31);
            break;
        }
        case 2:
        {
            int maxDay = 28;
            if (md.year % 100 == 0)
                if (md.year % 400 == 0)
                    maxDay = 29;
            else if (md.year % 4 == 0)
                maxDay = 29;   
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > maxDay) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > maxDay);
            break;
        }
        case 3:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 31) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 31);
            break;
        }
        case 4:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 30) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 30);
            break;
        }
        case 5:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 31) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 31);
            break;
        }
        case 6:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 30) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 30);
            break;
        }
        case 7:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 31) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 31);
            break;
        }
        case 8:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 31) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 31);
            break;
        }
        case 9:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 30) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 30);
            break;
        }
        case 10:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 31) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 31);
            break;
        }
        case 11:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 30) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 30);
            break;
        }
        case 12:
        {
            do
            {
                cout << "\nNhap ngay: "; is >> md.day;
                if (md.day < 0 || md.day > 31) cout << "\nNhap sai!";
            } while (md.day < 0 || md.day > 31);
            break;
        }
    }
    return is;
}
MyDate MyDate::operator + (int n)
{
    MyDate tmp;
    tmp.day = this->day + n;
    tmp.month = this->month;
    tmp.year = this->year;
    int maxday = 28;

    while (tmp.day > maxday || tmp.month > 12)
    {
        if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
        {
            maxday = 31;
        }
        else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
        {
            maxday = 30;
        }
        else
        {
            if (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0)
                maxday = 29;
            else
                maxday = 28; 
        }
        if (tmp.day > maxday)
        {
            tmp.day -= maxday;
            tmp.month++;
        }
        if (tmp.month > 12)
        {
            tmp.month -= 12;
            tmp.year++;
        }
    }
    return tmp;
}
MyDate& MyDate::operator = (MyDate md)
{
    this->day = md.day;
    this->month = md.month;
    this->year = md.year;

    return *this;
}
MyTime MyTime::operator + (int n)
{
    MyTime tmp;
    tmp.second = this->second + n;
    tmp.minute = this->minute;
    tmp.hour = this->hour;

    while (tmp.second > 59 || tmp.minute > 59 || tmp.hour > 23)
    {
        if (tmp.second > 59)
        {
            tmp.second -= 60;
            tmp.minute++;
        }
        if (tmp.minute > 59)
        {
            tmp.minute -= 60;
            tmp.hour++;
        }
        if (tmp.hour > 23)
        {
            tmp.hour -= 24;
        }
    }
    return tmp;
    
}
MyTime& MyTime::operator = (MyTime md)
{
    this->second = md.second;
    this->minute = md.minute;
    this->hour = md.hour;

    return *this;
}