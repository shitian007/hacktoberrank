#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int swap_count = 0;
    for (int i = 0; i < a.size(); i++) {     
        for (int j = 0; j < a.size() - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                a[j]^=a[j + 1]^=a[j]^=a[j + 1];
                swap_count++;
            }
        }
        
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d\n", swap_count, a.front(), a.back());
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    countSwaps(a);

    return 0;
}
