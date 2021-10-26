#include <string>
#include <cstring>
#include <iostream>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

bool isSame(int cnt[30])
{
    int prev = 0;
    for (int i = 0; i < 30; i++)
    {
        if (cnt[i])
        {
            if (!prev)
                prev = cnt[i];
            else if (prev != cnt[i])
                return false;
        }
    }
    return true;
}

string isValid(string s) {
    int cnt[30];
    memset(cnt, 0, sizeof(cnt));
    for (size_t i = 0; i < s.size(); i++)
        cnt[s[i] - 'a']++;
    if (isSame(cnt))
        return "YES";
    for (int i = 0; i < 30; i++)
    {
        if (cnt[i])
        {
            cnt[i]--;
            if (isSame(cnt))
                return "YES";
            cnt[i]++;
        }
    }
    return "NO";
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
