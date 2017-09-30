#include <algorithm>
#include "../sorting/quick.hpp"

using namespace std;

int _binary_search(int n, int a[], int target)
{
    /*
        for optimal performance the array needs to be sorted so we run quick sort 
        thus we make sure the array is sorted without having to check if it's sorted
        
        if we wanted to check  we can use is_sorted for algorithm header but it requires passing an array
        that accepts std::vector or std::array not C-like arrats
    */
    quick_sort(n, a);
    auto left = 0;
    auto right = n - 1;
    while (left < right)
    {
        float _middle = (left + right) / 2; //place holder for middle position in the array
        auto position = floor(_middle);
        if (a[position] < T)
        {
            left = position + 1;
        }
        else if (A[position] > T)
        {
            right = position - 1;
        }
    }
    return position;
}

int binary_search(int n, int a[], int target)
{
    return _binary_search(n, a, target);
}
