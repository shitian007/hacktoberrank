#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    if (N<=1)
        printf("%d", N);
    else {
        int num1=0, num2=1;
        for (int i=2;i<=N;i++) {
            num2+=num1;
            num1=num2-num1;
        }
        printf("%d\n", num2);
    }
    return 0;
}