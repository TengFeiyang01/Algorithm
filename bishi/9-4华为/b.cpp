#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, l;
    cin >> n >> m >> k >> l;

    vector<pair<int, int>> g(m);
    unordered_set<int> fs;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == k || b == k) {
            fs.insert(a);
            fs.insert(b);
        }
        g[i] = {a, b};
    }

    unordered_map<int, int> c;
    for (const auto& p : g) {
        int a = p.first, b = p.second;
        if (fs.count(b) && !fs.count(a)) {
            c[a]++;
        }
        if (fs.count(a) && !fs.count(b)) {
            c[b]++;
        }
    }

    vector<pair<int, int>> sl;
    for (const auto& p : c) {
        sl.emplace_back(-p.second, p.first);
    }

    sort(sl.begin(), sl.end());

    vector<int> ans;
    for (int i = 0; i < l; ++i) {
        if (i < sl.size()) {
            ans.push_back(sl[i].second);
        } else {
            ans.push_back(0);
        }
    }

    n = ans.size();
    for (int i = 0; i < n; ++i) {
            std::cout << ans[i] << " \n"[i == n - 1];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
