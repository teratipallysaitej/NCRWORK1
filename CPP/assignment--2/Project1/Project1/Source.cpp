#include<iostream>
#include<math.h>
#define PI 3.14159265
using namespace std;
class polar {
public:
	//static int count = 0;
	double ang;
	double rad;
	double x, y;
	polar() {
		ang = 0;
		rad = 0;
		x = rad*cos(ang*PI);
		y = rad*sin(ang*PI);
		//count++;
	}
	polar(double f1, double f2) {
		ang = f1;
		ang = f2;
		x = rad*cos(ang*PI);
		y = rad*sin(ang*PI);
		//count++;
	}
	int display() {
		cout << "X:" << x << "Y:" << y;
		//cout << endl << count;
		return 0;
	}
};
int main() {
	polar c1(30, 5);
	c1.display();
	getchar();
	getchar();
}