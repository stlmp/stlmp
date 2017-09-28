#include <bits/stdc++.h>
using namespace std;
 
void heapsort(int a[], int size)
{
  int l = 0, r = size;
  make_heap(a, size);
 
  while ( r > 1)
  {
    int tmp = a[0];
    --r;
    a[0] = a[r];
    a[r] = tmp;
    sift(a, r,0);
  }
}
