#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int TC, cases = 0;
    string s;
    
    cin >> TC;
    while (TC--) {
        cin >> s;
        string ans;
        int open = 0, close = 0;
        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            if (open > d) {
                while (open > d) {
                    ans.push_back(')');
                    open--;    
                }
            }
            else if (open < d) {
                while (open < d) {
                    ans.push_back('(');
                    open++;
                }    
            }
            ans.push_back(s[i]);
        }
        while (open--)
            ans.push_back(')');
    
        cout << "Case #" << ++cases << ": "<< ans << "\n";
    }
    return 0;
