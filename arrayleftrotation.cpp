#include<iostream>
#include<cstdio>

using namespace std;

int N, D, arr[100010], ans[100010];

int main() {
  scanf("%d%d", &N, &D);
  for (int i=0;i<N;i++) scanf("%d", &arr[i]);
  for (int i=0;i<N;i++) ans[i]=arr[(i+D)%N];
  printf("%d", ans[0]);
  for (int i=1;i<N;i++) printf(" %d", ans[i]);
  printf("\n");
  return 0;
}
