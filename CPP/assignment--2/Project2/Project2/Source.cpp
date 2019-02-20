#include<iostream>
using namespace std;

class student {
public:
	int rollno, Mmarks, Pmarks, Cmarks, TotalMarks;
	string name;
	student() {

	}
	student(char* s, int x, int y, int z, int m, int n) {
		name = s;
		rollno = n;
		Mmarks = x;
		Pmarks = y;
		Cmarks = z;
		TotalMarks = m;

	}
	friend ostream & operator << (ostream &out, const student &c);
	friend istream & operator >> (istream &in, student &c);
	friend void generate_results(student* s, int n);

};
void generate_results(student* s, int n) {
	for (int i = 0;i < n;i++) {
		if (s[i].TotalMarks > 85) {
			cout << "A+";
		}
		else if (s[i].TotalMarks > 75) {
			cout << "A";
		}
		else if (s[i].TotalMarks > 65) {
			cout << "B";
		}
		else {
			cout << "F";
		}
		cout << endl;
	}
}
ostream& operator<<(ostream& out,student s1) {
	cout << "name:";
	//cout<<s1.name;
	cout << "rollno";
	cout << s1.rollno;

	cout << "Mathsmarks:";
	cout << s1.Mmarks;
	cout << "Pmarks:";
	cout << s1.Pmarks;
	cout << "Cmarks:";
	cout << s1.Cmarks;
	cout << "totalmarks:";
	cout << s1.TotalMarks;
	return out;
}
istream& operator >> (istream& in,student& s1) {
	cout << "name:";
    //in >> s1.name;
	cout << "rollno";
	in>>s1.rollno;
	cout << "Mathsmarks:";
	in>> s1.Mmarks;
	cout << "Pmarks:";
	in>> s1.Pmarks;
	cout << "Cmarks:";
	in>> s1.Cmarks;
	cout << "totalmarks:";
	in>> s1.TotalMarks;
	return in;
}

int main() {
	int n;
	cout << "enter no of students:";
		cin >> n;
		student st[100];
		for (int i = 0;i<n;i++) {
			cin >> st[i];
}
		generate_results(st, n);
		
			getchar();
			getchar();
			return 1;

}