#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int length, int v[]){
	bool swapped = true;
	do{
		swapped = false;
		for(int i=0;i<length-1;i++){
			if(v[i] > v[i+1]){
				swap(v[i], v[i+1]);
				swapped = true;
			}
		}
	}while(swapped);
}