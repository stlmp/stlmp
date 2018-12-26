#include "stlmp.h"

template <class T>
void stlmp::Sorting::BubbleSort<T>::sort(int length, T *v) {
    bool swapped = true;
    do {
        swapped = false;
        for (int i = 0; i < length - 1; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}
