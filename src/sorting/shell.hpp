#include<bits/stdc++.h>
 using namespace std;
 
void Shell_Sort(int a[], int n)
{
	int i, j, k, temp;
	// Gap 'i' between index of the element to be compared, initially n/2.
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				// If value at higher index is greater, then break the loop.
				if(a[k+i] >= a[k])
				break;
				// Switch the values otherwise.
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
				}
			}
		}
	}
}
