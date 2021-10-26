#include <string>
#include <iostream>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    // find type 1 string
    long long ans = 0;
    size_t st = 0;
    while(st < s.size())
    {
        size_t ed = st;
        while (ed + 1 < s.size() && s[st] == s[ed + 1])
            ed++;
        long long len = ed - st + 1;
        ans += len * (len + 1) / 2;
        st = ed + 1;
    }
    // find type 2 string
    for (size_t mid = 1; mid < s.size() - 1; mid++)
    {
        if (s[mid - 1] == s[mid + 1] && s[mid - 1] != s[mid])
        {
            size_t len = 1;
            while (mid > len + 1 && mid + len + 1 < s.size()
                   && s[mid - len - 1] == s[mid - len] && s[mid + len + 1] == s[mid + len])
                len++;
            ans += len;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    cout << result << "\n";

    return 0;
}
