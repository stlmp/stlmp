#include "stlmp.h"

template<class T>
void stlmp::Sorting::InsertionSort<T>::sort(int length, T v[]) {
    int j;
    for (int i = 0; i < length; i++) {
        j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}