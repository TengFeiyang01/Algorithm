#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

struct PersistentSegmentTree {
    struct Info {
        int l, r, cnt;
    };
    std::vector<Info> tr;
    std::vector<int> root;
    int idx = 0;
    PersistentSegmentTree(int n) : tr(n << 5), root(n) {
        std::function<void(int &, int, int)> build = [&](int &u, int l, int r) {
            u = ++ idx;
            if (l == r) return ;
            int mid = l + r >> 1;
            build(tr[u].l, l, mid), build(tr[u].r, mid + 1, r);
        };
        build(root[0], 1, n);
    }
    void modify(int pre, int &now, int l, int r, int c) {
        now = ++ idx;
        tr[now] = tr[pre];
        tr[now].cnt ++;
        if (l == r) return ;
        int mid = l + r >> 1;
        if (c <= mid) {
            modify(tr[pre].l, tr[now].l, l, mid, c);
        } else {
            modify(tr[pre].r, tr[now].r, mid + 1, r, c);
        }
    }
    int ask(int pre, int now, int l, int r, int k) {
        if (l == r) return l;
        int mid = l + r >> 1, sum = tr[tr[now].l].cnt - tr[tr[pre].l].cnt;
        if (k <= sum) {
            return ask(tr[pre].l, tr[now].l, l, mid, k);
        } else {
            return ask(tr[pre].r, tr[now].r, mid + 1, r, k - sum);
        }
    }
};

void solve() {
    int n, q, k, l, r;
    std::cin >> n >> q;
    std::vector<int> a(n + 1), nums;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        nums.emplace_back(a[i]);
    }
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    auto find = [&](int x) {
        return std::lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    };
    PersistentSegmentTree tr(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = find(a[i]);
        tr.modify(tr.root[i - 1], tr.root[i], 1, n, a[i]);
    }
    while (q--) {
        std::cin >> l >> r >> k;
        std::cout << nums[tr.ask(tr.root[l - 1], tr.root[r], 1, n, k) - 1] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
