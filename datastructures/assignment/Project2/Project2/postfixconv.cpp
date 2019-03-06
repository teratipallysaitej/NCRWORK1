#include<iostream>
#include<stack>
using namespace std;
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

	string s, ns;
	cin >> s;
	int l = s.length();
	char c;

	for (int i = 0; i < l; i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
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
		cout << ns[i];
	}
	system("pause");
	return 0;
}
