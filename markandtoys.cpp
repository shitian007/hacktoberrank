#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, P;
    scanf("%d%d", &N, &P);
    int arr[100010];
    for (int i=0;i<N;i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    int ans=0;
    while (ans<N && P>arr[ans]) {
        P-=arr[ans];
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}