#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, D, expend[200010], hashTable[300];

int getNum(int rank) {
    int ttrank=0;
    for (int i=0;i<=200;i++) {
        if (ttrank+hashTable[i]>=rank) return i;
        ttrank+=hashTable[i];
    }
    return 0;
}

int isPossibleFrad(int i) {
    if (D%2==1) {
        if (getNum((D+1)/2)*2<=expend[i]) return true;
    } else {
        if (getNum(D/2)+getNum(D/2+1)<=expend[i]) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &D);
    for (int i=0;i<N;i++) scanf("%d", &expend[i]);
    memset(hashTable, 0, sizeof(hashTable));
    int fradCnt=0;
    for (int i=0;i<D;i++) hashTable[expend[i]]++;
    for (int i=D;i<N;i++) {
        if (isPossibleFrad(i)) fradCnt++;
        hashTable[expend[i]]++;
        hashTable[expend[i-D]]--;
    }
    printf("%d\n", fradCnt);
    return 0;
}