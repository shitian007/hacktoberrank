#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> chmap[10010];
char str[10010];

bool valid(vector<int>& rem, int pos) {
    for (int i=0;i<26;i++) {
        if (rem[i]>chmap[pos][i]) return false;
    }
    return true;
}

int main() {
    scanf("%s", str);
    int len=strlen(str);
    reverse(str, str+len);
    // Tabulate string compositions from current position onwards
    for (int i=0;i<=len;i++) chmap[i].resize(26);
    chmap[len-1][str[len-1]-'a']++;
    for (int i=len-2;i>=0;i--) {
        chmap[i]=chmap[i+1];
        chmap[i][str[i]-'a']++;
    }
    string ans;
    vector<int> rem(26);
    for (int i=0;i<26;i++) rem[i]=chmap[0][i]/2;
    int st=0;
    for (int i=0;i<len/2;i++) {
        int ind=st;
        while (rem[str[ind]-'a']==0) ind++;
        for (int j=ind+1;j<len;j++) {
            if (str[j]<str[ind] && rem[str[j]-'a']) {
                rem[str[j]-'a']--;
                if (valid(rem, j+1))
                    ind=j;
                rem[str[j]-'a']++;
            }
        }
        ans.push_back(str[ind]);
        rem[str[ind]-'a']--;
        st=ind+1;
    }
    printf("%s\n", ans.c_str());

    return 0;
}