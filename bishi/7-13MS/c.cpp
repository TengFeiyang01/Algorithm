#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    int n = S.size();
    int ans = 0;
    vector<int> pre(n), suf(n);
    pre[0] = S[0] == '<' || S[0] == '?';
    for (int i = 1; i < n; i++) {
        if (S[i] == '<' || S[i] == '?') {
            pre[i] = 1; 
        }
        if (S[i - 1] == '<' || S[i - 1] == '?') {
            pre[i] += pre[i - 1];
        }
    
    }
    suf[n - 1] = S[n - 1] == '>' || S[n - 1] == '?';
    for (int i = n - 2; i >= 0; --i) {
        if (S[i] == '>' || S[i] == '?') {
            suf[i] = 1;
        } 
        if (S[i + 1] == '>' || S[i + 1] == '?') {
            suf[i] += suf[i + 1];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, 2 * min(pre[i], suf[i + 1]));
    }

    return ans;
}


void solve() {
    string s;
    std::cin >> s;
    std::cout << solution(s) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}