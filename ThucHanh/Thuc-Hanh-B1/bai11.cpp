#include <iostream>
#include <vector>
using namespace std;

class PS {
private:
    int tu, mau;

    friend int gcd(int a, int b) {
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
        if (mau < 0) { 
            tu = -tu;
            mau = -mau;
        }
    }

    void display() const {
        cout << tu << "/" << mau << " ";
    }
};

int main() {
    vector<PS> arr(5);
    for (int i = 0; i < 5; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        arr[i].input();
        arr[i].simplify();
    }

    cout << "Danh sach phan so da rut gon: ";
    for (const auto &ps : arr) {
        ps.display();
    }
    cout << endl;

    return 0;
}
