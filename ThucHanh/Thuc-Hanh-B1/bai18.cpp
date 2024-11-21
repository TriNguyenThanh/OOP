#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double grade1, grade2;

public:
    Student() : grade1(0), grade2(0) {}

    void input() {
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap diem ky 1: ";
        cin >> grade1;
        cout << "Nhap diem ky 2: ";
        cin >> grade2;
    }

    double getAverage() const {
        return (grade1 + 2 * grade2) / 3;
    }

    bool isPassed() const {
        return getAverage() >= 5;
    }

    void display() const {
        cout << "Ten: " << name << ", Diem TB: " << getAverage() << endl;
    }
};

int main() {
    vector<Student> students(5);

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        students[i].input();
    }

    cout << "Danh sach sinh vien co diem trung binh >= 5:\n";
    for (const auto &student : students) {
        if (student.isPassed()) {
            student.display();
        }
    }

    return 0;
}
