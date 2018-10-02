#include <iostream>
using namespace std;

/*Function to reverse arr[] from index start to end*/
void rvereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n)
{
	rvereseArray(arr, 0, d - 1);
	rvereseArray(arr, d, n - 1);
	rvereseArray(arr, 0, n - 1);
}
