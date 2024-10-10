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
    void input();
    void output();
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
    void input();
    void output();
};

class DateTime: public MyDate, public MyTime
{
public:
    DateTime(){}
    ~DateTime(){}
    void input();
    void output();
};

int main()
{
    DateTime dt[3];
    int t = 0;
    int n = 1;
    while (t++ != n)
    {
        cout << "Nhap thong tin date time thu " << t << ":\n";
        dt[t-1].input();
    }
    cout << "\n--------------------\n";
    t = 0;
    while (t++ != n)
    {
        cout << "\nThong tin date time thu " << t << ":\n";
        dt[t-1].output();
    }
    
    return 0;
}

void DateTime::input()
{
    MyTime::input();
    MyDate::input();
}
void DateTime::output()
{
    MyTime::output();
    MyDate::output();
}

void MyTime::input()
{
    do{
        cout << "\nNhap gio: ";
        cin >> hour;
        if (hour > 24 || hour < 0) cout << "\nNhap sai!";
    }while(hour > 24 || hour < 0);
    do{
        cout << "\nNhap phut: ";
        cin >> minute;
        if (minute > 59 || minute < 0) cout << "\nNhap sai!";
    }while(minute > 59 || minute < 0);
    do{
        cout << "\nNhap giay: ";
        cin >> second;
        if (second > 59 || second < 0) cout << "\nNhap sai!";
    }while(second > 59 || second < 0);
}
void MyTime::output()
{
    cout << setw(2) << setfill('0') << fixed << hour << " : " << minute << " : " << second << ' ';
}
void MyDate::output()
{
    cout << setw(2) << setfill('0') << day << '-' << month << '-' << year;
}
void MyDate::input()
{
    cout << "\nNhap nam: "; cin >> year;
    do
    {
        cout << "\nNhap thang: ";
        cin >> month;
        if (month < 0 || month > 12) cout << "\nNhap sai!";
    } while (month < 0 || month > 12);
    switch (month)
    {
        case 1:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 31) cout << "\nNhap sai!";
            } while (day < 0 || day > 31);
            break;
        }
        case 2:
        {
            int maxday = 28;
            if (year % 100 == 0)
                if (year % 400 == 0)
                    maxday = 29;
            else if (year % 4 == 0)
                maxday = 29;   
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > maxday) cout << "\nNhap sai!";
            } while (day < 0 || day > maxday);
            break;
        }
        case 3:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 31) cout << "\nNhap sai!";
            } while (day < 0 || day > 31);
            break;
        }
        case 4:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 30) cout << "\nNhap sai!";
            } while (day < 0 || day > 30);
            break;
        }
        case 5:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 31) cout << "\nNhap sai!";
            } while (day < 0 || day > 31);
            break;
        }
        case 6:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 30) cout << "\nNhap sai!";
            } while (day < 0 || day > 30);
            break;
        }
        case 7:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 31) cout << "\nNhap sai!";
            } while (day < 0 || day > 31);
            break;
        }
        case 8:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 31) cout << "\nNhap sai!";
            } while (day < 0 || day > 31);
            break;
        }
        case 9:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 30) cout << "\nNhap sai!";
            } while (day < 0 || day > 30);
            break;
        }
        case 10:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 31) cout << "\nNhap sai!";
            } while (day < 0 || day > 31);
            break;
        }
        case 11:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 30) cout << "\nNhap sai!";
            } while (day < 0 || day > 30);
            break;
        }
        case 12:
        {
            do
            {
                cout << "\nNhap ngay: "; cin >> day;
                if (day < 0 || day > 31) cout << "\nNhap sai!";
            } while (day < 0 || day > 31);
            break;
        }
    }
}