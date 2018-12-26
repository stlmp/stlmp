#include "stlmp.h"
using namespace stlmp::Sorting;

template <class T>
T SelectionSort<T>::_get_min(int length, T v[], int i){
	int min = i;
	while(i < length){
		min = v[min] < v[i] ? min : i;
		i++;
	}
	return min;
}

template <class T>
void SelectionSort<T>::sort(int length, T v[]){
	int min = _get_min(length, v, 0);
	swap(v[0], v[min]);
	for(int i=0;i<length-1;i++){
		min = _get_min(length, v, i+1);
		swap(v[i+1], v[min]);
	}
}