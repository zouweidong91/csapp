#include <stdio.h>

// 二分查找

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main(){
    int v[] = {1,2,3,4,7,8};
    int n, i;
    n = 10;
    i = binsearch(7, v, n);
    printf("%d\n", i);
}