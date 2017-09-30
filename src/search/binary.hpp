#include <bits/stdc++.h>
#include "../sorting/quick.hpp"

using namespace std;

int _binary_search(int n,int a[],int target){
    /*
        for optimal performance the array needs to be sorted so we run quick sort 
        thus we make sure the array is sorted without having to check if it's sorted
        
        if we wanted to check  we can use is_sorted for algorithm header but it requires passing an array
        that accepts std::vector or std::array not C-like arrats
    */
    quick_sort(n,a);
    auto L = 0;
    auto R = n -1;
    while (L < R){
        float _x = (L+R)/2;
        auto m = floor(_x);
        if (a[m] < T){
            L = m+1;
        }
        else if(A[m]> T ){
            R = m - 1;
        }

    }
    return m;
}

int binary_search(int n,int a[],int target){
    return _binary_search(n,a,target);
}
