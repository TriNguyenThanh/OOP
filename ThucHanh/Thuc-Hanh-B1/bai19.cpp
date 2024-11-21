#include <iostream>
#include <vector>
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
        simplify();
    }

    void simplify() {
        int gcdValue = gcd(tu, mau);
        tu /= gcdValue;
        mau /= gcdValue;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void display() const {
        cout << tu << "/" << mau;
    }

    bool operator>=(const PS &other) const {
        return tu * other.mau >= other.tu * mau;
    }
};

int main() {
    vector<PS> arr(5);
    for (int i = 0; i < 5; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        arr[i].input();
    }

    PS maxPS = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] >= maxPS) {
            maxPS = arr[i];
        }
    }

    cout << "Phan so co gia tri lon nhat:\n";
    maxPS.display();

    return 0;
}
