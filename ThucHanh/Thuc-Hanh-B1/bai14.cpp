#include <iostream>
using namespace std;

class MyDate {
private:
    int day, month, year;

public:
    MyDate(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    void input() {
        cout << "Nhap ngay: "; cin >> day;
        cout << "Nhap thang: "; cin >> month;
        cout << "Nhap nam: "; cin >> year;
    }

    void display() const {
        cout << day << "-" << month << "-" << year << endl;
    }

    bool operator==(const MyDate &other) const {
        return (day == other.day && month == other.month && year == other.year);
    }
};

int main() {
    MyDate dates[5];

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap ngay thu " << i + 1 << ":\n";
        dates[i].input();
    }

    MyDate x;
    cout << "Nhap ngay can tim kiem:\n";
    x.input();

    bool found = false;
    for (int i = 0; i < 5; ++i) {
        if (dates[i] == x) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Ngay can tim co trong mang.\n";
    } else {
        cout << "Ngay can tim khong co trong mang.\n";
    }

    return 0;
}
