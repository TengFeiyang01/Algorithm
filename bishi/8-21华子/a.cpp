#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::map<std::vector<int>, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int j = 0; j < n; j += k) {
    	std::vector<int> tmp;
    	for (int i = j; i < std::min(n, j + k); i++) {
    		tmp.push_back(a[i]);
    	}
    	cnt[tmp]++;
    }
    std::vector<int> res;
    for (auto [k, v] : cnt) {
    	for (auto x : k) {
    		res.push_back(x);
    	}
    	res.push_back(v);
    }
    for (int i = 0; i < res.size(); ++i) {
    	std::cout << res[i] << " \n"[i == res.size() - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
