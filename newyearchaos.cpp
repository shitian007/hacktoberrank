#include<iostream>
#include<cstdio>

using namespace std;

int N,M,arr1[100010],arr2[100010];

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &M);
    for (int i=1;i<=M;i++) scanf("%d", &arr1[i]);
    int bribe = 0;
    for (int i=1;i<=M;i++) arr2[i]=i;
    for (int i=1;i<=M;i++) {
      if (arr1[i]==arr2[i]){
      } else if (arr1[i]==arr2[i+1]) {
	bribe++;
	arr2[i+1]^=arr2[i]^=arr2[i+1]^=arr2[i];
      } else if (arr1[i]==arr2[i+2]) {
	bribe+=2;
	arr2[i+2]^=arr2[i+1]^=arr2[i+2]^=arr2[i+1];
	arr2[i+1]^=arr2[i]^=arr2[i+1]^=arr2[i];
      } else {
	bribe=-1;
	break;
      }
    }
    if (bribe==-1) printf("Too chaotic\n");
    else printf("%d\n", bribe);
  }
}
