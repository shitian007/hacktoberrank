#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;
long long ans=0, arr[200];

int main() {
    scanf("%d%d", &N, &K);
    for (int i=0;i<N;i++) scanf("%lld", &arr[i]);
    sort(arr, arr+N, greater<long long>());
    for (int i=0;i<N;i++) {
        ans+=arr[i]*(i/K+1);
    }
    printf("%lld\n", ans);
    return 0;
}