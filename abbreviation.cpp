#include <iostream>
#include <cstring>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string abbreviation(string a, string b) {
    bool dp[a.size() + 1][b.size() + 1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= a.size(); i++)
        dp[i][0] = true;
    for (int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j] || b[j] - 'A' + 'a' == a[i])
                dp[i + 1][j + 1] = dp[i][j];
            if (a[i] >= 'a' && a[i] <= 'z')
                dp[i + 1][j + 1] |= dp[i][j + 1];
        }
    }
    return dp[a.size()][b.size()] ? "YES" : "NO";
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
