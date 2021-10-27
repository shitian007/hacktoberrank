#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long dp[300000][20];
long sum[300000];

long find(int dec, long pos)
{
    int digit = 0;
    while (pos > dp[dec][digit])
        digit++;
    if (digit)
        pos -= dp[dec][digit - 1];
    else
        return dec;

    long num = 1;
    while (num < 10)
    {
        long firstDigit = num;
        firstDigit <<= digit;
        if (pos <= dp[dec - firstDigit][digit - 1])
        {
            dec -= firstDigit;
            break;
        }
        num++;
        pos -= dp[dec - firstDigit][digit - 1];
    }
    while (digit--)
        num *= 10;
    return num + find(dec, pos);
}

int main() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 10; i++) dp[i][0] = 1;
    for (int sum = 1; sum < 300000; sum++)
    {
        for (int digit = 1; digit < 20; digit++)
        {
            for (int num = 1; num < 10; num++) {
                long firstDigit = num;
                firstDigit <<= digit;
                if (firstDigit > sum) break;
                for (int digit2 = 0; digit2 < digit; digit2++)
                    dp[sum][digit] += dp[sum - firstDigit][digit2];
            }
        }
    }
    for (int sum = 0; sum < 300000; sum++)
        for (int digit = 1; digit < 20; digit++)
            dp[sum][digit] += dp[sum][digit - 1];
    sum[0] = 1;
    for (int i = 1; i < 300000; i++)
        sum[i] = dp[i][19] + sum[i - 1];

    int q;
    scanf("%d", &q);
    while (q--)
    {
        long x;
        scanf("%ld", &x);
        if (x == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int f = 0, r = 299999, mid;
        while (f < r)
        {
            mid = (f + r) / 2;
            if (x <= sum[mid])
                r = mid;
            else
                f = mid + 1;
        }
        if (f > 0)
            x -= sum[f - 1];
        cout<< find(f, x) <<endl;
    }

    return 0;
}