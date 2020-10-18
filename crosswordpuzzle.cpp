#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char puzzle[20][20], sym='+';
vector<string> words;
bool found=false;

void fill(int x, int y) {
    if (found) return;
    if (x==10) {
        for (int i=0;i<10;i++) {
            for (int j=0;j<10;j++) printf("%c", puzzle[i][j]);
            printf("\n");
        }
        found=true;
        return;
    }
    if (y==10) {
        fill(x+1, 0);
        return;
    }
    if (puzzle[x][y]==sym) {
        fill(x, y+1);
        return;
    }
    bool needfill=true;
    if (y==0 || (y>0 && puzzle[x][y-1]==sym)) { // start of horizontal puzzle
        needfill=false;
        int ed=y;
        while (ed<10 && puzzle[x][ed]!=sym) ed++;
        int len=ed-y;
        if (len==1 && puzzle[x][y]!='-') {
            fill(x, y+1);
        } else if (len!=1) {
            string row=puzzle[x];
            for (auto word : words) {
                if (word.size()==len) { // try to fill
                    int i;
                    for (i=0;i<len;i++) {
                        if (puzzle[x][y+i]!='-' && puzzle[x][y+i]!=word[i]) break;
                        puzzle[x][y+i]=word[i];
                    }
                    if (i==len) fill(x, y+1);
                    for (int i=0;i<10;i++) puzzle[x][i]=row[i]; // reset
                }
            }
        }
    }
    if (x==0 || (x>0 && puzzle[x-1][y]==sym)) { // start of a vertical puzzle
        needfill=false;
        int ed=x;
        while (ed<10 && puzzle[ed][y]!=sym) ed++;
        int len=ed-x;
        if (len==1) {
            fill(x, y+1);
        } else {
            string col;
            for (int i=0;i<10;i++) col.push_back(puzzle[i][y]);
            for (auto word : words) {
                if (word.size()==len) {
                    int i;
                    for (i=0;i<len;i++) {
                        if (puzzle[x+i][y]!='-' && puzzle[x+i][y]!=word[i]) break;
                        puzzle[x+i][y]=word[i];
                    }
                    if (i==len) fill(x, y+1);
                    for (int i=0;i<10;i++) puzzle[i][y]=col[i];
                }
            }
        }
    }
    if (needfill) fill(x, y+1);
}

int main() {
    for (int i=0;i<10;i++) scanf("%s", puzzle[i]);
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            if (puzzle[i][j]!='-') sym=puzzle[i][j];
        }
    }
    char str[100000];
    scanf("%s", str);
    int len=strlen(str);
    int st=0;
    while (st<len) {
        int ed=st+1;
        while (ed<len && str[ed]!=';') ed++;
        str[ed]='\0';
        words.push_back(str+st);
        st=ed+1;
    }
    fill(0,0);
    return 0;
}