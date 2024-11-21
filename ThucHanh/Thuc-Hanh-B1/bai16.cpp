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

    bool operator==(const PS &other) const {
        return tu * other.mau == other.tu * mau;
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PS> arr(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        arr[i].input();
    }

    PS x;
    cout << "Nhap phan so can tim:\n";
    x.input();

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Phan so can tim co trong mang.\n";
    } else {
        cout << "Phan so can tim khong co trong mang.\n";
    }

    return 0;
}
