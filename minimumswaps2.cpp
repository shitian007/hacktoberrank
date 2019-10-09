#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N, arr[100010], explored[100010];

int main() {
  scanf("%d", &N);
  for (int i=1;i<=N;i++) scanf("%d", &arr[i]);
  memset(explored, false, sizeof(explored));
  int swaps=0;
  for (int i=1;i<=N;i++) {
    if (!explored[i]) {
      explored[i]=true;
      int pt=arr[i];
      while (pt!=i) {
	explored[pt]=true;
	swaps++;
	pt=arr[pt];
      }
    }
  }
  printf("%d\n", swaps);
  return 0;
}
