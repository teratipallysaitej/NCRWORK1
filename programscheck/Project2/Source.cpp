#include<string>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
double divi(double, double);
double addicalc(double, double);
double subcalc(double, double);
double mul(double, double);
#include <string>
#include <stack>
#include <iostream>
using namespace std;
int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	return 0;
}
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
double Operation(double a, double b, char op) {
	switch (op) {
	case '+': return addicalc(a,b);
	case '-': return subcalc(a, b);
	case '*': return mul(a,b);
	case '/': return divi(a,b);
	case '^': return pow(a, b);

	}
}

double evaluate(string str) {
	int i;
	stack <double> values;

	stack <char> ops;

	for (i = 0; i < str.length(); i++) {

		if (str[i] == ' ')
			continue;

		else if (str[i] == '(') {
			ops.push(str[i]);
		}

		else if (isdigit(str[i])) {
			double val = 0;

			while (i < str.length() && isdigit(str[i]))
			{
				val = (val * 10) + (str[i] - '0');
				i++;
			}
			i--;
			values.push(val);
		}


		else if (str[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				double val2 = values.top();
				values.pop();

				double val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(Operation(val1, val2, op));
			}


			ops.pop();
		}


		else
		{
			while (!ops.empty() && precedence(ops.top())
				>= precedence(str[i])) {
				double val2 = values.top();
				values.pop();

				double val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(Operation(val1, val2, op));
			}


			ops.push(str[i]);
		}
	}


	while (!ops.empty()) {
		double val2 = values.top();
		values.pop();

		double val1 = values.top();
		values.pop();

		char op = ops.top();
		ops.pop();

		values.push(Operation(val1, val2, op));
	}

	return values.top();
}

int main() {
	string s;
	cin >> s;
	if(areParanthesisBalanced(s)) {
		
	}
	else {
	cout << "invalid" << endl;
	system("pause");
	return 0;
	}
	cout << evaluate(s);
	system("pause");
	return 0;
}