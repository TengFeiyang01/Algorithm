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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::deque<int> id[n + 1];
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	id[a[i]].push_back(i);
    }   
    for (int i = 0; i <= n; ++i) 
        id[i].push_back(n);

    std::vector<int> s{0}, t{0};

    for (int i = 0; i < n; ++i) {
        int v = a[i];
        if (v == t.back() or v != s.back() and id[s.back()].front() < id[t.back()].front()) {
            s.emplace_back(v);
        } else {
            t.emplace_back(v);
        }
        id[v].pop_front();
    }
    int ans = 0;
    for (int i = 1; i < s.size(); ++i) 
        if (s[i] != s[i - 1]) 
            ans += 1;
    for (int j = 1; j < t.size(); ++j) 
        if (t[j] != t[j - 1])
            ans += 1;
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
