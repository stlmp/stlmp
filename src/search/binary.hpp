#include <algorithm>
#include <cmath>
#include "stlmp.h"

using namespace stlmp::Search;

template<class T>
T BinarySearch<T>::search(int arrayLength, T *ar, T target) {
    /*
        for optimal performance the array needs to be sorted so we run quick sort
        thus we make sure the array is sorted without having to check if it's sorted

        if we wanted to check  we can use is_sorted for algorithm header but it requires passing an array
        that accepts std::vector or std::array not C-like arrays
    */
    // quick_sort(n, a);
    auto left = 0;
    auto right = arrayLength - 1;
    while (left <= right) {
        auto middle = left + (right - left) / 2;
        if (ar[middle] == target) {
            return middle;
        } else if (ar[middle] > target) {
            // decrease right search part
            right = middle - 1;
        } else if (ar[middle] < target) {
            left = middle + 1;
        }
    }
    return -1;
}
