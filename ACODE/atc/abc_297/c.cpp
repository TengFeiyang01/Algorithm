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
    int n, m;
    std::cin >> n >> m;
    std::string s;

    for (int i = 0; i < n; ++i) {
    	std::cin >> s;
    	int j = 0;
    	while (j < m) {
    		if (j + 1 < m and s[j] == s[j + 1] and s[j] == 'T') {
    			s[j] = 'P';
    			s[j + 1] = 'C';
    			j += 2;
    			continue;
    		}
    		j += 1;
    	}
    	std::cout << s << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
