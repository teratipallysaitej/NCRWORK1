#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	char a[100];
	int top = -1;
	cin >> s;
	int count = 0;
	int i = 0;
	int flag = 0;
	char ch;
	while (s[i] != '\0') {
		ch = s[i];
		switch (ch) {
		case '{':
			a[++top] = ch;
			++count;
			break;
		case '(':
			a[++top] = ch;
			++count;
			break;
		case '[':
			a[++top] = ch;
			++count;
			break;
		case '}':
			--top;
			if (top>=0&&a[top] == '[' || a[top] == '(') {
				cout << top;
				flag = 1;
				goto A;
			}
			
		case ']':
			--top;
			if (top>=0&&a[top] == '{' || a[top] == '(') {
				flag = 1;
				goto A;
			}
			
		case ')':
			--top;
			if (top>=0&&a[top] == '[' || a[top] == '{') {
				flag = 1;
				goto A;
			}
		default:
			break;
		}
		i++;

	}
A:
	for (int i = 0;i<count;i++) {
		cout << a[i] << endl;
	}
	if (flag == 1) {
		cout << "not matching";
	}
	else {
		cout << "matching";
	}
	return 0;
	getchar();
	getchar();
}