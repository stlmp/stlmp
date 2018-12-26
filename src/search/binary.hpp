#include <algorithm>
#include <cmath>
#include "stlmp.h"

using namespace stlmp::Search;

template<class T>
T BinarySearch<T>::search(int arrayLength, T *ar, T target) {
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
