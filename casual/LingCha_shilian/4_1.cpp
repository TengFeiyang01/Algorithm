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
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    std::map<PII, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (i >= (n + 1) / 2) {
    		cnt[{a[i], a[n - i - 1]}]++;
    		cnt[{a[n - i - 1], a[i]}]++;
    	}
    }

    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    	if (i >= (n + 1) / 2) {
    		cnt[{b[i], b[n - i - 1]}]--;
    		cnt[{b[n - i - 1], b[i]}]--;
    	}
    }

    if (n % 2 and a[n / 2] != b[n / 2]) {
    	std::cout << "No\n";
    	return;
    }
    for (auto[_, v] : cnt) {
    	if (v) {
    		std::cout << "No\n";
            return;
    	}
    }
    std::cout << "yes\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
