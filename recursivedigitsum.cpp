#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char num[100010];
    long long sum=0, mul;
    scanf("%s%lld", num, &mul);
    int len=strlen(num);
    for (int i=0;i<len;i++) sum+=num[i]-'0';
    sum*=mul;
    while (sum>10) {
        long long newsum=0;
        while (sum) {
            newsum+=sum%10;
            sum/=10;
        }
        sum=newsum;
    }
    printf("%lld\n", sum);
    return 0;
}