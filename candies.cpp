#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    vector<pair<int, int>> candyInds;
    for (int i = 0; i < arr.size(); i++)
        candyInds.push_back(make_pair(arr[i], i));
    sort(candyInds.begin(), candyInds.end());
    vector<int> res;
    res.resize(arr.size(), 1);
    long ans = 0;
    for (auto& p : candyInds)
    {
        int i = p.second;
        if (i > 0 && arr[i - 1] < arr[i])
            res[i] = max(res[i], res[i - 1] + 1);
        if (i + 1 < arr.size() && arr[i + 1] < arr[i])
            res[i] = max(res[i], res[i + 1] + 1);
        ans += res[i];
    }
    return ans;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    cout << result << "\n";

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
