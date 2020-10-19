#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> important;

int main()
{
    scanf("%d%d", &N, &K);
    long long ans=0;
    while (N--) {
        int L, T;
        scanf("%d%d", &L, &T);
        if (T==0) ans+=L;
        else important.push_back(L);
    }
    sort(important.begin(), important.end());
    for (int i=0; i<important.size(); i++) {
        if (i>=int(important.size())-K)
            ans+=important[i];
        else ans-=important[i];
    }
    printf("%lld\n", ans);
    return 0;
}