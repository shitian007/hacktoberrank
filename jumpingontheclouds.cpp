#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N, arr[110], dp[110];

int main() {
  scanf("%d", &N);
  for (int i=0;i<N;i++) scanf("%d", &arr[i]);
  memset(dp, -1, sizeof(dp));
  dp[0]=0;
  for (int i=1;i<N;i++) {
    if (arr[i]==0) {
      if (dp[i-1]!=-1) dp[i]=dp[i-1]+1;
      if (i>1 && dp[i-2]!=-1) {
	if (dp[i]==-1 || dp[i-2]+1<dp[i]) dp[i]=dp[i-2]+1;
      }
    }
  }
  
  printf("%d\n", dp[N-1]);
  return 0;
}
