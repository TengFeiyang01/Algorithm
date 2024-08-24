#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::map<int, std::vector<i64>> pos;
    std::map<int, std::vector<i64>> pre;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	if (!pos.count(a[i])) {
    		pos[a[i]].push_back(0);
    	}
    	pos[a[i]].push_back(i);
    }

	for (auto &[k, v] : pos) {
    	v.push_back(n + 1);
    	int m = v.size();
    	pre[k] = v;
    	auto &p = pre[k];
    	for (int j = 1; j < m; ++j) {
    		i64 d = v[j] - v[j - 1] - 1;
    		p[j] = d * (d + 1) / 2;
    		p[j] += p[j - 1];
    	}
    }
    int q;
    std::cin >> q;
    while (q--) {
    	int l, r, x;
    	std::cin >> l >> r >> x;
    	if (!pos.count(x)) {
    		std::cout << 0 << "\n";
    		continue;
    	}
    	int lo = std::lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin();
    	int hi = std::lower_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin();
    	i64 d = r - l + 1, ans = 0;
    	ans = d * (d + 1) / 2;
    	

    	if (pos[x][hi] != r) {
    		hi--;
    		d = r - pos[x][hi];
    		ans -= d * (d + 1) / 2;
    	}

   		if (pos[x][lo] <= pos[x][hi]) {
   			ans -= pre[x][hi] - pre[x][lo];
   		}

    	if (pos[x][lo] != l) {
    		d = pos[x][lo] - l;
    		ans -= d * (d + 1) / 2;
    	}
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
