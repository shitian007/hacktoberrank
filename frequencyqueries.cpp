#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int countarr[1000010],N;
map<int, int> mymap;

int main() {
  scanf("%d", &N);
  while (N--) {
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    if (t1==1) {
      mymap[t2]++;
      int cnt = mymap[t2];
      countarr[cnt]++;
      if (cnt>1) countarr[cnt-1]--;
    } else if (t1==2) {
      if (mymap[t2]) {
	mymap[t2]--;
	int cnt=mymap[t2];
	if (cnt>0) countarr[cnt]++;
	countarr[cnt+1]--;
      }
    } else {
      if (t2<1000005 && countarr[t2]) printf("1\n");
      else printf("0\n");
    }
  }
  return 0;
}
