#include <iostream>
using namespace std;

class MyDate {
private:
    int day, month, year;

public:
    MyDate(int d = 1, int m = 1, int y = 2000){day = d; month = m; year = y;}

    void input() {
        cout << "Nhap ngay: "; cin >> day;
        cout << "Nhap thang: "; cin >> month;
        cout << "Nhap nam: "; cin >> year;
    }

    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }

    friend bool operator>=(const MyDate &d1, const MyDate &d2);
};

bool operator>=(const MyDate &d1, const MyDate &d2) {
    if (d1.year > d2.year) return true;
    if (d1.year == d2.year && d1.month > d2.month) return true;
    if (d1.year == d2.year && d1.month == d2.month && d1.day >= d2.day) return true;
    return false;
}

int main() {
    MyDate dates[5];

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap ngay thu " << i + 1 << ":\n";
        dates[i].input();
    }

    MyDate maxDate = dates[0];
    for (int i = 1; i < 5; ++i) {
        if (dates[i] >= maxDate) {
            maxDate = dates[i];
        }
    }

    cout << "Ngay lon nhat la: "; maxDate.display();

    return 0;
}
