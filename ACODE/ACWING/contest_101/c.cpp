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
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int left = 0, right = 0;
    std::set<int> st;
    int ans = 0;
    while (right < n) {
        cnt[a[right]] += 1;
        if (!st.count(a[right])) {
            st.insert(a[right]);
        }
        while (*st.rbegin() - *st.begin() > 1) {
            cnt[a[left]] -= 1;
            if (cnt[a[left]] == 0) {
                st.erase(a[left]);
            }
            left += 1;
        }
        ans = std::max(ans, right - left + 1);
        right += 1;
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
