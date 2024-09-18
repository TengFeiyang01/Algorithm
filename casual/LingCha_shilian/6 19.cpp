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
    std::map<int, int> st;
    std::vector<int> a(n);
    int left = 0, ans = 1;
    for (int right = 0; right < n; ++right) {
    	std::cin >> a[right];
    	st[a[right]]++;
    	while ((*st.rbegin()).first - (*st.begin()).first > 1) {
            st[a[left]]--;
            if (st[a[left]] == 0) st.erase(a[left]);
            left++;
    	}
        ans = std::max(ans, right - left + 1);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
