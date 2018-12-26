#include "stlmp.h"

using namespace std;

template<class T>
T FibonacciSearch<T>::search(int n, T *arr, T x) {
    /*
        for optimal performance the array needs to be sorted so we run quick sort 
        thus we make sure the array is sorted without having to check if it's sorted
        
        if we wanted to check  we can use is_sorted for algorithm header but it requires passing an array
        that accepts std::vector or std::array not C-like arrats
    */
    // quick_sort(n, arr);
    /*Fibonacci Searching algorithm */
    /* Initialize fibonacci numbers */
    int fib_m2 = 0;   // (m-2)'th Fibonacci No.
    int fib_m1 = 1;   // (m-1)'th Fibonacci No.
    int fib_m = fib_m2 + fib_m1;  // m'th Fibonacci

    /* fib_m is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fib_m < n) {
        fib_m2 = fib_m1;
        fib_m1 = fib_m;
        fib_m = fib_m2 + fib_m1;
    }

    // Marks the eliminated range from front
    int offset = -1;

    /* while there are elements to be inspected. Note that
       we compare arr[fib_mm2] with x. When fib_m becomes 1,
       fib_mm2 becomes 0 */
    while (fib_m > 1) {
        // Check if fib_mm2 is a valid location
        int index = min(offset + fib_m2, n - 1);

        /* If x is greater than the value at index fib_mm2,
           cut the subarray array from offset to i */
        if (arr[index] < x) {
            fib_m = fib_m1;
            fib_m1 = fib_m2;
            fib_m2 = fib_m - fib_m1;
            offset = index;
        }

            /* If x is greater than the value at index fib_mm2,
               cut the subarray after i+1  */
        else if (arr[index] > x) {
            fib_m = fib_m2;
            fib_m1 = fib_m1 - fib_m2;
            fib_m2 = fib_m - fib_m1;
        }

            /* element found. return index */
        else return index;
    }
    /* comparing the last element with x */
    if (fib_m1 && arr[offset + 1] == x)
        return offset + 1;
    /*element not found. return -1 */
    return -1;
}
