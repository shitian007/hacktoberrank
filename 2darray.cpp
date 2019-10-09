#include<iostream>
#include<cstdio>

using namespace std;

int dir[7][2] = {{0,0}, {0,1}, {0,2}, {1,1}, {2,0}, {2,1}, {2,2}};
int N=6, arr[10][10], ans=-70;

int main() {
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) scanf("%d", &arr[i][j]);
  }
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      int val=0;
      for (int k=0;k<7;k++) {
	val+=arr[i+dir[k][0]][j+dir[k][1]];
      }
      if (val>ans) ans=val;
    }
  }
  printf("%d\n", ans);
  return 0;
}
