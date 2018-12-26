//
// Created by manparvesh on 12/25/18.
//
#include "stlmp.h"

void rotateArrayUtil_(int *array, int start, int end) {
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

void stlmp::algorithms::RotateArray(int *array, int rotations, int arraySize) {
    rotateArrayUtil_(array, 0, rotations - 1);
    rotateArrayUtil_(array, rotations, arraySize - 1);
    rotateArrayUtil_(array, 0, arraySize - 1);
}
