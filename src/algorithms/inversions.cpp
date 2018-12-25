#include <vector>
#include <algorithm>
#include "../../include/stlmp.h"

int getSum(const int *bit, int index) {
    int a = 0;
    while (index > 0) {
        a += bit[index];
        index -= (index & (-index));
    }
    return a;
}

void update(int bit[], int index, int n) {
    while (index <= n) {
        bit[index]++;
        index += (index & (-index));
    }
}

int stlmp::algorithms::CountInversionsInArray(int array[], int n) {
    std::vector<int> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = array[i];
    std::sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        array[i] = static_cast<int>(lower_bound(temp.begin(), temp.end(), array[i]) - temp.begin() + 1);
    }
    int bit[n + 1];
    for (int i = 0; i < n + 1; i++)
        bit[i] = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += getSum(bit, array[i] - 1);
        update(bit, array[i], n);
    }
    return ans;
}
