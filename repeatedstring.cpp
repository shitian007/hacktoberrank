#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char str[110];
long long N;

int main () {
  scanf("%s%lld", str, &N);
  long long acnt = 0, len=strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i]=='a') acnt++;
  }
  long long ans=N/len*acnt;
  for (int i=0; i < N%len; i++) {
    if (str[i]=='a') ans++;
  }
  printf("%lld\n",ans);
  return 0;
}
