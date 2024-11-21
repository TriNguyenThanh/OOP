#include <iostream>
using namespace std;

class PS {
private:
    int tu, mau;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    PS(int t = 0, int m = 1) : tu(t), mau(m) {
        if (mau == 0) mau = 1;
    }

    void input() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0) mau = 1;
    }

    void simplify() {
        int gcdValue = gcd(tu, mau);
        tu /= gcdValue;
        mau /= gcdValue;
    }

    void display() const {
        cout << tu << "/" << mau << " ";
    }

    friend bool operator>=(const PS &p1, const PS &p2);
};

bool operator>=(const PS &p1, const PS &p2) {
    return p1.tu * p2.mau >= p2.tu * p1.mau;
}

int main() {
    PS arr[5];

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        arr[i].input();
        arr[i].simplify();
    }

    PS max = arr[0], min = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] >= max) max = arr[i];
        if (!(arr[i] >= min)) min = arr[i];
    }

    cout << "Phan so lon nhat: ";
    max.display();
    cout << "\nPhan so nho nhat: ";
    min.display();

    return 0;
}
