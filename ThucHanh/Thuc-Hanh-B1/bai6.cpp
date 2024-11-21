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
        cout << "Nhap tu so: "; cin >> tu;
        cout << "Nhap mau so: "; cin >> mau;
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

    bool operator>(const PS &other) const {
        return tu * other.mau > other.tu * mau;
    }

    bool operator<(const PS &other) const {
        return tu * other.mau < other.tu * mau;
    }

    friend void swap(PS &ps1, PS &ps2);
};

void swap(PS &ps1, PS &ps2) {
    int tempTu = ps1.tu;
    int tempMau = ps1.mau;
    ps1.tu = ps2.tu;
    ps1.mau = ps2.mau;
    ps2.tu = tempTu;
    ps2.mau = tempMau;
}

void sortPS(vector<PS> &arr) { 
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[i]) { 
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PS> arr(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        arr[i].input();
        arr[i].simplify();
    }

    sortPS(arr);

    cout << "Mang phan so da sap xep: ";
    for (const auto &ps : arr) {
        ps.display();
    }
    cout << endl;

    return 0;
}
