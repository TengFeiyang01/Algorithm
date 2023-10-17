#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    long long st = 0;
    for (int i = 0; i < n - 1; ++i) {
        int x = (s[i] - 'a') * 7 + s[i + 1] - 'a';
        st |= 1LL << x;
    }
    int ans = 0;
    while (st) {
        ans++;
        st &= st - 1LL;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
