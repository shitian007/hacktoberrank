#include<iostream>
#include<cstdio>

using namespace std;

int N, arr[120];

int main() {
  scanf("%d", &N);
  while (N--) {
    int t;
    scanf("%d", &t);
    arr[t]++;
  }
  int pairs=0;
  for (int i=1;i<=100;i++) pairs+=arr[i]/2;
  printf("%d\n", pairs);
  return 0;
}
