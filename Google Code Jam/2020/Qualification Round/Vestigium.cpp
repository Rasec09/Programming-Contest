#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int TC, n, a[110][110];
        
    cin >> TC;
    for (int cases = 0; cases < TC; cases++) {
        cin >> n;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (i == j)
                    k += a[i][j];
            }
        }
        int r = 0;
        for (int i = 0; i < n; i++) {
            set<int> diff;
            for (int j = 0; j < n; j++) {
                diff.insert(a[i][j]);
            }
            if (diff.size() < n) r++;
        }
        int c = 0;
        for (int j = 0; j < n; j++) {
            set<int> diff;
            for (int i = 0; i < n; i++) {
                diff.insert(a[i][j]);
            }
            if (diff.size() < n) c++;
        }
        printf("Case #%d: %d %d %d\n", cases + 1, k, r, c);
    }
    return 0;
}
