#include<iostream>
#include<string>
using namespace std;
class employee {
public:
	int empno;
	double salary;
	string name;
	employee() {
		empno = 0;
		salary = 0.0;
		name = " ";
	}
	employee(int n, double m, string o) {
		empno = n;
		salary = m;
		name = o;
	}
	void setdata(int n, double m, string o) {
		empno = n;
		salary = m;
		name = o;
}
	void getdata() {
		cout << "empno:" << empno << endl;
		cout << "salary" << salary << endl;
		cout << "name:" << name;

	}
	friend istream & operator >> (istream &in, employee &c);
	~employee() {
		
	}
	

};
istream & operator >> (istream &in, employee &c) {
	cout << "empno:";
		in >> c.empno;
		cout << "salary:";
		in >> c.salary;
		cout << "name";
		in >> c.name;
		return in;

}

int main() {
	employee st[2];
	for (int i = 0;i < 2;i++) {
		cin >> st[i];
		cout << endl;
	}
	for (int i = 0;i < 2;i++) {
		st[i].getdata();
	}
	getchar();
	getchar();
	return 0;
}
