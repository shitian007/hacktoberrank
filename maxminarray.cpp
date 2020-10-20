#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, K, arr[100010];

int main() {
    scanf("%d%d", &N, &K);
    for (int i=0;i<N;i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    int unfairness=1000000000;
    for (int i=0;i<=N-K;i++) {
        if (arr[i+K-1]-arr[i]<unfairness) unfairness=arr[i+K-1]-arr[i];
    }
    printf("%d\n", unfairness);
    return 0;
}