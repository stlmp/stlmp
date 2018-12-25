//
// Created by manparvesh on 12/25/18.
//
#include <cassert>
#include "stlmp.h"

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    stlmp::algorithms::RotateArray(arr, d, n);

    assert(arr[0] == 3);
    assert(arr[1] == 4);
    assert(arr[2] == 5);
    assert(arr[3] == 6);
    assert(arr[4] == 7);
    assert(arr[5] == 1);
    assert(arr[6] == 2);
}
