#include <stdio.h> 
#include <math.h> 
#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



int main()
{
	int n;
	cin >> n;
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	insertionSort(arr, n);
	printArray(arr, n);
	free(arr);
	system("pause");
	return 0;
}