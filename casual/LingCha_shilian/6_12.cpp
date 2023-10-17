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
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.size();
    for (int i = 0; i < n and k > 0; ++i) {
    	int id = i;
    	for (int j = i + 1; j < n and j <= i + k; ++j)
    		if (s[j] > s[id]) id = j;
    	while (id > i) {
    		std::swap(s[id], s[id - 1]);
    		k--;
            id--;
    	}
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
