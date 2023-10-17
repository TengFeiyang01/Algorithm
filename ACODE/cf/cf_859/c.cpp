#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, ok = 1;
    std::set<char> s1, s2;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (int i = 0; i < n; ++i) {
    	if (i & 1) {
    		s1.insert(s[i]);
    	} else {
    		s2.insert(s[i]);
    	}
    }

    for (auto c1 : s1)
    	for (auto c2 : s2) {
    		if (c1 == c2) {
    			ok = 0;
    			break;
    		}
    	}
    if (ok) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
