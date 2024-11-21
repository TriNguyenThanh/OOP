#include <iostream>
using namespace std;

class MyDate
{
private:
    int day;
    int month;
    int year;
public:
    MyDate() {day = 1; month = 1; year = 1;}
    ~MyDate() {}
    void input();
    void print();
    friend int operator>=(MyDate md1, MyDate md2);
};
int operator>=(MyDate md1, MyDate md2)
{
    //  0 is md1 < md2
    //  1 is md1 >= md2
    if (md1.year > md2.year) return 1;
    if (md1.year < md2.year) return 0;
    else 
    {
        if (md1.month > md2.month) return 1;
        if (md1.month < md2.month) return 0;
        else
        {
            if (md1.day >= md2.day) return 1;
            if (md1.day < md2.day) return 0;
        }
    }
}
int main()
{
    MyDate md[5];
    int max_i = 0;
    for (int i = 0; i < 5; ++i)
    {
        cout << "\nNhap ngay thu " << i +1 << ":\n";
        md[i].input();
        if (md[i] >= md[max_i]) max_i = i;
    }
    cout << "\nThoi gian lon nhat: "; md[max_i].print();
    return 0;
}
void MyDate::input()
{
    cout << "Nhap ngay, thang, nam: ";
    cin >> day >> month >> year;
}
void MyDate::print()
{
    cout << day << "-" << month << "-" << year;
}