#include<iostream> 
using namespace std;

class Complex {
public:
	int real, imag;
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(int r, int i) { real = r; imag = i; }

	Complex operator + (Complex const &obj) {
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	Complex operator -(Complex const &obj) {
		Complex res;
		res.real = real - obj.real;
		res.imag = imag - obj.imag;
		return res;
	}
	Complex operator-() {
		Complex c;
		c.real = -real;
		c.imag = -imag;
		return c;
	}
	Complex operator++() {
		Complex temp;
		temp.real = real + 1;
		temp.imag = imag + 1;
		return temp;
	}
	Complex operator++(int i) {
		Complex temp;
		temp.real = real++;
		temp.imag = imag++;
		return temp;
	}
	Complex operator--() {
		Complex temp;
		temp.real = real - 1;
		temp.imag = imag - 1;
		return temp;
	}
	Complex operator--(int i) {
		Complex temp;
		temp.real = real--;
		temp.imag = imag--;
		return temp;
	}



	friend ostream & operator << (ostream &out, const Complex &c);
	friend istream & operator >> (istream &in, Complex &c);
};
ostream & operator << (ostream &out, const Complex &c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream & operator >> (istream &in, Complex &c)
{
	cout << "Enter Real Part ";
	in >> c.real;
	cout << "Enter Imagenory Part ";
	in >> c.imag;
	return in;
}
int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; 
}
