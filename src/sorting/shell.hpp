#include <bits/stdc++.h>
using namespace std;

void shell_sort(int length, int v[]){
    int j, temp, swp;
    int d = length/2;
    swp = 1;
    while(swp || (d > 1)){
        swp = 0;
        d = (d + 1) / 2;
        for(int i=0;i<length-d;i++){
            if(v[i] > v[i+d]){
                swap(v[i+d], v[i]);
                swp = 1;
            }
        }
    } 
}
