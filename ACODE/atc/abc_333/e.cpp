#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    bool ok = true;
    std::cin >> n;
    std::vector<std::vector<int>> pos(n + 1);
    std::vector<int> cnt(n + 1), op(n + 1), f(n + 1);

    for (int i = 1, x; i <= n; ++i) {
    	std::cin >> op[i] >> x;
    	if (op[i] == 1) {
    		pos[x].push_back(i);
    	} else {
    		if (pos[x].empty()) {
    			ok = false;
    		} else {
    			cnt[pos[x].back()]++;
    			f[pos[x].back()] = x;
                pos[x].pop_back();
    		}
    	}
    }
    if (!ok) {
    	std::cout << "-1\n";
    	return;
    }
    for (int i = 1; i <= n; ++i) {
    	if (op[i] == 2) {
    		cnt[i]--;
    	}
    	cnt[i] += cnt[i - 1];
    }
    std::cout << std::ranges::max(cnt) << "\n";
    for (int i = 1; i <= n; ++i) {
        if (op[i] == 2) continue;
        std::cout << (f[i] > 0) << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
