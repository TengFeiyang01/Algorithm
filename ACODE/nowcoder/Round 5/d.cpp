#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
constexpr i64 mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, ans = 0;
    int m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, i64>> vp1(m1), vp2(m2);
    for (auto &[u, c] : vp1) {
        cin >> u >> c;
    }
    for (auto &[u, c] : vp2) {
        cin >> u >> c;
    }
    int x1 = 0, x2 = 0;
    i64 y1 = 0, y2 = 0;
    int l1 = -1, l2 = -1;
    while (x1 < m1 and x2 < m2) {
        i64 h = min(vp1[x1].second - y1, vp2[x2].second - y2);
        int u1 = vp1[x1].first, u2 = vp2[x2].first;
        ans += l1 != -1 and set({l1, l2, u1, u2}).size() == 2;
        if (u1 != u2) {
            ans += h - 1;
        }
        l1 = u1;
        l2 = u2;
        y1 += h;
        if (y1 == vp1[x1].second) {
            x1 += 1;
            y1 = 0;
        }
        y2 += h;
        if (y2 == vp2[x2].second) {
            x2 += 1;
            y2 = 0;
        }
    }
    cout << ans;
}