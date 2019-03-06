#include<string>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
double divi(double, double);
double addicalc(double, double);
double subcalc(double, double);
double mul(double, double);
bool areParanthesisBalanced(string expr)
{
	stack<char> s;
	char x;

	
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
		{
			
			s.push(expr[i]);
			continue;
		}

		
		if (s.empty())
			return true;

		switch (expr[i])
		{
		case ')':

			
			x = s.top();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			
			x = s.top();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			
			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}

	
	return (s.empty());
}
int postfixeval(string s) {
	stack<double> st;
	st.push(0);
	//string s;
	//cin >> s;
	double c1, c2;
	int i = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i])) {
			double a = (double)s[i];
			//cout<<a-48;
			st.push(a - 48);
		}
		else {
			if (s[i] == '*') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = mul(c1,c2);
				st.push(s);
			}
			if (s[i] == '/') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = divi(c1,c2);
				st.push(s);
			}
			if (s[i] == '+') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = addicalc(c1,c2);
				st.push(s);
			}
			if (s[i] == '-') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = subcalc(c2,c1);
				st.push(s);
			}
		}

	}
	cout << st.top();
	return 0;
}
int prec(char c)
{
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
int main() {
	stack<char> st;
	st.push('N');

	string s, ns,ns1;
	cin >> s;
	if (areParanthesisBalanced(s)) {
		cout << "Balanced"<<endl;
	}
	else {
		cout << "Not Balanced"<<endl;
		system("pause");
		return 0;
	}
	int l = s.length();
	char c;

	for (int i = 0; i < l; i++) {
		if (isdigit(s[i])) {
			ns += s[i];
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (st.top() != 'N'&&st.top() != '(') {
				c = st.top();
				st.pop();
				ns += c;
			}
			if (st.top() == '(') {
				c = st.top();
				st.top();
			}
		}
		else {
			while (st.top() != 'N'&&prec(s[i]) <= prec(st.top())) {
				c = st.top();
				st.pop();
				ns += c;
			}
			st.push(s[i]);
		}
	}
	while (st.top() != 'N') {
		c = st.top();
		st.pop();
		ns += c;
	}
	for (int i = 0; i < l; i++) {
		if (ns[i] == '(') {
			continue;
		}
		ns1 += ns[i];
	}
	postfixeval(ns1);
	system("pause");
	return 0;
}
