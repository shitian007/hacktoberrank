#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N, charcnt[30];
char str1[100010],str2[100010];

int main () {
  scanf("%d", &N);
  while (N--) {
    scanf("%s%s", str1, str2);
    int len1=strlen(str1),len2=strlen(str2);
    memset(charcnt,0,sizeof(charcnt));
    for (int i=0;i<len1;i++) charcnt[str1[i]-'a']++;
    bool can=false;
    for (int i=0;i<len2;i++) {
      if (charcnt[str2[i]-'a']>0) can=true;
    }
    if (can) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
