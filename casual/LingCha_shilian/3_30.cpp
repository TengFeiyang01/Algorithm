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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> mp;
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	mp[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) 
    	for (int j = 0; j < 31; ++j) {
    		int x = 1 << j;
    		if (mp.count(a[i] + x) and mp.count(a[i] - x)) {
    			auto b = std::vector<int>{i, mp[a[i] + x], mp[a[i] - x]};
    			std::sort(all(b));
    			std::cout << "3" << "\n";
    			for (int i = 0; i < 3; ++i) std::cout << a[b[i]] << " \n"[i == 2];
                return;
    		} else if (ans.size() == 0 and mp.count(a[i] + x)) {
    			ans = std::vector<int>{i, mp[a[i] + x]};
    			std::sort(all(ans));
    		} else if (ans.size() == 0 and mp.count(a[i] - x)) {
    			ans = std::vector<int>{i, mp[a[i] - x]};
    			std::sort(all(ans));
    		}
    	}
    	if (ans.size()) {
    		std::cout << "2" << "\n";
    		std::cout << a[ans[0]] << " " << a[ans[1]] << "\n";
    	} else {
    		std::cout << "1\n" << a[0];
    	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
