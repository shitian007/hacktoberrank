#include <string>
#include <iostream>
#include <cstring>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2) {
    int dp[2][5010];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] != s2[j])
                dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
            else
                dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
        }
    }
    return dp[s1.size() % 2][s2.size()];
}

int main()
{
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    cout << result << "\n";

    return 0;
}
