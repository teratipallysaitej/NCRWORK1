#include<iostream>
#include <stdio.h> 
using namespace std;
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	
	for (i = 0; i < n - 1; i++)
	{
		
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		
		swap(&arr[min_idx], &arr[i]);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int n;
	cin>>n;
	cout << "enter array:";
	int *arr=NULL;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	free(arr);
	system("pause");
	return 0;
}
