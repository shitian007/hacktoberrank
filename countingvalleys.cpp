#include<iostream>
#include<cstdio>

using namespace std;

int N;
char str[1000010];

int main() {
  scanf("%d%s", &N, str);
  int lvl=0,valley=0;
  for (int i=0;i<N;i++) {
    if (str[i]=='U') {
      lvl++;
      if (lvl==0) valley++;
    } else {
      lvl--;
    }
  }
  if (lvl<0) valley++;
  printf("%d\n", valley);
  return 0;
}
