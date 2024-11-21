#include <iostream>
using namespace std;

class MyTime {
private:
    int hours, minutes, seconds;

public:
    MyTime(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void input() {
        cout << "Nhap gio: "; cin >> hours;
        cout << "Nhap phut: "; cin >> minutes;
        cout << "Nhap giay: "; cin >> seconds;
    }

    void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    friend bool operator>=(const MyTime &t1, const MyTime &t2) {
        if (t1.hours != t2.hours) return t1.hours > t2.hours;
        if (t1.minutes != t2.minutes) return t1.minutes > t2.minutes;
        return t1.seconds >= t2.seconds;
    }
};

int main() {
    MyTime times[5];

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap thoi gian thu " << i + 1 << ":\n";
        times[i].input();
    }

    MyTime maxTime = times[0], minTime = times[0];
    for (int i = 1; i < 5; ++i) {
        if (times[i] >= maxTime) maxTime = times[i];
        if (!(times[i] >= minTime)) minTime = times[i];
    }

    cout << "Thoi gian lon nhat: ";
    maxTime.display();
    cout << "Thoi gian nho nhat: ";
    minTime.display();

    return 0;
}
