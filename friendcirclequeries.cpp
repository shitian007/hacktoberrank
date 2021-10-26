#include <iostream>
#include <vector>
#include <map>

using namespace std;

int getInd(int v, map<int, int>& toInd) {
    if (toInd.find(v) == toInd.end())
        toInd[v] = toInd.size();
    return toInd[v];
}

int findRoot(int u, vector<int>& root, vector<int>& tot)
{
    if (root[u] == u)
        return u;
    int newroot = findRoot(root[u], root, tot);
    if (newroot != root[u])
        tot[root[u]] -= tot[u];
    root[u] = newroot;
    return root[u];
}

void ufds(int u, int v, vector<int>& root, vector<int>& tot)
{
    int rootu = findRoot(u, root, tot), rootv = findRoot(v, root, tot);
    if (rootu != rootv)
    {
        tot[rootv] += tot[rootu];
        root[rootu] = rootv;
    }
}

// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
    vector<int> res, root, tot;
    for (size_t i = 0; i < queries.size() * 2; i++)
        root.push_back(i);
    tot.resize(queries.size() * 2, 1);

    int largest = 0;
    map<int, int> toInd;
    for (auto& q : queries)
    {
        int u = getInd(q[0], toInd), v = getInd(q[1], toInd);
        ufds(u, v, root, tot);
        largest = max(tot[root[u]], max(tot[root[v]], largest));
        res.push_back(largest);
    }
    return res;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
