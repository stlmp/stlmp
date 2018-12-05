#include <algorithm>
using namespace std;

int _interpolation_search(int arr[], int n, int x) 
{ 
    // Find indexes of two corners 
    int lo = 0, hi = (n - 1); 
  
    // Since array is sorted, an element present 
    // in array must be in range defined by corner 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
    { 
        // Probing the position with keeping 
        // uniform distribution in mind. 
        int pos = lo + (((double)(hi-lo) / 
              (arr[hi]-arr[lo]))*(x - arr[lo])); 
  
        // Condition of target found 
        if (arr[pos] == x) 
            return pos; 
  
        // If x is larger, x is in upper part 
        if (arr[pos] < x) 
            lo = pos + 1; 
  
        // If x is smaller, x is in the lower part 
        else
            hi = pos - 1; 
    } 
    return -1; 
} 

int interpolation_search(int n, int a[], int x)
{
    return _interpolation_search(a, n, x);
}

