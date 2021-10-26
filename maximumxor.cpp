#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

bool findGreaterOrEqual(vector<int>& arr, size_t& f, size_t& r, int mask)
{
    if (f > r)
        return false;
    if (!(arr[r] & mask))
        return false;
    size_t tf = f, tr = r, mid;
    while (tf < tr)
    {
        mid = (tf + tr) / 2;
        if (arr[mid] & mask)
            tr = mid;
        else
            tf = mid + 1;
    }
    f = tf;
    return true;
}

bool findSmallerOrEqual(vector<int>& arr, size_t& f, size_t& r, int mask)
{
    if (f > r)
        return false;
    if (arr[f] & mask)
        return false;
    size_t tf = f, tr = r, mid;
    while (tf < tr)
    {
        mid = (tf + tr + 1) / 2;
        if (arr[mid] & mask)
            tr = mid - 1;
        else
            tf = mid;
    }
    r = tr;
    return true;    
}

// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> queries) {
    // solve here
    vector<int> res;
    sort(arr.begin(), arr.end());
    for (int q : queries)
    {
        size_t f = 0, r = arr.size() - 1;
        int ans = 0;
        for (int shift = 30; shift >= 0; shift--)
        {
            int mask = int(1) << shift;
            if (!(q & mask))
            {
                if (findGreaterOrEqual(arr, f, r, mask))
                    ans |= mask;
            }
            else
            {
                if (findSmallerOrEqual(arr, f, r, mask))
                    ans |= mask;
            }
        }
        res.push_back(ans);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
