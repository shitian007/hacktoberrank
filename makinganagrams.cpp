#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    int cnt1[30], cnt2[30];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    for (int i = 0; i < a.size(); i++)
        cnt1[a[i] - 'a']++;
    for (int i = 0; i < b.size(); i++)
        cnt2[b[i] - 'a']++;

    int res = 0;
    for (int i = 0; i < 30; i++) {
        int small = min(cnt1[i], cnt2[i]);
        res += cnt1[i] - small;
        res += cnt2[i] - small;
    }

    return res;
}

int main()
{

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}
