#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    i64 ans = 0;
    std::deque<int> q;
    std::string s;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i] += a[i - 1];
        q.push_back(i - 1);
    }
    std::cin >> s;
    while (q.size()) {
        int l = -1, r = -1;
        while (q.size() and s[q.front()] != 'L') {
            q.pop_front();
        }
        if (q.size()) {
            l = q.front();
            q.pop_front();
        }
        while (q.size() and s[q.back()] != 'R') {
            q.pop_back();
        }
        if (q.size()) {
            r = q.back() + 1;
            q.pop_back();
        }
        if (l != -1 and r != -1) {
            ans += a[r] - a[l];
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
