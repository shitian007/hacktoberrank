#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

map<int, long long> map1, map2;
int N, M;
long long ans=0;

int main() {
  scanf("%d%d", &N, &M);
  for (int i =0; i<N;i++) {
    long long tmp;
    scanf("%lld", &tmp);
    if (tmp%M==0) {
      ans+=map2[tmp/M];
      map2[tmp]+=map1[tmp/M];
    }
    map1[tmp]++;
  }
  printf("%lld\n", ans);
  return 0;
}
