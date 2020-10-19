#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, arr[100010];

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;i++) scanf("%d", &arr[i]);
    int mindiff=2000000000;
    sort(arr, arr+N);
    for (int i=1;i<N;i++) {
        if (arr[i]-arr[i-1]<mindiff) mindiff=arr[i]-arr[i-1];
    }
    printf("%d\n", mindiff);
    return 0;
}