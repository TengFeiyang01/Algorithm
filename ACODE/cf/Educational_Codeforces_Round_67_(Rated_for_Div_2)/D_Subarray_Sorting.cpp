#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 考虑贪心
// 依次枚举b串上的每个数字，然后在a串上依次寻找里b串最近的位置k，然后判断在a串中[1,k]这个区间中，这个数字是不是最小值，如果是ok,否则no,在a中判断成立的数字要去掉

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<std::queue<int>> q(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        q[a[i]].push(i);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        --b[i];
    }

    std::vector<int> seg(n << 2);

    std::function<void(int, int, int)> build = [&](int o, int l, int r) {
        if (l == r) {
            seg[o] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        seg[o] = std::min(seg[o << 1], seg[o << 1 | 1]);
    };

    std::function<void(int, int, int, int)> modify = [&](int o, int l, int r, int pos) {
        if (l == r) {
            seg[o] = inf;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) modify(o << 1, l, mid, pos);
        else modify(o << 1 | 1, mid + 1, r, pos);
        seg[o] = std::min(seg[o << 1], seg[o << 1 | 1]);
    };

    std::function<int(int, int, int, int, int)> query = [&](int o, int l, int r, int s, int t) {
        if (s <= l and r <= t) {
            return seg[o];
        }
        int mid = l + r >> 1, ans = inf;
        if (s <= mid) {
            ans = query(o << 1, l, mid, s, t);
        }
        if (t > mid) {
            ans = std::min(ans, query(o << 1 | 1, mid + 1, r, s, t));
        }
        return ans;
    };

    bool ok = true;
    build(1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        int k;
        if (!q[b[i]].empty()) {
            k = q[b[i]].front();
            q[b[i]].pop();
        } else {
            ok = false;
        }
        int mn = query(1, 0, n - 1, 0, k);
        if (mn != b[i]) {
            ok = false;
        } else {
            modify(1, 0, n - 1, k);
        }
        if (!ok) break;
    }
    if (ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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
