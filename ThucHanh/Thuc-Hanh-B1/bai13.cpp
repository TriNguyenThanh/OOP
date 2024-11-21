#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double grade1, grade2, avg;

public:
    Student() : grade1(0), grade2(0), avg(0) {}

    void input() {
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap diem ky 1: ";
        cin >> grade1;
        cout << "Nhap diem ky 2: ";
        cin >> grade2;
        avg = (grade1 + 2 * grade2) / 3;
    }

    void display() const {
        cout << "Ten: " << name << ", Diem TB: " << avg << endl;
    }

    bool operator>(const Student &other) const {
        return avg > other.avg;
    }

    friend void swap(Student &a, Student &b);
};

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

void sortStudent(vector<Student> &arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    vector<Student> students(5);

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        students[i].input();
    }

    sortStudent(students);

    cout << "Danh sach sinh vien sau khi sap xep:\n";
    for (const auto &student : students) {
        student.display();
    }

    return 0;
}
