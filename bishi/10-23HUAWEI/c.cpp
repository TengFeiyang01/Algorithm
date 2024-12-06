#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;

void solve() {
    
    vector<int> items, start, end, query;
    int n = items.size(), m = start.size();
    vector<int> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        cnt[start[i]] += 1;
        cnt[end[i] + 1] -= 1;
    }
    int q = query.size();
    vector<int> ans(q);
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<int> p(n), pos(q);
    iota(p.begin(), p.end(), 0);
    iota(pos.begin(), pos.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) {
        return items[x] < items[y];
    });
    sort(pos.begin(), pos.end(), [&](int x, int y){
        return query[x] < query[y];
    });
    int res = 0;
    int i = 0;
    for (int j = 0; j < q; j++) {
        int t = query[pos[j]];
        while (items[p[i]] <= t) {
            res += cnt[p[i]];
            i += 1;
        }
        ans[pos[j]] = res;
    }
    return ans;
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
