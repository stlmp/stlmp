#include <iostream>
using namespace std;

void reverse_array_util(int arr[], int start, int end)
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

void reverse_array(int arr[], int d, int n)
{
	reverse_array_util(arr, 0, d - 1);
	reverse_array_util(arr, d, n - 1);
	reverse_array_util(arr, 0, n - 1);
}
