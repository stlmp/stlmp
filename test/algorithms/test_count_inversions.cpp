#include <cassert>
#include "stlmp.h"

int main(){
	int arr[] = {9, 3, 10, 11, 1};
    int arr_size = 5;
    int ans = stlmp::algorithms::CountInversionsInArray(arr,arr_size);

    assert(ans == 5);
}
