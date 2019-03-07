#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int stringLen(char *str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}

char* stringCat(char* s1,  char* s2)
{
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i);

	for (j = 0; s2[j] != '\0'; ++j, ++i)
	{
		s1[i] = s2[j];
	}

	s1[i] = '\0';

	return s1;
}


char* stringCopy(char* source, char* destination) {
	int i = 0;
	for (i = 0; source[i] != '\0'; ++i)
	{
		destination[i] = source[i];
	}

	destination[i] = '\0';
	return destination;
}


int stringCmp(char * str1,  char* str2)

{
	int i = 0, j = 0;
	while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 == *str2)
	{
		return 1; // strings are identical
	}

	else
	{
		return 0;
	}
}

char* stringRev(char *s)
{
	char temp;
	int i, j;
	for ( i = 0,  j =  stringLen(s) - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}


int main()
{
	int option, res;
	char *str1;
	str1 = (char*)malloc(100 * sizeof(char));
	char *str2;
	str2 = (char*)malloc(100 * sizeof(char));

	printf("Enter an operation to be performed.\n1.stringCopy()\n2.stringCat()\n3.strRev()\n4.stringCmp()\n5.stringLen() and enter a number greater than 5 to break out of loop");
	cout << endl;
	scanf_s("%d", &option);
	
	while (option <= 5)
	{
		switch (option)
		{
		case 1:
		{   cout << "enter source and destination strings" << endl;
		cin >> str1 >> str2;
			stringCopy( str2,str1);
			
			printf("Copied string is :%s\n", str1);
			break;
		}

		case 2:
		{   cout << "enter strings:" << endl;
		cin >> str1;
		cin >> str2;
			stringCat(str1, str2);
			printf("Concatenated String is: %s\n", str1);
			break;
		}

		case 3:
		{    
			cout << "enter string to be reversed:";
			cin >> str1;
			printf("Reversed string is %s", stringRev(str1));
			break;

		}

		case 4:
		{   cout << "enter strings:";
		cin >> str1 >> str2;
		res = strcmp(str1, str2);
			if (res == 1)
				printf("Strings are equal\n");
			else
				printf("Strings are not equal\n");
			break;
		}

		case 5:
		{  cout << "enter strin:";
		cin >> str1;
			printf("length of first string is %d\n", stringLen(str1));
			
			break;
		}

		default:break;
		}

		printf("\nChoose another operation to be performed :");
		scanf_s("%d", &option);
	}
	free(str1);
	free(str2);
	return 0;
}