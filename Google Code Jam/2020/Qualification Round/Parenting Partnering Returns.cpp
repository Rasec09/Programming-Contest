#include <bits/stdc++.h>
using namespace std;

struct intervalo {
    int ini, fin, idx;
    intervalo(int i, int f, int _idx) : ini(i), fin(f), idx(_idx) {}
    bool operator<(const intervalo &a) {
        return ini < a.ini;
    }
};

int main() {
    
    int TC, n, s[1010], e[1010], cases = 0;
    
    cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> s[i] >> e[i];
        vector<int> color(1441, 0);
        for (int i = 0; i < n; i++) {
            for (int j = s[i]; j < e[i]; j++)
                color[j] += 1;
        }
        int maxNum = *max_element(color.begin(), color.end());
        cout << "Case #" << ++cases << ": ";
        if (maxNum > 2) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            string ans(n, 'a');
            vector<intervalo> rangos;
            for (int i = 0; i < n; i++) {
                rangos.push_back(intervalo(s[i], e[i], i));
            }
            sort(rangos.begin(), rangos.end());
            int i = 0, j = 1;
            while (j < n) {
                ans[rangos[i].idx] = 'J';
                while (rangos[j].ini < rangos[i].fin and j < n)
                    j++;
                i = j;
            }
            for (int i = 0; i < n; i++) {
                if (ans[i] == 'a')
                    ans[i] = 'C';
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
