#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int N;
long long offset[30];
char str[110];

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%s", str);
    string s = string(str);
    long long ans=0;
    for (int len=1;len<s.size(); len++) {
      map<string, int> smap;
      for (int j=0;j+len<=s.size(); j++) {
	string ss = s.substr(j, len);
	sort(ss.begin(), ss.end());
	smap[ss]++;
      }
      for (map<string, int>::iterator it=smap.begin(); it!=smap.end(); it++) {
	long long cnt=it->second;
	ans+=cnt*(cnt-1)/2;
      }
    }
    printf("%lld\n", ans);
  }
}
