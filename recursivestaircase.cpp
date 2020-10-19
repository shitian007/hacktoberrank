#include <iostream>
#include <cstdio>

using namespace std;

int dp[40];

int main() {
    dp[0]=1;
    for(int i=1;i<=36;i++) {
        dp[i]=dp[i-1];
        if (i>=2) dp[i]+=dp[i-2]; dp[i]%=10000000007;
        if (i>=3) dp[i]+=dp[i-3]; dp[i]%=10000000007;
    }
    int S;
    scanf("%d", &S);
    while (S--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }
    return 0;
}