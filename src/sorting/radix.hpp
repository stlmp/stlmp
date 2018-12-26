#include "stlmp.h"
using namespace stlmp::Sorting;

template <class T>
void RadixSort<T>::_count_sort(T arr[], int length, int exp) {
    int output[length]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < length; i++) count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++) count[i] += count[i - 1];

    // Build the output array
    for (i = length - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < length; i++) arr[i] = output[i];
}

template <class T>
void RadixSort<T>::sort(int length, T v[]) {
    int mx = *max_element(v, v + length);
    for (int i = 1; mx / i > 0; i *= 10) {
        _count_sort(v, length, i);
    }
}