#include <iostream>
#include <cstdio>

using namespace std;

int D, N, arrcpy[100010];
long long inv;

void mergesort(int arr[], int f, int r)
{
    if (f >= r) return;
    int mid =(f+r)/2;
    mergesort(arr, f, mid);
    mergesort(arr, mid+1, r);
    int i=f,j=mid+1,newi=f;
    while (i<=mid && j<=r) {
        if (arr[i]<=arr[j]) {
            arrcpy[newi]=arr[i];
            i++;
        } else {
            arrcpy[newi]=arr[j];
            j++;
            inv+=mid-i+1;
        }
        newi++;
    }
    while (i<=mid) {
        arrcpy[newi]=arr[i];
        i++;
        newi++;
    }
    while (j<=r) {
        arrcpy[newi]=arr[j];
        j++;
        newi++;
    }
    for (newi=f; newi<=r; newi++) arr[newi]=arrcpy[newi];
}

int main() {
    scanf("%d", &D);
    while (D--) {
        scanf("%d",&N);
        int arr[N];
        for (int i=0;i<N;i++) scanf("%d", &arr[i]);
        inv=0;
        mergesort(arr, 0, N-1);
        printf("%lld\n", inv);
    }
    return 0;
}