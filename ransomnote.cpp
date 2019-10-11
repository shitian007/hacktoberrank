#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

map<string, int> wordmap;
int N, M;
char str[20];

int main() {
  scanf("%d%d", &N, &M);
  while (N--) {
    scanf("%s", str);
    wordmap[str]++;
  }
  bool can=true;
  while (M--) {
    scanf("%s", str);
    wordmap[str]--;
    if (wordmap[str]<0) can=false;
  }
  if (can) printf("Yes\n");
  else printf("No\n");
  return 0;
}
