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
	Complex operator-(Complex x);
private:
	float a;
	float b;
};

int main()
{
    Complex x, y;
	x.input();
	y.input();
	Complex tong, hieu;
	tong = x + y;
	hieu = x - y;
	cout << "Tong hai so phuc: "; tong.print();
	cout << "\nHieu hai so phuc: "; hieu.print();
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
Complex Complex::operator-(Complex x)
{
	Complex tmp;
	tmp.a = a - x.a;
	tmp.b = b - x.b;

	return tmp;
}