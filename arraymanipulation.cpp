#include<iostream>
#include<cstdio>

using namespace std;

int N, M;
long long fenwick[10000010], ans=0;

int lowbit(int a) {return a&(-a);}

void update(int i, long long v) {
  while (i<=N) {
    fenwick[i]+=v;
    i+=lowbit(i);
  }
}

long long query(int i) {
  long long res=0;
  while (i>0) {
    res+=fenwick[i];
    i-=lowbit(i);
  }
  return res;
}

int main() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int st, ed;
    long long val;
    scanf("%d%d%lld", &st, &ed, &val);
    update(st, val);
    update(ed+1, -val);
  }
  for (int i=1;i<=N;i++) {
    long long t=query(i);
    if (t>ans) ans=t;
  }
  printf("%lld\n", ans);
  return 0;
}
