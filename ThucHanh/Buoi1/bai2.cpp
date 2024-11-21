#include <iostream>
using namespace std;

class Complex 
{
public:
	Complex() {a = 0; b = 0;}
    ~Complex() {}
	void input();
	void print();
	Complex operator+(Complex x);
	void operator=(Complex x);
private:
	float a;
	float b;
};

int main()
{
    // phap so phuc
    int n;
    cout << "Nhap so luong so phuc: "; cin >> n;
    Complex s[100];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap so phuc thu "<< i + 1<< ":\n";
        s[i].input();
    }
    //tinh tong
    Complex sum;
    for (int i = 0; i < n; i++)
    {
        sum = sum + s[i];
    }

    //in tong
    cout << "\nTong cua " << n <<" so phuc vua nhap la: "; sum.print();
    return 0;
}

void Complex::input()
{
	cout << "Nhap phan thuc: "; cin >> a;
	cout << "Nhap phan ao: "; cin >> b;
}
void Complex::print()
{
	cout << a;
	if (b > 0) cout << " + ";
	if (b < 0)
	{
		cout << " - ";
		b *= -1;
	}
	cout << b << "i";
}
Complex Complex::operator+(Complex x)
{
	Complex tmp;
	tmp.a = a + x.a;
	tmp.b = b + x.b;

	return tmp;
}
void Complex::operator=(Complex x)
{
	a = x.a;
    b = x.b;
}