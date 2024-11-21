#include <iostream>
#include <vector>
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

    friend bool operator>(const MyDate &d1, const MyDate &d2);
    friend void swap(MyDate &d1, MyDate &d2);
};

bool operator>(const MyDate &d1, const MyDate &d2) {
    if (d1.year != d2.year) return d1.year > d2.year;
    if (d1.month != d2.month) return d1.month > d2.month;
    return d1.day > d2.day;
}

void swap(MyDate &d1, MyDate &d2) {
    MyDate temp = d1;
    d1 = d2;
    d2 = temp;
}

void sortDate(vector<MyDate> &dates) {
    for (int i = 0; i < dates.size() - 1; ++i) {
        for (int j = i + 1; j < dates.size(); ++j) {
            if (dates[i] > dates[j]) {
                swap(dates[i], dates[j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong ngay: ";
    cin >> n;

    vector<MyDate> dates(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap ngay thu " << i + 1 << ":\n";
        dates[i].input();
    }

    // Sắp xếp mảng ngày tăng dần
    sortDate(dates);

    cout << "Mang ngay da sap xep: ";
    for (const auto &date : dates) {
        date.display();
    }

    return 0;
}
