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

    PS operator+(const PS &other) const {
        PS result(tu * other.mau + other.tu * mau, mau * other.mau);
        result.simplify();
        return result;
    }

    PS operator-(const PS &other) const {
        PS result(tu * other.mau - other.tu * mau, mau * other.mau);
        result.simplify();
        return result;
    }

    PS operator*(const PS &other) const {
        PS result(tu * other.tu, mau * other.mau);
        result.simplify();
        return result;
    }

    PS operator/(const PS &other) const {
        PS result(tu * other.mau, mau * other.tu);
        result.simplify();
        return result;
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PS> arr(n);
    PS sum;

    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        arr[i].input();
        arr[i].simplify();
        sum = sum + arr[i];
    }

    cout << "Tong cac phan so: ";
    sum.display();
    cout << endl;

    return 0;
}
